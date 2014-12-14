/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ZERO = 258,
    SIZE = 259,
    ID = 260,
    TRUE = 261,
    FALSE = 262,
    CHAINE = 263,
    INCR = 264,
    DECR = 265,
    INT = 266,
    CONST = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    FOR = 271,
    STENCIL = 272,
    PRINTI = 273,
    PRINTF = 274,
    MAIN = 275,
    RETURN = 276,
    EQUAL = 277,
    OR = 278,
    AND = 279,
    NOT = 280,
    DIFF = 281,
    Unary = 284
  };
#endif
/* Tokens.  */
#define ZERO 258
#define SIZE 259
#define ID 260
#define TRUE 261
#define FALSE 262
#define CHAINE 263
#define INCR 264
#define DECR 265
#define INT 266
#define CONST 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define STENCIL 272
#define PRINTI 273
#define PRINTF 274
#define MAIN 275
#define RETURN 276
#define EQUAL 277
#define OR 278
#define AND 279
#define NOT 280
#define DIFF 281
#define Unary 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "proj.y" /* yacc.c:1909  */

	int value;
	char* identificateur;
	
	struct
	{
		struct symbol* result; // -> pour les expressions arithmétiques
		struct quad_list* code;
		struct quad_list* true_list;
		struct quad_list* false_list;
		int next; // label du prochain quad
	}code_gen;
	
	struct symbol* expression;
	char* keyword;
	
	struct
	{
		int* tab;
		int nb_dimension;
		struct quad_list* code ; // dans le cas où on aurait tab[i*3] -> on doit d'abord évaluer i*3
		int indexDefined; // champ servant à savoir si on sait exactement ce qui se trouve entre les crochets
	}tab;
	
	char* chaine;
	char* op_part;
	

#line 137 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
