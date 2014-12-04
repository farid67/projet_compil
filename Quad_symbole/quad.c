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
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new_quad(new->label,new->op,new->arg1,new->arg2,new->res);
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


/*
struct quad* next_quad(struct quad*node)
{
	return node->next;
}
*/

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

	tmp = (*l1)->node;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = l2->node;

}
