#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct symbol 
{
	char* name;
	int isConstant;
	int value;
	int isVar ; // permet de différencier les variables de type i,j.. et autres identificateurs des variables utilisées pour les goto
	struct symbol* next;
};

static int label_tmp=0;

struct symbol* alloc(); // création d'un symbole
//~ void symbol_free(char* nom);

// crée un nouveau temporaire dans la table des symbole 
struct symbol* new_tmp(struct symbol ** table); 

// crée une nouvelle constante True ou False
struct symbol* new_cst(struct symbol ** table, int val);

// ajout d'un symbole dans la table, on ne connait que son nom
struct symbol* symbol_add(struct symbol** table, char* nom);

// recherche le symbole (dont le nom est passé en argument) dans la table des symboles
struct symbol* symbol_lookup (struct symbol* table, char* nom);

void print_s (struct symbol* s);

void print_tds(struct symbol* tds);


#endif
