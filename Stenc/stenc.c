#include "stenc.h"


void traitementTds( struct symbol* tds)
{
	if (tds != NULL)
	{
		printf("\n\t.data\n");
		struct symbol* tmp = tds;
		do
		{
			if (tmp->isConstant==1 || tmp->isVar==1)
			{
				printf("%s:\t.word %d\n",tmp->name,tmp->value);
			}
			
			if (tmp->isConstant == 2) // tampon
			{
				printf("%s:\t.word ",tmp->name);
				int i,nb_elem = tmp->value;
				for (i = 0; i < nb_elem-1;i++)
				{
					tmp=tmp->next;
					printf("%d ,",tmp->value);
				}
				tmp = tmp->next;
				printf("%d ",tmp->value);
				printf("\n");
			}
			
			tmp = tmp->next;
		}while (tmp!= NULL);
		printf("\n");
	}
}


void traitementTab(struct symbol* s,int indexKnown)
{
	printf("\tla $t2 %s\n",s->name);
	if (!indexKnown)
		printf("\tli $t1 %d\n",s->value); // index
	printf("\tmul $t1 $t1 4\n"); 
	printf("\tadd $t4 $t2 $t1\n");
	// $t4 contient l'adresse de l'élément voulu
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
				if (strcmp(tmp->op,"li") == 0 && tmp->res->value != 0)  // appel système 
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
						case 11 :
							printf("$t3 ");
							break;
						case 13 :
							printf("$t5 ");
							break;
					}
					printf("%d\n",tmp->arg1->value);
				}
				
				else if (strcmp(tmp->op,"=") ==0)
				{
					// affectation d'une expression vers un ID
					
					// gestion de l'expression
					
					
					
					if (tmp->arg1->isConstant != 3)// si l'argument est le résultat d'une sous expression, son évaluation a déjà été traité auparavant
					{
						switch (tmp->arg1->isVar)
						{
							case 0: // tmp -> donc un entier quelconque
								printf("\tli $t0 %d\n",tmp->arg1->value);
								break;
							case 1:
								printf("\tmove $t0 %s\n",tmp->arg1->name);
								break;
							case 2:
								// récupération de l'adresse du tableau avec l'étiquette
								traitementTab(tmp->arg1,0);
								printf("\tlw $t0 0($t4)\n");
								break;
							case 3 :
								traitementTab(tmp->arg1,1);
								printf("\tlw $t0 0($t4)\n");
								break;
								
						}
					}
					
					
					
					// gestion du resultat 
					
					switch (tmp->res->isVar)
					{
						// si le res est un ID 
						case 1:
							// stockage de la valeur souhaitée dans la zone mémoire correspondante
							printf("\tsw $t0 %s\n",tmp->res->name);
							break;
						
						// si le res est l'étiquette vers un tableau 
						case 2:
							// l'index du tableau est contenu dans res->value
							traitementTab(tmp->res,0);
							printf("\tsw $t0 0($t4)\n");
							break;
						case 3 :
							// l'index du tableau a été calculé auparavant et il se trouve dans $t1
							traitementTab(tmp->res,1);
							printf("\tsw $t0 0($t4)\n");
							break;
					}
						
				}
				
				
				else if (strcmp(tmp->op,"lw") ==0 ) // l'argument est forcément une variable 
				{
					if (tmp->arg1->isVar== 2 || tmp->arg1->isVar== 3 )
					{
						traitementTab(tmp->arg1,tmp->arg1->isVar - 2); 
					}
					printf("\t%s ",tmp->op);
					switch (tmp->res->value)
					{
						case 2:
							printf("$v0 ");
							break;
						case 4:
							printf("$a0 ");
							break;
						case 9:
							printf("$t1 ");
							break;
						case 8 :
							printf("$t0 ");
							break;
						case 11 :
							printf("$t3 ");
							break;
						case 13 :
							printf("$t5 ");
							break;
					}
					if (tmp->arg1->isVar == 2 || tmp->arg1->isVar== 3)
					{
						printf("0($t4)\n");
					}
					else
						printf("%s\n",tmp->arg1->name);
				}
				
				// opération arithmétique
				else if (strcmp(tmp->op,"add") ==0  || strcmp(tmp->op,"mul") ==0  || (strcmp(tmp->op,"div") ==0 ) || (strcmp(tmp->op,"sub") ==0 ))
				{
// 					printf("%s\n",tmp->op);
					
					if (tmp->arg1->isConstant== 3 || tmp->arg2->isConstant== 3)
					{
						printf("\tmove $t5 $t6\n");
					}
					
					printf("\t%s $t0 $t5 $t3\n",tmp->op);

					
					if (tmp->res->isConstant== 3)
					{
						printf("\tmove $t6 $t0\n");
					}
					
				}
				
				// instruction syscall en mips
				else if (strcmp(tmp->op,"syscall") == 0)
				{
					printf("\t%s\n",tmp->op);
				}
				tmp = tmp->next;
			}while (tmp!= NULL);
			
			// cas où on aurait plusieurs listes chaînée -> voir si on en aura besoin
			tmp_list = tmp_list->next;
		}while (tmp_list!= NULL);
	}
// 	printf("");
}