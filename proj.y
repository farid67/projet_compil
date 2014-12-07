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
		// struct symbol* result;
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
	}tab;
	
}

%token <value> ZERO SIZE
%type <value> NUMERO
%token <identificateur> ID
%type <code_gen> declaration instruction en_tete prg stenc liste_inst
%type <expression> expr expr_tab
%type <tab> TAB init liste
%token <keyword> INT CONST IF ELSE WHILE FOR STENCIL PRINTI MAIN RETURN


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
		
		

instruction:	INT declaration ';'
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
				
				if ($3->isVar)
				{
					op = "lw";
				}
				else
				{
					op = "li";
				}
				
				struct quad* q_li_a0 = new_quad(label_quad,op,$3,NULL,tmp);
				label_quad ++;
				
				
				// on demande l'appel système numéro 1 -> on le stocke dans $v0
				struct symbol* tmp1 = new_tmp(&tds);
				tmp1 -> value = 1;
				
				struct symbol* tmpv0 = new_tmp(&tds);
				tmpv0->value = 2; // 2-> $v0
				
				struct quad* q_li_v0 = new_quad(label_quad,"li",tmp1,NULL,tmpv0);
				
				struct quad* sys = new_quad(label_quad,"syscall",NULL,NULL,NULL);
				label_quad++;
				
				
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
				struct quad* q_returnCode = new_quad(label_quad,"li",$2,NULL,tmp);
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
				
				
				quad_add(&$$.code,q_returnCode);
				quad_add(&$$.code,q_return);
				quad_add(&$$.code,sys);
				
			}
		;


declaration :	ID '=' expr
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
				struct quad* q_assign = new_quad(label_quad,"=",$3,NULL,s);
				label_quad++;
				
				quad_add (&$$.code, q_assign);
			}
		|ID TAB
			{
				$$.code = NULL;
				struct symbol* tab = new_tab($1,$2.tab,$2.nb_dimension);
				tab_add(&tds,tab);
				int i;
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
				tab_complete (&tds,&tab,$5.tab);
				
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
				tab_complete (&tds,&tab,elem);
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

TAB:		'[' expr_tab ']'
			{
				$$.nb_dimension = 0;
				int* d = malloc (sizeof (int));
				d[0] = $2->value;
				$$.nb_dimension ++;
				$$.tab = d;
			}
		|TAB '[' expr_tab ']'
			{
				int*d  =  realloc($1.tab,$1.nb_dimension +1);
				d[$1.nb_dimension] = $3->value;
				$$.nb_dimension = $1.nb_dimension+1;
				$$.tab = d;
				// realloc + une case et écriture
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

expr_tab :	// exemple : int tab[]
			{
				struct symbol* tmp = new_tmp (&tds);
				tmp->value = 0;
				$$ = tmp;
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
				$$ = s;
			}
		|SIZE
			{
				struct symbol* tmp = new_tmp (&tds);
				tmp->value = $1;
				$$ = tmp;
			}
		;
		
expr : 		ID
			{
				// génération d'un symbole qui sera le nom du temporaire avec comme valeur 0 (fait par défaut)
				struct symbol* s = symbol_lookup(tds,$1);
				if (s == NULL)
				{
					s = symbol_add(&tds,$1);	
				}
				s->isConstant = 0;
				$$ = s;
			}
		|NUMERO
			{
				struct symbol* tmp = new_tmp (&tds);
				tmp->value = $1;
				$$ = tmp;
				
			}
		;
		
NUMERO:		SIZE
			{
				$$ = $1;
			}
		|ZERO// parce qu'on ne peut pas avoir tab[0]
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
	}
	
/* 	print_tds(tds); // effectuer un traitement sur cette liste des symboles */
/* 	quad_list_print(q_Globallist); */
	
	fprintf(stderr,"\n\nfin analyse\n");
	fprintf(stderr,"\n---> Début traitement\n\n");
	
	traitementQList(q_Globallist);
	traitementTds(tds);
	
	
	return 0;
}
