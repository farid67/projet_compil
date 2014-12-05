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
	
}

%token <value> NUMERO
%token <identificateur> ID
%type <code_gen> declaration instruction en_tete prg stenc liste_inst
%type <expression> expr
%token <keyword> INT CONST IF ELSE WHILE FOR STENCIL PRINTF PRINTI MAIN RETURN


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
		
		

instruction:	declaration ';'
			{
				$$.code = NULL;
				concat(&$$.code,$1.code);
				
				// à chaque fois qu'on à remonté une liste de quad, on l'ajoute à la liste de quad "globale", et dans le main, on gére cette liste de quad?
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


declaration :	INT ID '=' expr
			{
				$$.code = NULL;
				// génération d'un quad qui sera celui de l'affectation
				
				// génération d'un symbole qui sera le nom du temporaire avec comme valeur 0 (fait par défaut)
				struct symbol* s = symbol_lookup(tds,$2);
				if (s == NULL)
				{
					s = symbol_add(&tds,$2);	
				}
				s->isConstant = 0;
				
				
				// affecter une valeur à une variable entière <=> li en mips
				struct quad* q_assign = new_quad(label_quad,"li",$4,NULL,s);
				label_quad++;
				
				quad_add (&$$.code, q_assign);
			}
		|INT ID
			{
				$$.code = NULL;
				struct symbol* s = symbol_lookup(tds,$2);
				if (s == NULL)
				{
					s = symbol_add(&tds,$2);	
				}
				s->isConstant = 0;
				
				// en mettant le champ arg1 à un null on sait que c'est une déclaration sans initialisation -> pas besoin de faire de quad

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
	
	traitementTds(tds);
	traitementQList(q_Globallist);
	
	return 0;
}
