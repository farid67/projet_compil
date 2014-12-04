%{
	#include <stdio.h>
	#include <string.h>
	#include "quad.h"
	int yylex();
	int yyerror();


	// déclaration des variables globales
	struct symbol* tds = NULL;

	// struct quad_list* q_list = NULL;

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
%type <code_gen> declaration instruction
%type <expression> expr
%token <keyword> INT CONST IF ELSE WHILE FOR STENCIL PRINTF PRINTI MAIN RETURN


%%


instruction:	declaration ';'
			{
				$$.code = NULL;
				concat(&$$.code,$1.code);
				
				
				print_tds(tds);
				quad_list_print($$.code);
				// à chaque fois qu'on à remonté une liste de quad, on l'ajoute à la liste de quad "globale", et dans le main, on gére cette liste de quad?
			}
		;


declaration :	CONST declaration
			{
				$$.code = NULL;
				
				
				$2.code->node->res->isConstant = 1;
				
				quad_add (&$$.code,$2.code->node);
				
			}
		| INT ID '=' expr
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
	printf ("-----------------------------------------------------\n");
	printf("\t\tYacc Compilateur StenC:\n");
	printf ("-----------------------------------------------------\n");
	return yyparse();
}
