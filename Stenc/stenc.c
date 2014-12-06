#include "stenc.h"


void traitementTds( struct symbol* tds)
{
	if (tds != NULL)
	{
		printf("\t.data\n");
		struct symbol* tmp = tds;
		do
		{
			if (tmp->isConstant || tmp->isVar)
			{
				printf("%s:	.word %d\n",tmp->name,tmp->value);
			}
			tmp = tmp->next;
		}while (tmp!= NULL);
		printf("\n");
	}
}


void traitementQList( struct quad_list* q_list)
{
	// pour le moment on traite les différents quad dont l'opérateur est un li et dont le résultat et un symbole avec un numéro différents de 0
	
	printf("\t.text\n");
	printf("\t.globl main\n\n");
	printf("main:\n");
	
	if (q_list != NULL)
	{
		struct quad* tmp;//parcours une liste
		struct quad_list* tmp_list = q_list;//parcours toutes les listes de quad
		do
		{
			tmp = tmp_list -> node;
			do 
			{
				if (strcmp(tmp->op,"li") == 0 && tmp->res->value != 0) 
				{
					printf("\tli ");
					switch (tmp->res->value)
					{
						case 2:
							printf("$v0 ");
							break;
						case 4:
							printf("$a0 ");
							break;
					}
					printf("%d\n",tmp->arg1->value);
				}
				
				else if (strcmp(tmp->op,"=") ==0)
				{
					// affectation d'une expression vers un ID
					
					// d'abord un load int de la valeur souhaitée
					printf("\tli $v0 %d\n",tmp->arg1->value);
					// stockage de la valeur souhaitée dans la zone mémoire correspondante
					printf("\tsw $v0 %s\n",tmp->res->name);
				}
				
				else if (strcmp(tmp->op,"lw") ==0 ) // l'argument est forcément une variable
				{
					printf("\tlw ");
					switch (tmp->res->value)
					{
						case 2:
							printf("$v0 ");
							break;
						case 4:
							printf("$a0 ");
							break;
					}
					printf("%s\n",tmp->arg1->name);
				}
				
				else if (strcmp(tmp->op,"syscall") == 0)
				{
					printf("\t%s\n",tmp->op);
				}
				tmp = tmp->next;
			}while (tmp!= NULL);
			tmp_list = tmp_list->next;
		}while (tmp_list!= NULL);
	}
// 	printf("");
}