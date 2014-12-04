%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	
/* 	FILE* out; */
	int compteur_ligne =1;
%}

space_newLine	[ \t\n]*
nonAlphaNum	["+""\-""/""{""}"","";""=""$""\[""\]""\(""\)""&"">""<""!""|"]


%%



{space_newLine} 	{if (strcmp(yytext,"\n") == 0) {compteur_ligne++;}}
{nonAlphaNum}		{return yytext[0];}
int			{return INT ;}
stencil			{return STENCIL;}
if			{return IF;}
else			{return ELSE;}
while			{return WHILE;}
for			{return FOR;}
const			{return CONST;}
printf			{return PRINTF;}
printi			{return PRINTI;}
main			{return MAIN;}
return			{return RETURN;}
[0-9]+			{
				yylval.value = atoi(yytext);
/* 				printf("entier reconnu\n"); */
				return NUMERO;
			}
[a-zA-Z][a-zA-Z_0-9]*	{
				yylval.identificateur = strdup (yytext);
/* 				printf("identificateur reconnu\n"); */
				return ID;
			}
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