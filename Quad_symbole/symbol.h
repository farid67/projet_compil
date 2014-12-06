#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct symbol 
{
	char* name;
	int isConstant; // 1-> constante (true,false..) 2-> tampon pour tableaux
	int value;
	int isVar ; // permet de différencier les variables de type i,j.. et autres identificateurs des variables utilisées pour les goto
	// si isVar = 2 alors le symbol est un élément de tableau
	struct symbol* next;
};

static int label_tmp=0;

struct symbol* alloc(); // création d'un symbole
//~ void symbol_free(char* nom);

// crée un nouveau temporaire dans la table des symbole 
struct symbol* new_tmp(struct symbol ** table); 

struct symbol* new_tmp_tab_element(); 

// crée une nouvelle constante True ou False
struct symbol* new_cst(struct symbol ** table, int val);

// ajout d'un symbole dans la table, on ne connait que son nom
struct symbol* symbol_add(struct symbol** table, char* nom);

// recherche le symbole (dont le nom est passé en argument) dans la table des symboles
struct symbol* symbol_lookup (struct symbol* table, char* nom);

void print_s (struct symbol* s);

void print_tds(struct symbol* tds);


// ajout d'un tableau en queue de table
void tab_add (struct symbol** tds, struct symbol* tab);


// nom -> nom du tableau ; dimension est un tableau qui contient uniquement le nombre d'éléments max par dimension
// par exemple 		nom=tab , dim={2,3} -> 		tab[2,3]
// création du premier élément tab[0,0] -> puis chainage -> tab[0,1]... tab[0,2]
// pour le nom des éléments, on donnera tab_0_0 pour le premier etc tab_1_2 p


// valeur renvoyée -> pointeur sur le premier élément donc tab_0_0 dans notre cas
struct symbol* new_tab(char* nom, int* dim, int nb_dim);


#endif
