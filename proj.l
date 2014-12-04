%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	FILE* out;
	int compteur_ligne =1;
%}

keyword  	int|stencil|if|else|while|for|const|printf|printi|main|return
space_newLine	[ \t\n]
nonAlphaNum	["+""\-""/""{""}"","";""=""$""\[""\]""\(""\)""&&"">""<""!""||"]


%%



{space_newLine} 	{if (strcmp(yytext,"\n") == 0) {compteur_ligne++;}}
{nonAlphaNum}		{}
{keyword}		{
				printf("mot clé reconnu\n");
			}
[a-zA-Z][a-zA-Z_0-9]*	{
				printf("identificateur reconnu\n");
/* 				return yytext; */
			}
[0-9]*		{
				printf("entier reconnu\n");
/* 				return atoi(yytext); */
			}
.			{
				printf("Caractère non reconnu par Lex %s, ligne %d\n",yytext,compteur_ligne);
			}

%%

int main()
{
/* 	yyin = fopen("/home/farid/Documents/M1/Compilation/Projet/stenc.txt", "r"); */
	
/* 	out = fopen("/home/farid/Documents/M1/Compilation/Projet/sortie.txt", "w+"); */
	
	yylex();
	
/* 	fclose(yyin); */
/* 	fclose(out); */
	
	return 0;
}