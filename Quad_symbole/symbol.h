#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct symbol 
{
	char* name;
	int isConstant; // 1-> constante (true,false..) 2-> tampon pour tableaux 3 -> résultat intérmédiaire pour les expressions 4 -> tampon pour les stenc
	int value;
	int isVar ; // permet de différencier les variables de type i,j.. et autres identificateurs des variables utilisées pour les goto
	// si isVar = 2 alors le symbole est un élément de tableau 
	// si isVar = 3 alors le symbole est un élément de tableau mais l'index n'est pas connu tab[i] par exemple
	// si isVar = 4 le symbol est une étiquette pour une chaine de caractère // ATTENTION pas encore gérer
	// si isVar = 5 le symbol est une étiquette pour les goto dans les structures de contrôle 
	
	int* dimension_size; // existe seulement pour les tampons , et le chaine de caractère
	
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


// Les 3 prototypes de fonction suivants partent du principe qu'un tableau de taille N (peu importe la dimension) est alloué par le biais d'une allocation 
// d'un symbole tampon qui contiendra l'étiquette du tableau ainsi que le nombre d'éléments qu'il contiendra


// ajout d'un tableau en queue de table des symboles
void tab_add (struct symbol** tds, struct symbol* tab);


// complete les éléments d'un tableau de la tds avec ce qui est contenu dans le tableau
void tab_complete (struct symbol** tab,int* tab_int);



// nom -> nom du tableau ; dimension est un tableau qui contient uniquement le nombre d'éléments max par dimension
// par exemple 		nom=tab , dim={2,3} -> 		tab[2,3]
// création du premier élément tab[0,0] -> puis chainage -> tab[0,1]... tab[0,2]


// valeur renvoyée -> pointeur sur le premier élément donc tab_0_0 dans notre cas
struct symbol* new_tab(char* nom, int* dim, int nb_dim);

struct symbol* new_stenc(char* nom, int nb_el, int* el);



#endif
