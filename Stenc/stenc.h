#ifndef _STENC_H_
#define _STENC_H_


#include "quad.h"

// renvoie l'étiquette en fonction du label 
char* labelGoto(struct quad_list* q_list, int label);

void traitementTds(struct symbol* tds);

void traitementQList(struct quad_list* q_list);

void traitementTab(struct symbol* s,int indexKnown);



#endif // _STENC_H_
