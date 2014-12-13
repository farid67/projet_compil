%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	
/* 	FILE* out; */
	int compteur_ligne =1;
%}

space_newLine	[ \t\n]*
nonAlphaNum	["*""+""\-""/""{""}"","";""=""$""\[""\]""\(""\)""&"">""<""!""|""\""]
commentaire	"/*"([^"*"]*["*"]+[^/*])*[^*]*[*]+"/"
ascii		[\!\"\#\$\%\&\'\(\)\*\+\,\-\.\/0-9\:\;\<\=\>\?\@\[\\\]\^_\`\{\|\}\~]*
/* comm_ligne	"//".\n */


%%



{space_newLine} 	{if (strcmp(yytext,"\n") == 0) {compteur_ligne++;}}
{commentaire}		{}
"++"			{return INCR;}
"--"			{return DECR;}
{nonAlphaNum}		{return yytext[0];}
true|TRUE		{return TRUE;}
false|FALSE		{return FALSE;}
int			{return INT ;}
stencil			{return STENCIL;}
if			{return IF;}
else			{return ELSE;}
while			{return WHILE;}
for			{return FOR;}
const			{return CONST;}
printi			{return PRINTI;}
printf			{return PRINTF;}
main			{return MAIN;}
return			{return RETURN;}
[1-9]+[0-9]*		{// éviter qu'on écrive tab[0] pour la déclaration
				yylval.value = atoi(yytext);
				return SIZE;
			}
[0]			{
				yylval.value = 0;
/* 				printf("entier reconnu\n"); */
				return ZERO;
			}
[a-zA-Z][a-zA-Z_0-9]*	{
				yylval.identificateur = strdup (yytext);
/* 				printf("identificateur reconnu\n"); */
				return ID;
			}

<<EOF>>			{ yyterminate();}
.			{
				printf("Caractère non reconnu par Lex %s, ligne %d\n",yytext,compteur_ligne);
			}	


%%

// int main()
// {
/* 	yyin = fopen("/home/farid/Documents/M1/Compilation/Projet/stenc.txt", "r"); */
	
/* 	out = fopen("/home/farid/Documents/M1/Compilation/Projet/sortie.txt", "w+"); */
	
/* 	yylex(); */
/* 	 */
/* 	fclose(yyin); */
/* 	fclose(out); */
	
/* 	return 0; */
// }


// [1-9]+[0-9]*		{// éviter qu'on écrive tab[0] pour la déclaration
// 				yylval.value = atoi(yytext);
// 				return SIZE;
// 			}