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
%token <keyword> EQUAL OR AND NOT DIFF LE GE


%right '='
%left OR
%left AND
%left DIFF EQUAL
%left '>' '<' LE GE
%left '+' '-'
%left '*' '/'
%left Unary INCR DECR NOT
%left '[' ']'



%%

stenc:		en_tete prg
			{
				$$.code = NULL;
				
				concat (&$$.code,$1.code);
				concat (&$$.code,$2.code);
				
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad($2.code),"label",NULL,NULL,new_label);
				label_quad++;
				
				struct quad* q_nop = new_quad(next_quad($2.code)+1,"nop",NULL,NULL,NULL);
				label_quad++;
				
				quad_add(&$$.code,q_label);
				quad_add(&$$.code,q_nop);
				
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
				
				// On commence par créer un label qui sera le label pour le début de la liste d'instruction
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad($3.code),"label",NULL,NULL,new_label);
				label_quad++;
				
				struct quad_list* tmp_list = new_quad_list (q_label);
				concat(&tmp_list,$6.code);
				
				$6.code = tmp_list;
				
				// concaténation du code de la condition et du code de la liste d'instruction 
				concat(&$$.code,$3.code);
				concat (&$$.code,$6.code);
				
				complete(&$3.true_list,$6.code->node->label);
				
				// ajout d'un quad qui se situera après la liste d'instructions
				
				struct symbol* new_label2 = new_tmp(&tds);
				new_label2->isVar = 5; 
				struct quad* q_label2 = new_quad(next_quad($6.code),"label",NULL,NULL,new_label2);
				label_quad++;
				
				complete(&$3.false_list,next_quad($6.code));
				
				
				quad_add (&$$.code,q_label2);
				
				
			}
		| IF '(' expr_bool ')' '{' liste_inst '}' ELSE '{' liste_inst '}' 
			{
				$$.code = $$.true_list = $$.false_list = NULL;
				
				
				
				
				// label début THEN
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad($3.code),"label",NULL,NULL,new_label);
				label_quad++;
				

				struct quad_list* tmp_list = new_quad_list (q_label);
				concat(&tmp_list,$6.code);
				
				$6.code = tmp_list;
				
				
				
				// nouveau quad pour le goto avant le else
				struct symbol* s = new_tmp(&tds);
// 
				struct quad* q_goto= new_quad(next_quad($6.code),"goto",NULL,NULL,s);
				label_quad++;
// 				
/* 				quad_add(&$4.true_list,q_goto); */
				quad_add(&$6.code,q_goto);
				
				
				
				
				// label début ELSE
				
				struct symbol* new_label2 = new_tmp(&tds);
				new_label2->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label2 = new_quad(next_quad($6.code),"label",NULL,NULL,new_label2);
				label_quad++;
				

				struct quad_list* tmp_list2 = new_quad_list (q_label2);
				concat(&tmp_list2,$10.code);
				
				$10.code = tmp_list2;
				
				
				complete(&$3.true_list,next_quad($3.code));
				complete(&$3.false_list,next_quad($6.code));
				
				q_goto->res->value = next_quad($10.code);
				
				
				concat(&$$.code, $3.code);
				concat (&$$.code,$6.code);
				concat(&$$.code,$10.code);
				
				
				
				
				// ajout d'un quad qui se situera après la liste d'instructions
				
				struct symbol* new_label3 = new_tmp(&tds);
				new_label3->isVar = 5; 
				struct quad* q_label3 = new_quad(next_quad($10.code),"label",NULL,NULL,new_label3);
				label_quad++;
				
				quad_add (&$$.code,q_label3);
				
				
				concat(&$$.true_list ,$6.true_list);
				concat(&$$.true_list ,$10.true_list); 
				
				concat(&$$.false_list,$3.false_list);
				
				
				

			}
		| WHILE '(' expr_bool ')' '{' liste_inst '}' 
			{
				$$.code = NULL;
				
				// création label pour le début de la liste d'instructions
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad($3.code),"label",NULL,NULL,new_label);
				label_quad++;
				
				struct quad_list* tmp_list = new_quad_list (q_label);
				concat(&tmp_list,$6.code);
				
				$6.code = tmp_list;
				
				// génération d'un quad pour qu'à la fin de la liste d'instructions on boucle sur la condition pour la tester à nouveau
				
				struct symbol*tmp2 = new_tmp(&tds);
				struct quad* q_loop = new_quad(next_quad($6.code),"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&$6.code,q_loop);
				
				
				complete (&$3.true_list,next_quad($3.code));
				complete(&$3.false_list,next_quad($6.code));
				
				concat(&$$.code,$3.code);
				concat(&$$.code,$6.code);
				
				
				tmp2->value = $3.code->node->label;
				
/* 				quad_add(&$4.true_list,q_loop); */
				
				// ajout d'un quad qui se situera après la liste d'instructions
				
				struct symbol* new_label2 = new_tmp(&tds);
				new_label2->isVar = 5; 
				struct quad* q_label2 = new_quad(next_quad($6.code),"label",NULL,NULL,new_label2);
				label_quad++;
				
				quad_add(&$$.code,q_label2);
			
				
				
/* 				complete (&$4.true_list,$2.code->node->label); */
/* 				complete (&$4.false_list,label_quad); */
	
/* 				complete(&$4.false_list,label_quad); */
				

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
/*	Pour le moment problème avec les chaines de caractères (gestion des " étrange, provoquent des erreurs semblerait-il) */
		| PRINTF '(' CHAINE ')' ';'
			{
				$$.code=NULL;
			}

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
		| STENCIL ID '{' NUMERO','NUMERO '}' '=' '{' init '{' liste '}' '}' 
			{
				$$.code = NULL;
				int taille =  $10.nb_dimension + $12.nb_dimension, i ;
				int* tab =  malloc (taille * sizeof(int));
				for (i = 0 ; i < $10.nb_dimension; i++)
				{
					
					tab[i] = $10.tab[i];
				}
				for (i = 0 ; i < $12.nb_dimension; i++)
				{
					
					tab[i + $10.nb_dimension] = $12.tab[i];
				}
				
				int * tab2 = malloc ((taille+2) * sizeof(int));
				tab2[0] = $4;
				tab2[1] = $6;
				
				for (i= 0 ; i <taille ; i++)
				{
					tab2[i+2] = tab[i];
				}
				
				struct symbol *new_stencil = new_stenc($2,taille+2,tab2);
				
				tab_add (&tds,new_stencil);
				
				
			}
		| STENCIL ID '{' NUMERO ',' NUMERO '}' '=' '{' liste '}' 
			{
				$$.code = NULL;
				int * tab = malloc ( ($10.nb_dimension + 2) * sizeof(int));
				tab[0] = $4;
				tab[1] = $6;
				int i;
				for (i  = 0 ;i < $10.nb_dimension ; i++)
				{
					tab[i+2] = $10.tab[i];
				}
				struct symbol * new_stencil = new_stenc($2,$10.nb_dimension+2,tab );
				
				tab_add(&tds,new_stencil);
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

liste:		'-' NUMERO
			{
				$$.nb_dimension = 1;
				$$.tab = malloc (sizeof (int));
				$$.tab[0] = -$2;
			}
		| NUMERO
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
		|liste ',' '-' NUMERO
			{
				$$.nb_dimension = $1.nb_dimension +1;
				$$.tab = realloc($1.tab,$1.nb_dimension +1);
				$$.tab[$1.nb_dimension] = -$4;
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
				
				
				if ($2.result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ($2.result->isVar == 0)
						quad_a3 =  new_quad(label_quad,"li",$2.result,NULL,n_t3);
					else
						quad_a3 =  new_quad(label_quad,"lw",$2.result,NULL,n_t3);
					label_quad ++;
					quad_add (&$$.code,quad_a3);
				}
				
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
				
				concat (&$$.code,$1.code);
				
				struct symbol* s_1 = alloc();
				s_1->value = 1;
				
				struct symbol* n_t5 = alloc();
				n_t5 -> value = 13;
				
				struct quad* quad_a1 =  new_quad (label_quad,"li",s_1,NULL,n_t5);
				label_quad++;
				
				quad_add(&$$.code,quad_a1);
				
				struct symbol* n_t3 =  alloc();
				n_t3->value = 11;
				
				struct quad* quad_a3 = NULL;
				
					
				if ($1.result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",$1.result,NULL,n_t3);
				else
					quad_a3 =  new_quad(label_quad,"lw",$1.result,NULL,n_t3);
				label_quad ++ ;
				
				quad_add (&$$.code,quad_a3);
				
				
				struct quad* q_incr = new_quad(label_quad,"add", n_t5, n_t3, $1.result);
				label_quad++;
				
				quad_add(&$$.code,q_incr);
				
				struct symbol* res = new_tmp(&tds);
				res->isConstant=0;
				
				
				
				struct quad* q_assign = new_quad(label_quad,"=",$1.result,NULL,res);
				label_quad++;
				
				quad_add(&$$.code,q_assign);
				
				$$.result = res;
				
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
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
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

/* 				$$.result = s_true; */
				
				quad_add (&$$.code,q_label);
				quad_add (&$$.code,q_new);
			}
		|FALSE
			{
				$$.code = $$.true_list = $$.false_list =NULL;
				// génération d'un nouveau symbole pour FALSE -> pour la table des symboles

				struct symbol* s_false = symbol_lookup(tds,"FALSE");
				{
					if (s_false == NULL)
					{
						s_false = new_cst (&tds,0);
					}
				}
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// création d'un quad -> goto vers (on ne sait pas)

					// création d'un symbole tmp qui sera juste un entier qui correspondra au label où aller

				struct symbol* tmp = new_tmp(&tds);

				struct quad* q_new = new_quad(label_quad,"goto",NULL,NULL,tmp);
				label_quad++;

				// completer la true_liste et la false_list des quads 

					// ici on ne peut que remplir que la false_list 

				$1.false_list = new_quad_list(q_new);

				$$.false_list = $1.false_list;

				// le code qui est porté est simplement le quad généré avec le "goto"

/* 				$$.result = s_false; */
				
				quad_add (&$$.code,q_label);
				quad_add (&$$.code,q_new);
			}
		|expr EQUAL expr
			{
				$$.code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ($1.result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ($3.result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",$3.result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",$3.result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"==",$1.result,$3.result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&$$.code,q_label);
				quad_add(&$$.code,quad_a1);
				quad_add(&$$.code,quad_a3);
				quad_add(&$$.code,q_eval);
				quad_add(&$$.code,q_goto);
				$$.true_list = new_quad_list(q_eval);
				$$.false_list = new_quad_list(q_goto);
				
			}
		|expr DIFF expr
			{
				$$.code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ($1.result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ($3.result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",$3.result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",$3.result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"!=",$1.result,$3.result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&$$.code,q_label);
				quad_add(&$$.code,quad_a1);
				quad_add(&$$.code,quad_a3);
				quad_add(&$$.code,q_eval);
				quad_add(&$$.code,q_goto);
				$$.true_list = new_quad_list(q_goto);
				$$.false_list = new_quad_list(q_eval);
				
			}
		| expr '>' expr
			{
				$$.code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ($1.result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ($3.result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",$3.result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",$3.result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,">",$1.result,$3.result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&$$.code,q_label);
				quad_add(&$$.code,quad_a1);
				quad_add(&$$.code,quad_a3);
				quad_add(&$$.code,q_eval);
				quad_add(&$$.code,q_goto);
				$$.true_list = new_quad_list(q_eval);
				$$.false_list = new_quad_list(q_goto);
			}
		| expr '<' expr
			{
				$$.code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ($1.result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ($3.result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",$3.result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",$3.result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"<",$1.result,$3.result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&$$.code,q_label);
				quad_add(&$$.code,quad_a1);
				quad_add(&$$.code,quad_a3);
				quad_add(&$$.code,q_eval);
				quad_add(&$$.code,q_goto);
				$$.true_list = new_quad_list(q_eval);
				$$.false_list = new_quad_list(q_goto);
			}
		| expr '>''=' expr
			{
				$$.code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ($1.result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ($4.result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",$4.result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",$4.result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,">=",$1.result,$4.result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&$$.code,q_label);
				quad_add(&$$.code,quad_a1);
				quad_add(&$$.code,quad_a3);
				quad_add(&$$.code,q_eval);
				quad_add(&$$.code,q_goto);
				$$.true_list = new_quad_list(q_eval);
				$$.false_list = new_quad_list(q_goto);
			}
		| expr '<''=' expr
			{
				$$.code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ($1.result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",$1.result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",$1.result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ($4.result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",$4.result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",$4.result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"<=",$1.result,$4.result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&$$.code,q_label);
				quad_add(&$$.code,quad_a1);
				quad_add(&$$.code,quad_a3);
				quad_add(&$$.code,q_eval);
				quad_add(&$$.code,q_goto);
				$$.true_list = new_quad_list(q_eval);
				$$.false_list = new_quad_list(q_goto);
			}
		|'('expr_bool')'
			{
				$$.code = $$.true_list = $$.false_list =  NULL;
				$$.code = $2.code;
				$$.true_list = $2.true_list;
				$$.false_list = $2.false_list;
			}
		| expr_bool OR expr_bool
			{
				$$.code = $$.true_list = $$.false_list = NULL;
				// on ne peut rien dire sur la condition courante 

				// on peut completer la false_list de la première condition

				complete(&$1.false_list,$3.code->node->label);


				concat(&$$.true_list,$1.true_list);
				concat(&$$.true_list,$3.true_list);



				$$.false_list=$3.false_list;

				concat(&$$.code,$1.code);
				concat(&$$.code,$3.code);
			}
		| expr_bool AND expr_bool
			{
				$$.code = $$.true_list = $$.false_list = NULL;

				// on peut completer la true_list de la première condition

				complete(&$1.true_list,$3.code->node->label);


				concat(&$$.false_list,$1.false_list);
				concat(&$$.false_list,$3.false_list);



				$$.true_list=$3.true_list;

				concat(&$$.code,$1.code);
				concat(&$$.code,$3.code);
			}
		| NOT expr_bool
			{
				$$.code = $$.true_list = $$.false_list = NULL;
				$$.true_list=$2.false_list;
				$$.false_list = $2.true_list;
				$$.code = $2.code;
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
