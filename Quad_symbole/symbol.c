#include "symbol.h"


// création d'une table de symbole vide
struct symbol* alloc()
{
	struct symbol* s= (struct symbol*) malloc (sizeof(struct symbol));
	// s->name="c";
	// s->value=42;
	s->isConstant = 0; // variable temporaire
	s->next = NULL;
	return s;
}


struct symbol* new_tmp (struct symbol** tds)
{
	struct symbol* n = alloc();
	n->name = (char*) malloc (10 * sizeof (char));
	sprintf(n->name,"tmp_%d",label_tmp);
	label_tmp ++;
	// parcourir la table des symbole et ajouter le symbole en queue de liste 
	if (*tds == NULL)
	{
		*tds = n;
		// tds = (struct symbol **) malloc (sizeof(struct symbol*));
	}

	else
	{
		struct symbol* tmp = *tds;

		while (tmp -> next != NULL)
		{
			tmp = tmp -> next;
		}
		tmp -> next = n;
	}


	return n;
}

struct symbol* new_cst (struct symbol** tds, int val)
{
	struct symbol* cst = alloc();
	if (val == 1)
	{
		cst->name = "TRUE";
	}
	else
	{
		cst->name = "FALSE";	
	}
	cst->value = val;
	cst->isConstant = 1;

	if (*tds == NULL)
	{
		*tds = cst;
		// tds = (struct symbol **) malloc (sizeof(struct symbol*));
	}

	else
	{
		struct symbol* tmp = *tds;

		while (tmp -> next != NULL)
		{
			tmp = tmp -> next;
		}
		tmp -> next = cst;
	}

	return cst;
}



struct symbol* symbol_add (struct symbol** tds, char* nom)
{
	if (*tds == NULL)
	{
		// printf("ici\n");
		*tds = alloc();
		(*tds)->name = strdup (nom);
		(*tds)->isConstant = 0;
		return *tds;
	}
	else
	{
		struct symbol* tmp = *tds;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = alloc();
		tmp->next->name = strdup(nom);
		return tmp->next;
	}
}



struct symbol* symbol_lookup (struct symbol * tds, char* nom)
{
	if (tds == NULL)
	{
		return (struct symbol*) NULL;
	}
	else
	{
		struct symbol* tmp = tds;
		do
		{
			if (tmp->name !=NULL && strcmp(tmp->name,nom)== 0)
			{
				return tmp;
			}
			tmp = tmp->next;
		}while (tmp!= NULL);
	}
	return (struct symbol*) NULL;
}


void print_s (struct symbol* s)
{
	if (s != NULL)
	{	
		printf("%s (%d)",s->name, s->value);
	}
	else
	{
		printf(" - ");
	}
}
	

void print_tds(struct symbol* tds)
{
	if (tds == NULL)
	{
		printf ("Aucuns symboles \n");
	}
	else
	{
		printf(" \t\tTable des symboles : \n");
		struct symbol* tmp = tds;
		do
		{
			print_s(tmp);
			printf("\n");
			tmp = tmp->next;
		}while (tmp!= NULL);
	}

}