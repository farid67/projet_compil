/**************************************

		Gestion des quadruplets

 **************************************/

#ifndef QUAD_H
#define QUAD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"

struct quad
{
	int label; // label du quadruplet
	char* op; // opérateur
	struct symbol* arg1; // premier symbol
	struct symbol* arg2; // second symbol
	struct symbol* res; // symbol correspondant au résultat
	struct quad* next;

};


struct quad_list
{
	struct quad* node;
	struct quad_list* next;
	
	// true_list et false_list initialisée à NULL
};// liste de quad




//~ void quad_free(struct quad* q);
void quad_add(struct quad_list** liste, struct quad* q);


// affiche l'état du quad passé en paramètre
void quad_print(struct quad* q);


// création d'un nouveau quad
struct quad* new_quad (int l, char* o, struct symbol* a1, struct symbol* a2, struct symbol* r); 


// crée une nouvelle liste de quad
struct quad_list* new_quad_list (struct quad* n); 



// affiche l'état de la quad_list (utile surtout pour les tests)
void quad_list_print(struct quad_list* ql);


// struct quad* next_quad (struct quad* node); // renvoie un pointeur sur le prochain quad


// la méthode complete parcours la liste de quads et remplace chaque symbole "resultat" des noeuds par le pointeur passé en paramètre
void complete (struct quad_list** liste, int label_goto);


// concaténation de la liste 1 et 2 -> mettre la liste l2 au bout de la liste l1
void concat (struct quad_list** l1, struct quad_list* l2);


#endif // QUAD_H
