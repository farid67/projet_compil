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

struct symbol* new_tmp_tab_element (char* nom, int i)
{
	struct symbol* n = alloc();
	n->name = (char*) malloc ((strlen(nom) + 10) * sizeof (char));
	sprintf(n->name,"%s_%d",nom,i);
	n->isVar=2; // élément de tableau 
	
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
	char* nom_secure = malloc( (strlen(nom)+1) * sizeof (char));
	nom_secure = strdup(nom);
	nom_secure[strlen(nom)] = '_';
	
	if (*tds == NULL)
	{
		// printf("ici\n");
		*tds = alloc();
		(*tds)->name = strdup (nom_secure);
		(*tds)->isConstant = 0;
		(*tds)->isVar=1;
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
		tmp->next->name = strdup(nom_secure);
		tmp->next->isConstant = 0;
		tmp->next->isVar=1;
		return tmp->next;
	}
}



struct symbol* symbol_lookup (struct symbol * tds, char* nom)
{
	char* nom_secure = malloc( (strlen(nom)+1) * sizeof (char));
	nom_secure = strdup(nom);
	nom_secure[strlen(nom)] = '_';
	if (tds == NULL)
	{
		return (struct symbol*) NULL;
	}
	else
	{
		struct symbol* tmp = tds;
		do
		{
			if (tmp->name !=NULL && strcmp(tmp->name,nom_secure)== 0)
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
		if (s->isConstant==1)
			printf("%s (constante -> %d)",s->name, s->value);
		else if (s->isVar ==2)
			printf("%s (element de tableau -> %d)",s->name, s->value);
		else
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


void tab_add (struct symbol** tds, struct symbol* tab)
{
	// parcourir la table des symbole et ajouter le symbole en queue de liste 
	if (*tds == NULL)
	{
		*tds = tab;
		// tds = (struct symbol **) malloc (sizeof(struct symbol*));
	}

	else
	{
		struct symbol* tmp = *tds;

		while (tmp -> next != NULL)
		{
			tmp = tmp -> next;
		}
		tmp -> next = tab;
	}
}

void tab_complete  (struct symbol** tab, int* tab_int)
{
	// on n'initialisera uniquement le nombre d'éléments qui ont initalement étés déclarés dans le tableau
	
	int nb_elem  = (*tab)->value,i;
	
	struct symbol* it = (*tab)->next;
	
	for (i=0; i< nb_elem && it!= NULL ; i++)
	{
		it -> value = tab_int[i];
		it = it -> next;
	}
	
	// vérifier si on a besoin de la table des symboles ou pas 
}


struct symbol* new_tab (char* nom, int* dim, int nb_dim)
{
	
	// ajout d'un symbole "tampon" qui délimitera le début du tableau
	
	struct symbol* tampon = alloc();
	
	char* nom_secure = malloc( (strlen(nom)+1) * sizeof (char));
	nom_secure = strdup(nom);
	nom_secure[strlen(nom)] = '_';
	
	tampon -> name = strdup(nom_secure);
	tampon -> isConstant = 2; // isConst à 2 signifie qu'on a un symbole tampon -> utile juste pour créer l'étiquette sous mips
	
	
// 	struct symbol* init = alloc();
// 	char* nom_init = strdup(nom);
// 	nom_init = realloc (nom_init,sizeof ( (strlen(nom) + 2) *  sizeof(char) ));
	
	
	// génération du nom 
	

// 	nom_init[strlen(nom) ] = '_';
// 	nom_init[strlen(nom) + 1] = '0';
	
	
// 	init->name = nom_init;
	
// 	init -> isVar = 2;// init est un élément de tableau
	
	
	// création de n autres symboles
	
	int nb_symbole = 1,i;
	
	tampon -> dimension_size = malloc (nb_dim * sizeof(int));
	
	
	
	for (i = 0; i < nb_dim; i++)
	{
		tampon -> dimension_size[i] = dim[i];
		nb_symbole *= dim[i];
	}
	
	
	tampon->value = nb_symbole;
	
	struct symbol * it = tampon; // init pointe sur le premier symbole créé
	
	
	for (i = 0 ; i < nb_symbole; i++)
	{
		struct symbol* tmp = new_tmp_tab_element(nom,i);
		it -> next = tmp;
		it = it -> next;
	}
	
	return tampon;
	
	
}