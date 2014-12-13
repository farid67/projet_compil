%{
	#define STDOUT 0
	#include <stdio.h>
	#include <string.h>
	#include "quad.h"
	#include "stenc.h"
	int yylex();
	int yyerror();


	// déclaration des variables globales
	struct symbol* tds = NULL;

	struct quad_list* q_Globallist = NULL;

	int label_quad=1;
	
	
%}

%union
{
	int value;
	char* identificateur;
	
	struct
	{
		struct symbol* result; // -> pour les expressions arithmétiques
		struct quad_list* code;
		struct quad_list* true_list;
		struct quad_list* false_list;
		int next; // label du prochain quad
	}code_gen;
	
	struct symbol* expression;
	char* keyword;
	
	struct
	{
		int* tab;
		int nb_dimension;
		struct quad_list* code ; // dans le cas où on aurait tab[i*3] -> on doit d'abord évaluer i*3
		int indexDefined; // champ servant à savoir si on sait exactement ce qui se trouve entre les crochets
	}tab;
	
	char* chaine;
	char* op_part;
	
}

%token <value> ZERO SIZE
%type <value> NUMERO
%token <identificateur> ID
%type <code_gen> declaration instruction en_tete prg stenc liste_inst
%type <code_gen> expr expr_part expr_bool 
%token <code_gen> TRUE FALSE
%type <tab> TAB init liste
%token <chaine> CHAINE
%token <op_part> INCR DECR
%token <keyword> INT CONST IF ELSE WHILE FOR STENCIL PRINTI PRINTF MAIN RETURN 


%right '='
%left '+' '-'
%left '*' '/'
%left Unary INCR DECR
%left '[' ']'



%%

stenc:		en_tete prg
			{
				$$.code = NULL;
				
				concat (&$$.code,$1.code);
				concat (&$$.code,$2.code);
				
				concat(&q_Globallist,$$.code);
				
/* 				print_tds(tds); */
/* 				quad_list_print($$.code); */
			}
		;


en_tete:	
			{
				$$.code= NULL;
/* 				printf("aucune en-tête\n"); */
			}
		|en_tete CONST INT ID '=' NUMERO ';' // au vu du MIPS, ce n'est pas une instruction de load int, on crée juste une étiquette avec le nom du symbole et sa valeur
			{
/* 				printf("en-tête détectée\n"); */
				$$.code = NULL;
				
				struct symbol* s = symbol_lookup(tds,$4);
				if (s == NULL)
				{
					s = symbol_add(&tds,$4);	
				}
				s->isConstant = 1;
				s->value = $6;
				
			}
		;
		

prg:		INT MAIN '('')' '{' liste_inst '}'
			{
				// début du programme avec la fonction principale
				
					
				$$.code = NULL;
				// création d'un quad pour le main -> voir comment faire pour avoir l'étiquette etc
				concat(&$$.code,$6.code);
				
			}
		;


		
liste_inst : 	
			{
				// cas ou la liste d'instructions est vide
				$$.code = NULL;
			}
		| liste_inst instruction
			{
				$$.code = NULL;
				concat(&$$.code,$1.code);
				concat(&$$.code,$2.code);
			}
		;
		
		

instruction:	

		IF '(' expr_bool ')' '{' liste_inst '}'
			{
				$$.code = NULL;
			}
		|declaration ';' //pour pouvoir écrire int i; puis i =5; par exemple
			{
				$$.code = NULL;
				concat (&$$.code,$1.code);
			}
		| expr_part ';'
			{
				$$.code = NULL;
				concat (&$$.code, $1.code);
			}
		|INT declaration ';'
			{
				$$.code = NULL;
				concat(&$$.code,$2.code);
				
				// à chaque fois qu'on à remonté une liste de quad, on l'ajoute à la liste de quad "globale", et dans le main, on gére cette liste de quad?
			}
		|INT declaration ',' declaration ';'
			{
				$$.code=NULL;
				concat (&$$.code,$2.code);
				concat (&$$.code,$4.code);
			}
/*	Pour le moment problème avec les chaines de caractères (gestion des " étrange, provoquent des erreurs semblerait-il)
		| PRINTF '(' chaineAscii ')' ';'
			{
				$$.code=NULL;
			}
		*/
		| PRINTI '(' expr ')' ';'
			{
				$$.code = NULL;
				
				/********************************************************
				 *
				 * 	Pour afficher une valeur avec mips, on stocke la 
				 * 	valeur que l'on veut afficher dans $a0 et on 
				 * 	demande l'appel système numéro 1
				 * 
				*********************************************************/
				
				
				// d'abord on stocke la valeur que l'on veut afficher dans le registre $a0
				
				struct symbol* tmp = new_tmp(&tds);
				tmp->value = 4;  // Le registre numéro 4 correspond à $a0
				
				// dépend de expr
				char* op;
				
				if ($3.result->isVar)
				{
					op = "lw";
				}
				else
				{
					op = "li";
				}
				
				struct quad* q_li_a0 = new_quad(label_quad,op,$3.result,NULL,tmp);
				label_quad ++;
				
				
				// on demande l'appel système numéro 1 -> on le stocke dans $v0
				struct symbol* tmp1 = new_tmp(&tds);
				tmp1 -> value = 1;
				
				struct symbol* tmpv0 = new_tmp(&tds);
				tmpv0->value = 2; // 2-> $v0
				
				struct quad* q_li_v0 = new_quad(label_quad,"li",tmp1,NULL,tmpv0);
				
				struct quad* sys = new_quad(label_quad,"syscall",NULL,NULL,NULL);
				label_quad++;
				
				// on ajoute éventuellement le code porté par l'expression
				
				concat (&$$.code, $3.code);
				
				// on stocke les quads crées 
				quad_add(&$$.code,q_li_a0);
				quad_add(&$$.code,q_li_v0);
				quad_add(&$$.code,sys);
				
				
			}
		| RETURN expr ';' // amélioration faire un return i par exemple, dans ce cas faire un test de expr (contenu dans return expr) et si l'expression
				// est un entier -> champ is constante à 1, alors on stocke la valeur contenu dans expr->value sinon on fait un move avec la variable
			{
				$$.code = NULL;
				// création d'un quad correspondant au exit dans le mips  
				/********************************************************
				 *
				 * 	Pour un return dans le main, il faut utiliser
				 * 	l'appel système 17 -> exit2 (with return value)
				 * 
				*********************************************************/
				
				// première quad -> affectation du code de retour à $a0 -> le symbole resultat peut contenir comme valeur le numero du registre
				
				struct symbol* tmp = new_tmp(&tds);
				tmp->value = 4;  // Le registre numéro 4 correspond à $a0
				struct quad* q_returnCode = new_quad(label_quad,"li",$2.result,NULL,tmp);
				label_quad++;
				
				// second quad -> affectation de 17 à $v0
				struct symbol* tmp17 = new_tmp(&tds);
				tmp17 -> value = 17;
				struct symbol* tmpv0 = new_tmp(&tds);
				tmpv0 -> value = 2; // $v0 = registre numéro 2
				struct quad* q_return = new_quad(label_quad,"li",tmp17,NULL,tmpv0);
				label_quad++;
				
				// 3ème quad -> syscall;
				
				struct quad* sys = new_quad(label_quad,"syscall",NULL,NULL,NULL);
				label_quad++;
				
				concat (&$$.code,$2.code);
				
				
				quad_add(&$$.code,q_returnCode);
				quad_add(&$$.code,q_return);
				quad_add(&$$.code,sys);
				
			}
		;


declaration :	ID '=' expr // i = 0; i = j; i = tab[0]
			{
				$$.code = NULL;
				// génération d'un quad qui sera celui de l'affectation
				
				// génération d'un symbole qui sera le nom du temporaire avec comme valeur 0 (fait par défaut)
				struct symbol* s = symbol_lookup(tds,$1);
				if (s == NULL)
				{
					s = symbol_add(&tds,$1);	
				}
				s->isConstant = 0;
				
				// affecter une valeur à une variable entière <=> li en mips
				struct quad* q_assign = new_quad(label_quad,"=",$3.result,NULL,s);
				label_quad++;
				
				concat (&$$.code,$3.code);
				quad_add (&$$.code, q_assign);
			}
		|ID TAB '=' expr // tab[2][3] = i; ou bien tab[2] = 0; 
		// implique de faire un sw précédé eventuellement d'un li si l'expression est une variable	
			{
				$$.code = NULL;
				// affectation d'une valeur à un élément du tableau
				
				// on vérifie que le tableau existe bien
				
				struct symbol* id = symbol_lookup(tds,$1);
				if (id == NULL)
				{
					yyerror("Le tableau n'est pas été définis correctement\n");
					return -1;
				}
				
				struct symbol* ptr = alloc(); // pour ne pas modifier les éléments de la table des symboles
				ptr->name = strdup(id->name);
				
				// tab contient un tableau d'entiers : i,j,k où i = l'entier contenu entre les premiers crochets...
				
				
				int i,index= 0;
				for (i = 0;i< $2.nb_dimension-1; i++)
				{
					if (id->dimension_size[i] < $2.tab[i])
					{
						yyerror("overflow in tab\n");
						return -1;
					}
					index += id->dimension_size[i] * $2.tab[i+1] ;
				}
				index += $2.tab[i];
				
				
				// si on arrive ici c'est que l'étiquette a bien été définie auparavant et on a l'index
				if ($2.indexDefined == 1) // index connu tab[5] par exemple
					ptr ->isVar=2; // on stocke une valeur dans le tableau
				else // index inconnu tab[i] par exemple
					ptr->isVar = 3;
				ptr ->value = index;
				
				
				struct quad* q_assign = new_quad(label_quad,"=",$4.result,NULL,ptr);
				label_quad++;
				
				
				// WARNING -> pour l'ordre des quads, il faut d'abord évaluer l'expression (pour utilisation moindre des registres)
				concat (&$$.code,$4.code);
				concat (&$$.code,$2.code);
				quad_add (&$$.code, q_assign);
			}
		|ID TAB // allocation
			{
				$$.code = NULL;
				struct symbol* tab = new_tab($1,$2.tab,$2.nb_dimension);
				tab_add(&tds,tab);
				concat(&$$.code,$2.code);
			}
		|ID TAB '=' '{' liste '}' // cas tableaux unidim
		// nécessite de vérifier que le nombre d'éléments définis dans la liste correspond bien à ce qui est contenu dans tab
		// Faire le même test dans le cas du dessous -> par exemple int tab[3][2]
			{
				// initialisation du tableau avec les informations contenues dans tab -> création d'un étiquette est de n éléments après le .word
				
				$$.code = NULL;
				struct symbol* tab = new_tab($1,$2.tab,$2.nb_dimension);
				tab_add(&tds,tab);
				
				// récupération des données contenues dans la liste entre les accolades 
				tab_complete (&tab,$5.tab);
				concat (&$$.code,$2.code);
			}
		|ID TAB '=' '{' init '{' liste '}' '}' // cas tableaux multidimensionnel -> dimension > 2
			{
				$$.code = NULL;
				struct symbol* tab = new_tab($1,$2.tab,$2.nb_dimension);
				tab_add(&tds,tab);
				
				// concaténation de la dernière liste entre accolades avec les autres listes contenues dans init
				
				int * elem = realloc ($5.tab, $5.nb_dimension + $7.nb_dimension);
				int i;
				for (i=0; i < $7.nb_dimension; i++)
				{
					elem[$5.nb_dimension + i] = $7.tab[i];
				}
				
				
				// on complète les élements contenus dans le tableau avec ce qu'on a récupéré de la liste d'initialisation
				tab_complete (&tab,elem);
				
				concat (&$$.code,$2.code);
			}
		|ID
			{
				$$.code = NULL;
				struct symbol* s = symbol_lookup(tds,$1);
				if (s == NULL)
				{
					s = symbol_add(&tds,$1);	
				}
				s->isConstant = 0;
				
				// en mettant le champ arg1 à un null on sait que c'est une déclaration sans initialisation -> pas besoin de faire de quad

			}
		
		;
/*
chaineAscii :   CHAINE 
			{
				printf("%s",$1);
				$$ = strdup ($1);
			}
		;
*/
		
/*
TAB_DECL:	// on différence 2 cas pour les tableaux car on ne peut pas définir un tableau avec 0 élements par contre on peut vouloir accéder à tab[0]
		'[' expr_tab ']' 
			{
				$$.nb_dimension = 0;
				int* d = malloc (sizeof (int));
				d[0] = $2->value;
				$$.nb_dimension ++;
				$$.tab = d;
			}
		|TAB_DECL '[' expr_tab ']'
			{
				int*d  =  realloc($1.tab,$1.nb_dimension +1);
				d[$1.nb_dimension] = $3->value;
				$$.nb_dimension = $1.nb_dimension+1;
				$$.tab = d;
				// realloc + une case et écriture
			}
		;
*/
		
TAB:		'[' expr ']'
			{
				$$.code = NULL;
				$$.nb_dimension = 0;
				int* d = malloc (sizeof (int));
				// si l'expression est une variable (exemple tab[i]), on commence par stocker i dans $t1
				
				if ($2.result->isVar==0)
				{
					d[0] = $2.result->value;
					$$.indexDefined = 1;
				}
				else // dans ce cas, expr est soit une variable, soit un tab[i]
				{
					// on veut stocker la valeur contenue dans la variable dans $t1
					struct symbol* n_t1 = alloc();
					n_t1->value = 9 ; // 9 -> code pour $t1
					struct quad* q_load = new_quad(label_quad,"lw",$2.result,NULL,n_t1);
					label_quad ++;
					quad_add (&$$.code,q_load);
					$$.indexDefined = 0;
				}
				
				// faire même chose en bas et vérifier que tab[i] et bien accessible (modifier l'ordre des actions dans traitemenTab
				$$.nb_dimension ++;
				$$.tab = d;
				concat (&$$.code,$2.code);
			}
		|TAB '[' expr ']'
			{
				$$.code = NULL;
				// realloc + une case et écriture
				int*d  =  realloc($1.tab,$1.nb_dimension +1);
				
				if ($3.result->isVar==0)
				{
					d[$1.nb_dimension] = $3.result->value;
					$$.indexDefined = $1.indexDefined;
					
				}
				else // nécessite de faire un load word d'abord avant 
				{
					$$.indexDefined = 0;
					// on veut stocker la valeur contenue dans la variable dans $t1
					struct symbol* n_t1 = alloc();
					n_t1->value = 9 ; // 9 -> code pour $t1
					struct quad* q_load = new_quad(label_quad,"lw",$3.result,NULL,n_t1);
					label_quad++;
					quad_add (&$$.code,q_load);
				}
				
				$$.nb_dimension = $1.nb_dimension+1;
				$$.tab = d;
				concat (&$$.code,$1.code);
				concat (&$$.code,$3.code);
				
			}
		;
		
		
init:		'{' liste '}' ','
			{
				$$.tab=NULL;
				$$.tab = $2.tab;
				$$.nb_dimension = $2.nb_dimension;
			}
		| init '{' liste '}' ','
		
			{
				$$.tab=NULL;
				$$.tab = realloc ($1.tab, $1.nb_dimension + $3.nb_dimension);
				int i;
				for (i=0; i < $3.nb_dimension; i++)
				{
					$$.tab[$1.nb_dimension +i ] = $3.tab[i];
				}
				
				$$.nb_dimension = $1.nb_dimension + $3.nb_dimension;
			}
		;

liste:		NUMERO
			{
				$$.nb_dimension = 1;
				$$.tab = malloc (sizeof (int));
				$$.tab[0] = $1;
			}
		|liste ',' NUMERO
			{
				$$.nb_dimension = $1.nb_dimension +1;
				$$.tab = realloc($1.tab,$1.nb_dimension +1);
				$$.tab[$1.nb_dimension] = $3;
			}
		;

// pour le moment on simplifiera en admettant qu'on ne puisse pas définir un tableau vide 
//  Il sera donc impossible d'écrire int tab[] ;
		
/*
expr_tab :	// vide car on peut avoir par exemple : int tab[] ->et ne peut pas être le cas pour les expressions simples (on ne peut pas écrire " i * " )
			{
				struct symbol* tmp = new_tmp (&tds);
				tmp->value = 0;
				$$.result = tmp;
			}
		|ID
			{
				// génération d'un symbole qui sera le nom du temporaire avec comme valeur 0 (fait par défaut)
				struct symbol* s = symbol_lookup(tds,$1);
				if (s == NULL)
				{
					s = symbol_add(&tds,$1);	
				}
				s->isConstant = 0;
				$$.result = s;
			}
		|NUMERO
			{
				struct symbol* tmp = new_tmp (&tds);
				tmp->value = $1;
				$$.result = tmp;
			}
		;
*/

expr : 		ID
			{
				// génération d'un symbole qui sera le nom du temporaire avec comme valeur 0 (fait par défaut)
				struct symbol* s = symbol_lookup(tds,$1);
				if (s == NULL)
				{
					s = symbol_add(&tds,$1);	
				}
				s->isConstant = 0;
				$$.result = s;
			}
		|NUMERO
			{
				struct symbol* tmp = new_tmp (&tds);
				tmp->value = $1;
				$$.result = tmp;
				
			}
		|ID TAB 
			{
				
				// renvoie le symbole correspondant à l'élement du tableau souhaité
				
				// on vérifie que le tableau existe bien
				
				struct symbol* id = symbol_lookup(tds,$1);
				if (id == NULL)
				{
					yyerror("Le tableau n'est pas été définis correctement\n");
/* 					return -1; */
				}
				
				
				struct symbol* ptr = alloc();
				
				// tab contient un tableau d'entiers : i,j,k où i = l'entier contenu entre les premiers crochets...
				
				int i,index=0;
				
				// ATTENTION la taille des dimensions sont stockés dans le sens inverse 
				
				for (i = 0;i< $2.nb_dimension-1; i++)
				{
					if (id->dimension_size[i] < $2.tab[i])
					{
						yyerror("overflow in tab");
						return -1;
					}
/* 					printf("dimension_size %d = %d\n",i,id->dimension_size[i]); */
					index += (id->dimension_size[i+1]) * $2.tab[i] ;
				}
				index += $2.tab[i];
				
				
				// on stocke l'index dans id->value
				
				if ($2.indexDefined == 1)
					ptr -> isVar = 2;// c'est un élément de tableau
				else
					ptr-> isVar = 3;// on ne connait pas l'index à l'avance -> par exemple tab[i] demande d'abord une évaluation de i 
				ptr -> name = strdup (id->name);
				ptr -> value = index;
				
				concat (&$$.code, $2.code);
				
/* 				printf("expression temporaire détéctée -> id : %s\n",$1); */
/* 				quad_list_print($$.code); */
				
				
				$$.result = ptr;
			}
		| '(' expr ')' 
			{
				$$.code = NULL;
				concat (&$$.code, $2.code);
				$$.result = $2.result;
			}
		| expr '+' expr
			{
				$$.code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				
				// ATTENTION -> pour gérer le chainage des quads, et les priorités, on ajoutera les quads en fin de chaine ici (après $3.code)
				
				
				
				// concaténation si les expressions elles-même portent du code
				concat_ope (&$$.code,$1.code, $3.code);
				
				
				if ($1.result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
				
					
					if ($1.result->isVar == 0)
						quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,n_t5);
					else
						quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,n_t5);
					label_quad ++ ;
					
					quad_add (&$$.code,quad_a1);
				}
				
				
				if ($3.result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ($3.result->isVar == 0)
						quad_a3 =  new_quad(label_quad,"li",$3.result,NULL,n_t3);
					else
						quad_a3 =  new_quad(label_quad,"lw",$3.result,NULL,n_t3);
					label_quad ++;
					quad_add (&$$.code,quad_a3);
				}
				
				
				struct quad* quad_a = new_quad(label_quad,"add",$1.result,$3.result,tmp);
				label_quad++;
				
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&$$.code, quad_a);
				
				$$.result = tmp;
			}
		| expr '*' expr
			{
/* 				printf("mult d'abord\n"); */
				$$.code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				if ($1.result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
					
					
/* 					printf("1er quad de $1 -> %d\n",$1.code->node->label); */
					
					if ($1.result->isVar == 0)
						quad_a1 =  new_quad(next_quad($1.code),"li",$1.result,NULL,n_t5);
					else
						quad_a1 =  new_quad(next_quad($1.code),"lw",$1.result,NULL,n_t5);
					label_quad ++ ;
				
					quad_add (&$1.code,quad_a1);
				}
				
				
				if ($3.result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ($3.result->isVar == 0)
						quad_a3 =  new_quad(next_quad($3.code),"li",$3.result,NULL,n_t3);
					else
						quad_a3 =  new_quad(next_quad($3.code),"lw",$3.result,NULL,n_t3);
					label_quad ++;
					quad_add (&$3.code,quad_a3);
				}
				
				
				struct quad* quad_m = new_quad(label_quad,"mul",$1.result,$3.result,tmp);
				label_quad++;
				
				// concaténation si les expressions elles-même portent du code
				concat (&$$.code,$1.code);
				concat (&$$.code,$3.code);
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&$$.code, quad_m);
				$$.result = tmp;
			}
		| expr '/' expr
			{
				$$.code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				if ($1.result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
					
					
/* 					printf("1er quad de $1 -> %d\n",$1.code->node->label); */
					
					if ($1.result->isVar == 0)
						quad_a1 =  new_quad(next_quad($1.code),"li",$1.result,NULL,n_t5);
					else
						quad_a1 =  new_quad(next_quad($1.code),"lw",$1.result,NULL,n_t5);
					label_quad ++ ;
				
					quad_add (&$1.code,quad_a1);
				}
				
				
				if ($3.result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ($3.result->isVar == 0)
						quad_a3 =  new_quad(next_quad($3.code),"li",$3.result,NULL,n_t3);
					else
						quad_a3 =  new_quad(next_quad($3.code),"lw",$3.result,NULL,n_t3);
					label_quad ++;
					quad_add (&$3.code,quad_a3);
				}
				
				
				struct quad* quad_d = new_quad(label_quad,"div",$1.result,$3.result,tmp);
				label_quad++;
				
				// concaténation si les expressions elles-même portent du code
				concat (&$$.code,$1.code);
				concat (&$$.code,$3.code);
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&$$.code, quad_d);
				$$.result = tmp;
			}
		| expr '-' expr
			{
				printf("ici\n");
				$$.code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				// concaténation si les expressions elles-même portent du code
				concat_ope (&$$.code,$1.code, $3.code);
				
				
				if ($1.result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
				
					
					if ($1.result->isVar == 0)
						quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,n_t5);
					else
						quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,n_t5);
					label_quad ++ ;
					
					quad_add (&$$.code,quad_a1);
				}
				
				
				if ($3.result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ($3.result->isVar == 0)
						quad_a3 =  new_quad(label_quad,"li",$3.result,NULL,n_t3);
					else
						quad_a3 =  new_quad(label_quad,"lw",$3.result,NULL,n_t3);
					label_quad ++;
					quad_add (&$$.code,quad_a3);
				}
				
				
				struct quad* quad_s = new_quad(label_quad,"sub",$1.result,$3.result,tmp);
				label_quad++;
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&$$.code, quad_s);
				$$.result = tmp;
			}
		| '-' expr %prec Unary
			{
				$$.code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				struct quad* quad_n = new_quad(label_quad,"neg",$2.result,NULL,tmp);
				label_quad++;
				
				concat (&$$.code,$2.code);
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&$$.code, quad_n);
				$$.result = tmp;
			}
		|expr_part // i++ , i-- ...
			{
				$$.code = NULL;
			}
		;
			
expr_part :
		 expr INCR
			{
				$$.code = NULL;
			}
		| INCR expr
			{
				$$.code = NULL;
			}
		| expr DECR 
			{
				$$.code = NULL;
			}
		| DECR expr 
			{
				$$.code = NULL;
			}
		;
		
expr_bool:	
		TRUE
			{
				// génération d'un nouveau symbole pour TRUE -> pour la table des symboles
				$$.code = NULL;

				struct symbol* s_true = symbol_lookup(tds,"TRUE");
				{
					if (s_true == NULL)
					{
						s_true = new_cst (&tds,1);
					}
				}


				// création d'un quad -> goto vers (on ne sait pas)

					// création d'un symbole tmp qui sera juste un entier qui correspondra au label où aller

				struct symbol* tmp = new_tmp(&tds);

				struct quad* q_new = new_quad(label_quad,"goto",NULL,NULL,tmp);
				label_quad++;

				// completer la true_liste et la false_list des quads 

					// ici on ne peut que remplir que la true_list 

				$1.true_list = new_quad_list(q_new);

				$$.true_list = $1.true_list;

				// le code qui est porté est simplement le quad généré avec le "goto"

				$$.result = s_true;
				
				quad_add (&$$.code,q_new);
			}
		|FALSE
			{
				$$.code = NULL;
			}
		;
		
		
NUMERO:		SIZE
			{
				$$ = $1;
			}
		|ZERO// parce qu'on ne peut pas avoir tab[0] pour une déclaration (autorisé en C mais pourrait mal se passer)
			{
				$$ = $1;
			}
		;


%%


int main()
{
/* 	printf ("-----------------------------------------------------\n"); */
/* 	printf("\t\tYacc Compilateur StenC:\n"); */
/* 	printf ("-----------------------------------------------------\n"); */
	if (yyparse())
	{
		fprintf(stdout,"erreur\n");
		return -1;
	}
	
	
	
/* 	print_tds(tds); // effectuer un traitement sur cette liste des symboles */
/* 	quad_list_print(q_Globallist);	 */
	
	fprintf(stderr,"\n\nfin analyse\n");
	fprintf(stderr,"\n---> Début traitement\n\n");
	
	traitementQList(q_Globallist);
	traitementTds(tds);
	
	
	return 0;
}
