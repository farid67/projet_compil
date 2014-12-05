#include "stenc.h"


void traitementTds( struct symbol* tds)
{
	if (tds == NULL)
	{
		printf ("Aucuns symboles \n");
	}
	else
	{
		struct symbol* tmp = tds;
		do
		{
			if (tmp->isConstant)
			{
				printf("%s:	.word %d\n",tmp->name,tmp->value);
			}
			printf("\n");
			tmp = tmp->next;
		}while (tmp!= NULL);
	}
}