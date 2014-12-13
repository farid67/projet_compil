#include "quad.h"


void quad_add(struct quad_list** liste, struct quad* new)
{
	
	if (*liste == NULL)
	{
		*liste = new_quad_list(new);
	}
	else
	{
		struct quad* tmp;
		tmp = (*liste)->node;
		while (tmp->next != NULL && tmp->label < new->label)
		{
			tmp = tmp->next;
		}
		tmp->next = new_quad(new->label,new->op,new->arg1,new->arg2,new->res);
		
// 		tmp = tmp->next; // tmp pointe sur le quad ajouté
// 		// pour décaler les labels;
// 		do
// 		{
// 			tmp = tmp->next;
// 			tmp->label = tmp->label +1;
// 		}while (tmp!=NULL);
	}
}


void quad_print(struct quad* q)
{
	if (q != NULL)
	{
		printf("%d ",q->label);
		printf(" | ");
		printf("%s",q->op);
		printf(" | ");
		print_s(q->arg1);
		printf(" | ");
		print_s(q->arg2);
		printf(" | ");
		print_s(q->res);
		printf ("\n");
	}
	else
	{
		printf("quad vide\n");
	}
}


void quad_list_print(struct quad_list* ql)
{
	if (ql == NULL)
	{
		printf("liste de quad vide\n");
	}	
	else
	{
		struct quad* tmp;//parcours une liste
		struct quad_list* tmp_list = ql;//parcours toutes les listes de quad
		do
		{
			tmp = tmp_list -> node;
			printf("Nouvelle liste de quad indépendante\n");
			do 
			{
				printf("-------------------------------------\n");
				quad_print(tmp);
				tmp = tmp->next;
			}while (tmp!= NULL);
			printf("-------------------------------------\n");
			tmp_list = tmp_list->next;
		}while (tmp_list!= NULL);
	}
}


struct quad* new_quad(int l, char* o, struct symbol* a1, struct symbol* a2, struct symbol* r)
{
	struct quad* q = (struct quad*) malloc (sizeof(struct quad));
	q->label = l;
	q->op = strdup(o);
	q->arg1 = a1;
	q->arg2 = a2;
	q->res = r;
	q->next = NULL;
}


struct quad_list* new_quad_list(struct quad* n)
{
	struct quad_list* l = (struct quad_list*) malloc (sizeof(struct quad_list));
	l->node = new_quad(n->label,n->op,n->arg1,n->arg2,n->res);
	l->next =NULL;
	return l;
}



int next_quad(struct quad_list* q_list)
{
	if (q_list==NULL)
	{
		return 1;
	}
	struct quad* tmp = q_list->node;
	while (tmp->next !=NULL) 
	{
		tmp = tmp->next;
	}
	
	return tmp->label +1;
	
}


void complete(struct quad_list** liste , int label_goto)
{
	struct quad* tmp;
	if(*liste != NULL)
	{
		tmp = (*liste)->node;
		// parcours de la liste et la complete 

		do
		{
			tmp->res->value = label_goto;
			tmp = tmp->next;
		}while (tmp != NULL);
	}

	
}

void concat_ope (struct quad_list** l1, struct quad_list* op1, struct quad_list* op2)
{
	if (op2==NULL)
	{
		concat (l1,op1);
	}
	if (op1 == NULL)
	{
		concat (l1,op2);
	}
	
	// liste non vide -> recherche priorité 
	
	
	int prio1 = 1;
	
	struct quad* tmp;
	
	tmp = op2->node;
	while (tmp != NULL)
	{
		if (strcmp(tmp->op,"mul") == 0 || strcmp(tmp->op,"div") == 0)
		{
			prio1 = 0; // la liste 1 n'est plus forcément prioritaire
			break;
		}
		tmp = tmp->next;
	}
	
	if (prio1 == 1) //liste 1 prio
	{
		concat (l1, op1);
		concat (l1, op2);
		return ;
	}
	
	tmp = op1-> node;
	
	while (tmp != NULL)
	{
		if (strcmp(tmp->op,"mul") == 0 || strcmp(tmp->op,"div") == 0)
		{
			prio1 = 1; // la liste 1 devient prioritaire
		}
		tmp = tmp->next;
	}
	
	if (prio1 == 1) // l1 prio
	{
		concat (l1, op1);
		concat (l1, op2);
		return ;
	}
	
	else
	{
		concat (l1, op2);
		concat (l1, op1);
		return ;
	}
	
	
}


void concat(struct quad_list** l1, struct quad_list* l2)
{
	struct quad* tmp;
	// test si l1 est une liste vide 

	if (l2 == NULL)
	{
		return ;
	}

	if (*l1 == NULL)
	{
		// création d'une nouvelle liste de quad avec comme argument le premier noeud de l2
		*l1=l2;
		return;
	}
	
	int next_label = next_quad(*l1);
	
	tmp = (*l1)->node;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = l2->node;
	
	// décalage des numéro des quads en fonction de la valeur du dernier quad de l1
	
	
	
	while (tmp->next !=NULL)
	{
		tmp->next->label = next_label;
		next_label ++;
		tmp = tmp ->next;
	}

}
