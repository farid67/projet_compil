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
/* commentaire	"/*"([^"*"]*["*"]+[^/*])*[^*]*[*]+"/" */
ascii		[\!\"\#\$\%\&\'\(\)\*\+\,\-\.\/0-9\:\;\<\=\>\?\@\[\\\]\^_\`\{\|\}\~]*
/* comm_ligne	"//".\n */

%x COMMENT

%%



{space_newLine} 	{if (strcmp(yytext,"\n") == 0) {compteur_ligne++;}}
"++"			{return INCR;}
"--"			{return DECR;}
"=="			{return EQUAL;}
"!="			{return DIFF;}
"||"			{return OR;}
"&&"			{return AND;}
"!"			{return NOT;}
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



\/\*         	{   // début du commentaire, se met dans l'"état" COMMENT
					BEGIN(COMMENT);
				}
<COMMENT>\*\/ 	{   // fin du commentaire, retour à une lecture "normale"
					BEGIN(INITIAL);
				}
<COMMENT>\n    { compteur_ligne++; }   // on incrémente les lignes dans le commentaire (le cas échéant)
<COMMENT>.     {}   // on ignore tout quand on est dans l'état COMMENT



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
