/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "proj.y" /* yacc.c:339  */

	#define STDOUT 0
	#include <stdio.h>
	#include <string.h>
	#include "quad.h"
	#include "stenc.h"
	int yylex();
	int yyerror();


	// déclaration des variables globales
	struct symbol* tds = NULL;

	struct quad_list* q_Globallist = NULL;

	int label_quad=1;
	
	

#line 86 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 22 "proj.y" /* yacc.c:355  */

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
	

#line 209 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    34,    32,    44,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      29,    27,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    30,    31,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,   107,   111,   128,   143,   147,   159,   196,
     278,   333,   338,   343,   350,   362,   419,   462,   482,   488,
     492,   543,   550,   564,   585,   630,   658,   690,   696,   711,
     717,   755,   766,   773,   826,   832,   893,   950,  1006,  1061,
    1077,  1084,  1134,  1139,  1143,  1151,  1196,  1241,  1307,  1373,
    1438,  1503,  1568,  1633,  1640,  1660,  1679,  1689,  1693
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ZERO", "SIZE", "ID", "TRUE", "FALSE",
  "CHAINE", "INCR", "DECR", "INT", "CONST", "IF", "ELSE", "WHILE", "FOR",
  "STENCIL", "PRINTI", "PRINTF", "MAIN", "RETURN", "EQUAL", "OR", "AND",
  "NOT", "DIFF", "'='", "'>'", "'<'", "\"<=\"", "\">=\"", "'+'", "'-'",
  "'*'", "'/'", "Unary", "'['", "']'", "';'", "'('", "')'", "'{'", "'}'",
  "','", "$accept", "stenc", "en_tete", "prg", "liste_inst", "instruction",
  "declaration", "TAB", "init", "liste", "expr", "expr_part", "expr_bool",
  "NUMERO", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    62,    60,
     282,   283,    43,    45,    42,    47,   284,    91,    93,    59,
      40,    41,   123,   125,    44
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -25

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -90,    18,    -7,   -90,     4,    29,   -90,    12,    28,    19,
      27,    25,    71,   -90,   -90,   -90,    30,    82,   -90,    77,
     228,   228,    22,    36,    44,   100,    70,   228,   228,   228,
     -90,   -90,    42,   306,    89,   -90,   228,   228,   177,    84,
     -90,   -90,   -90,   -18,    17,   190,   190,    94,   228,   260,
     -90,   245,   -90,   -90,   -90,   228,   228,   228,   228,   -90,
     306,   272,    26,   228,   103,    46,   -90,    22,   -90,   -90,
     190,   190,   302,   -13,    41,    71,   255,   -90,   -90,    11,
      11,    92,    92,   -90,    13,   306,   288,   105,   -90,   218,
      47,   228,   228,   202,   216,   190,   190,   115,   121,    98,
     126,    71,   127,    64,   -90,   -90,   -90,   -90,   306,   306,
     228,   306,   228,   306,   148,   -90,   -90,   -90,    71,   -90,
      76,    71,   -90,    71,   306,   306,   128,   149,   133,   134,
      80,   -90,   163,   -90,   157,   -90,    83,   144,   156,   -90,
     -90,   -90,    13,   170,   159,   104,   -90,    71,   -90,   107,
     112,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     6,    58,    57,     0,     0,     4,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     7,     0,     0,    40,    32,     0,     0,    33,    31,
      42,    40,    44,    24,     0,     0,     0,     0,     0,     0,
      39,     0,    11,    41,    43,     0,     0,     0,     0,    12,
      17,     0,     0,     0,    33,    21,    13,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,    16,    34,    35,
      38,    36,    37,    25,     0,    20,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    26,    14,    53,    47,    48,
       0,    49,     0,    50,    54,    55,     6,     6,     0,    15,
       0,     0,    22,     0,    51,    52,     0,     0,     0,     0,
       0,    30,     8,    10,     0,    27,     0,     0,     0,    23,
      28,     6,     0,     0,     0,     0,     9,     0,    19,     0,
       0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   -90,   -79,   -90,   -20,    51,    48,   -89,
     -14,    -9,   -45,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,    17,    31,    32,    38,   102,   103,
      72,    41,    73,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    74,    44,    33,     4,     5,    40,    42,    34,    36,
      95,    96,   120,    49,    50,    51,    14,    15,     3,    37,
      53,    54,    60,    61,     7,    88,    90,    43,    97,    14,
      15,    39,   130,    10,    76,    20,    21,   126,   127,    25,
       8,    79,    80,    81,    82,    57,    58,    87,    85,    86,
     114,   115,     9,   145,    12,   101,    66,    89,   149,    28,
      11,    67,   143,    99,    95,    96,    29,    13,    84,    18,
      95,    96,   104,    62,    14,    15,    45,   108,   109,   111,
     113,    52,    98,    63,    46,    14,    15,    19,   107,   104,
      64,    20,    21,    22,    65,    23,   124,    24,   125,    25,
      26,    53,    54,    27,    36,    47,   128,   122,   123,   104,
      48,   131,    33,    33,    37,    28,   -24,    34,    34,   129,
     123,    37,    29,   136,   123,    30,   139,   140,    59,    33,
     104,    14,    15,    19,    34,   104,    75,    20,    21,    22,
      63,    23,   118,    24,   106,    25,    26,   148,   123,    27,
     150,   123,    14,    15,    19,   151,   140,   116,    20,    21,
      22,    28,    23,   117,    24,   119,    25,    26,    29,   121,
      27,   132,    96,    14,    15,    19,   134,   137,   135,    20,
      21,    22,    28,    23,   138,    24,   141,    25,    26,    29,
     144,    27,   133,    14,    15,    39,    68,    69,   142,    20,
      21,   147,     0,    28,    62,    14,    15,    39,     0,     0,
      29,    20,    21,   146,    63,    70,   -21,     0,     0,    14,
      15,    39,     0,    28,     0,    20,    21,    53,    54,   110,
      71,    14,    15,    39,     0,    28,     0,    20,    21,     0,
      91,     0,    29,   112,    92,     0,    93,    94,     0,    28,
      55,    56,    57,    58,    53,    54,    29,     0,     0,    78,
       0,    28,     0,     0,    53,    54,     0,     0,    29,    53,
      54,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    53,    54,     0,     0,     0,    78,    55,    56,    57,
      58,     0,    55,    56,    57,    58,   100,    53,    54,    77,
       0,     0,     0,     0,    55,    56,    57,    58,     0,     0,
      83,    53,    54,     0,     0,    53,    54,     0,     0,     0,
      55,    56,    57,    58,    91,     0,   105,     0,    92,     0,
      93,    94,     0,     0,    55,    56,    57,    58,    55,    56,
      57,    58
};

static const yytype_int16 yycheck[] =
{
      12,    46,    22,    17,    11,    12,    20,    21,    17,    27,
      23,    24,   101,    27,    28,    29,     3,     4,     0,    37,
       9,    10,    36,    37,    20,    70,    71,     5,    41,     3,
       4,     5,   121,     5,    48,     9,    10,   116,   117,    17,
      11,    55,    56,    57,    58,    34,    35,    67,    62,    63,
      95,    96,    40,   142,    27,    42,    39,    71,   147,    33,
      41,    44,   141,    75,    23,    24,    40,    42,    42,    39,
      23,    24,    84,    27,     3,     4,    40,    91,    92,    93,
      94,    39,    41,    37,    40,     3,     4,     5,    41,   101,
      39,     9,    10,    11,    43,    13,   110,    15,   112,    17,
      18,     9,    10,    21,    27,     5,   118,    43,    44,   121,
      40,   123,   126,   127,    37,    33,    39,   126,   127,    43,
      44,    37,    40,    43,    44,    43,    43,    44,    39,   143,
     142,     3,     4,     5,   143,   147,    42,     9,    10,    11,
      37,    13,    44,    15,    39,    17,    18,    43,    44,    21,
      43,    44,     3,     4,     5,    43,    44,    42,     9,    10,
      11,    33,    13,    42,    15,    39,    17,    18,    40,    42,
      21,    43,    24,     3,     4,     5,    43,    14,    44,     9,
      10,    11,    33,    13,    27,    15,    42,    17,    18,    40,
     142,    21,    43,     3,     4,     5,     6,     7,    42,     9,
      10,    42,    -1,    33,    27,     3,     4,     5,    -1,    -1,
      40,     9,    10,    43,    37,    25,    39,    -1,    -1,     3,
       4,     5,    -1,    33,    -1,     9,    10,     9,    10,    27,
      40,     3,     4,     5,    -1,    33,    -1,     9,    10,    -1,
      22,    -1,    40,    27,    26,    -1,    28,    29,    -1,    33,
      32,    33,    34,    35,     9,    10,    40,    -1,    -1,    41,
      -1,    33,    -1,    -1,     9,    10,    -1,    -1,    40,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,     9,    10,    -1,    -1,    -1,    41,    32,    33,    34,
      35,    -1,    32,    33,    34,    35,    41,     9,    10,    39,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      38,     9,    10,    -1,    -1,     9,    10,    -1,    -1,    -1,
      32,    33,    34,    35,    22,    -1,    38,    -1,    26,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    35,    32,    33,
      34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,    11,    12,    48,    20,    11,    40,
       5,    41,    27,    42,     3,     4,    58,    49,    39,     5,
       9,    10,    11,    13,    15,    17,    18,    21,    33,    40,
      43,    50,    51,    55,    56,    58,    27,    37,    52,     5,
      55,    56,    55,     5,    51,    40,    40,     5,    40,    55,
      55,    55,    39,     9,    10,    32,    33,    34,    35,    39,
      55,    55,    27,    37,    52,    52,    39,    44,     6,     7,
      25,    40,    55,    57,    57,    42,    55,    39,    41,    55,
      55,    55,    55,    38,    42,    55,    55,    51,    57,    55,
      57,    22,    26,    28,    29,    23,    24,    41,    41,    58,
      41,    42,    53,    54,    58,    38,    39,    41,    55,    55,
      27,    55,    27,    55,    57,    57,    42,    42,    44,    39,
      54,    42,    43,    44,    55,    55,    49,    49,    58,    43,
      54,    58,    43,    43,    43,    44,    43,    14,    27,    43,
      44,    42,    42,    49,    53,    54,    43,    42,    43,    54,
      43,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     7,     7,     0,     2,     7,    11,
       7,     2,     2,     3,     5,     5,     3,     3,    14,    11,
       4,     2,     6,     9,     1,     3,     4,     4,     5,     1,
       3,     1,     1,     2,     3,     3,     3,     3,     3,     2,
       1,     2,     2,     2,     2,     1,     1,     3,     3,     3,
       3,     4,     4,     3,     3,     3,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				concat (&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				concat (&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
				
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad((yyvsp[0].code_gen).code),"label",NULL,NULL,new_label);
				label_quad++;
				
				struct quad* q_nop = new_quad(next_quad((yyvsp[0].code_gen).code)+1,"nop",NULL,NULL,NULL);
				label_quad++;
				
				quad_add(&(yyval.code_gen).code,q_label);
				quad_add(&(yyval.code_gen).code,q_nop);
				
				concat(&q_Globallist,(yyval.code_gen).code);
				
/* 				print_tds(tds); */
/* 				quad_list_print($$.code); */
			}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 107 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code= NULL;
/* 				printf("aucune en-tête\n"); */
			}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "proj.y" /* yacc.c:1646  */
    {
/* 				printf("en-tête détectée\n"); */
				(yyval.code_gen).code = NULL;
				
				struct symbol* s = symbol_lookup(tds,(yyvsp[-3].identificateur));
				if (s == NULL)
				{
					s = symbol_add(&tds,(yyvsp[-3].identificateur));	
				}
				s->isConstant = 1;
				s->value = (yyvsp[-1].value);
				
			}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 129 "proj.y" /* yacc.c:1646  */
    {
				// début du programme avec la fonction principale
				
					
				(yyval.code_gen).code = NULL;
				// création d'un quad pour le main -> voir comment faire pour avoir l'étiquette etc
				concat(&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				
			}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 143 "proj.y" /* yacc.c:1646  */
    {
				// cas ou la liste d'instructions est vide
				(yyval.code_gen).code = NULL;
			}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				concat(&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				concat(&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
			}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 160 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// On commence par créer un label qui sera le label pour le début de la liste d'instruction
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad((yyvsp[-4].code_gen).code),"label",NULL,NULL,new_label);
				label_quad++;
				
				struct quad_list* tmp_list = new_quad_list (q_label);
				concat(&tmp_list,(yyvsp[-1].code_gen).code);
				
				(yyvsp[-1].code_gen).code = tmp_list;
				
				// concaténation du code de la condition et du code de la liste d'instruction 
				concat(&(yyval.code_gen).code,(yyvsp[-4].code_gen).code);
				concat (&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				
				complete(&(yyvsp[-4].code_gen).true_list,(yyvsp[-1].code_gen).code->node->label);
				
				// ajout d'un quad qui se situera après la liste d'instructions
				
				struct symbol* new_label2 = new_tmp(&tds);
				new_label2->isVar = 5; 
				struct quad* q_label2 = new_quad(next_quad((yyvsp[-1].code_gen).code),"label",NULL,NULL,new_label2);
				label_quad++;
				
				complete(&(yyvsp[-4].code_gen).false_list,next_quad((yyvsp[-1].code_gen).code));
				
				
				quad_add (&(yyval.code_gen).code,q_label2);
				
				
			}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 197 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = (yyval.code_gen).true_list = (yyval.code_gen).false_list = NULL;
				
				
				
				
				// label début THEN
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad((yyvsp[-8].code_gen).code),"label",NULL,NULL,new_label);
				label_quad++;
				

				struct quad_list* tmp_list = new_quad_list (q_label);
				concat(&tmp_list,(yyvsp[-5].code_gen).code);
				
				(yyvsp[-5].code_gen).code = tmp_list;
				
				
				
				// nouveau quad pour le goto avant le else
				struct symbol* s = new_tmp(&tds);
// 
				struct quad* q_goto= new_quad(next_quad((yyvsp[-5].code_gen).code),"goto",NULL,NULL,s);
				label_quad++;
// 				
/* 				quad_add(&$4.true_list,q_goto); */
				quad_add(&(yyvsp[-5].code_gen).code,q_goto);
				
				
				
				
				// label début ELSE
				
				struct symbol* new_label2 = new_tmp(&tds);
				new_label2->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label2 = new_quad(next_quad((yyvsp[-5].code_gen).code),"label",NULL,NULL,new_label2);
				label_quad++;
				

				struct quad_list* tmp_list2 = new_quad_list (q_label2);
				concat(&tmp_list2,(yyvsp[-1].code_gen).code);
				
				(yyvsp[-1].code_gen).code = tmp_list2;
				
				
				complete(&(yyvsp[-8].code_gen).true_list,next_quad((yyvsp[-8].code_gen).code));
				complete(&(yyvsp[-8].code_gen).false_list,next_quad((yyvsp[-5].code_gen).code));
				
				q_goto->res->value = next_quad((yyvsp[-1].code_gen).code);
				
				
				concat(&(yyval.code_gen).code, (yyvsp[-8].code_gen).code);
				concat (&(yyval.code_gen).code,(yyvsp[-5].code_gen).code);
				concat(&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				
				
				
				
				// ajout d'un quad qui se situera après la liste d'instructions
				
				struct symbol* new_label3 = new_tmp(&tds);
				new_label3->isVar = 5; 
				struct quad* q_label3 = new_quad(next_quad((yyvsp[-1].code_gen).code),"label",NULL,NULL,new_label3);
				label_quad++;
				
				quad_add (&(yyval.code_gen).code,q_label3);
				
				
				concat(&(yyval.code_gen).true_list ,(yyvsp[-5].code_gen).true_list);
				concat(&(yyval.code_gen).true_list ,(yyvsp[-1].code_gen).true_list); 
				
				concat(&(yyval.code_gen).false_list,(yyvsp[-8].code_gen).false_list);
				
				
				

			}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 279 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// création label pour le début de la liste d'instructions
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(next_quad((yyvsp[-4].code_gen).code),"label",NULL,NULL,new_label);
				label_quad++;
				
				struct quad_list* tmp_list = new_quad_list (q_label);
				concat(&tmp_list,(yyvsp[-1].code_gen).code);
				
				(yyvsp[-1].code_gen).code = tmp_list;
				
				// génération d'un quad pour qu'à la fin de la liste d'instructions on boucle sur la condition pour la tester à nouveau
				
				struct symbol*tmp2 = new_tmp(&tds);
				struct quad* q_loop = new_quad(next_quad((yyvsp[-1].code_gen).code),"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&(yyvsp[-1].code_gen).code,q_loop);
				
				
				complete (&(yyvsp[-4].code_gen).true_list,next_quad((yyvsp[-4].code_gen).code));
				complete(&(yyvsp[-4].code_gen).false_list,next_quad((yyvsp[-1].code_gen).code));
				
				concat(&(yyval.code_gen).code,(yyvsp[-4].code_gen).code);
				concat(&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				
				
				tmp2->value = (yyvsp[-4].code_gen).code->node->label;
				
/* 				quad_add(&$4.true_list,q_loop); */
				
				// ajout d'un quad qui se situera après la liste d'instructions
				
				struct symbol* new_label2 = new_tmp(&tds);
				new_label2->isVar = 5; 
				struct quad* q_label2 = new_quad(next_quad((yyvsp[-1].code_gen).code),"label",NULL,NULL,new_label2);
				label_quad++;
				
				quad_add(&(yyval.code_gen).code,q_label2);
			
				
				
/* 				complete (&$4.true_list,$2.code->node->label); */
/* 				complete (&$4.false_list,label_quad); */
	
/* 				complete(&$4.false_list,label_quad); */
				

			}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 334 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				concat (&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
			}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 339 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				concat (&(yyval.code_gen).code, (yyvsp[-1].code_gen).code);
			}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 344 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				concat(&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				
				// à chaque fois qu'on à remonté une liste de quad, on l'ajoute à la liste de quad "globale", et dans le main, on gére cette liste de quad?
			}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 351 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code=NULL;
				concat (&(yyval.code_gen).code,(yyvsp[-3].code_gen).code);
				concat (&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
			}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 363 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				/********************************************************
				 *
				 * 	Pour afficher une valeur avec mips, on stocke la 
				 * 	valeur que l'on veut afficher dans $a0 et on 
				 * 	demande l'appel système numéro 1
				 * 
				*********************************************************/
				
				
				// d'abord on stocke la valeur que l'on veut afficher dans le registre $a0
				
				struct symbol* tmp = new_tmp(&tds);
				tmp->value = 4;  // Le registre numéro 4 correspond à $a0
				
				// dépend de expr
				char* op;
				
				if ((yyvsp[-2].code_gen).result->isVar)
				{
					op = "lw";
				}
				else
				{
					op = "li";
				}
				
				struct quad* q_li_a0 = new_quad(label_quad,op,(yyvsp[-2].code_gen).result,NULL,tmp);
				label_quad ++;
				
				
				// on demande l'appel système numéro 1 -> on le stocke dans $v0
				struct symbol* tmp1 = new_tmp(&tds);
				tmp1 -> value = 1;
				
				struct symbol* tmpv0 = new_tmp(&tds);
				tmpv0->value = 2; // 2-> $v0
				
				struct quad* q_li_v0 = new_quad(label_quad,"li",tmp1,NULL,tmpv0);
				
				struct quad* sys = new_quad(label_quad,"syscall",NULL,NULL,NULL);
				label_quad++;
				
				// on ajoute éventuellement le code porté par l'expression
				
				concat (&(yyval.code_gen).code, (yyvsp[-2].code_gen).code);
				
				// on stocke les quads crées 
				quad_add(&(yyval.code_gen).code,q_li_a0);
				quad_add(&(yyval.code_gen).code,q_li_v0);
				quad_add(&(yyval.code_gen).code,sys);
				
				
			}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 421 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				// création d'un quad correspondant au exit dans le mips  
				/********************************************************
				 *
				 * 	Pour un return dans le main, il faut utiliser
				 * 	l'appel système 17 -> exit2 (with return value)
				 * 
				*********************************************************/
				
				// première quad -> affectation du code de retour à $a0 -> le symbole resultat peut contenir comme valeur le numero du registre
				
				struct symbol* tmp = new_tmp(&tds);
				tmp->value = 4;  // Le registre numéro 4 correspond à $a0
				struct quad* q_returnCode = new_quad(label_quad,"li",(yyvsp[-1].code_gen).result,NULL,tmp);
				label_quad++;
				
				// second quad -> affectation de 17 à $v0
				struct symbol* tmp17 = new_tmp(&tds);
				tmp17 -> value = 17;
				struct symbol* tmpv0 = new_tmp(&tds);
				tmpv0 -> value = 2; // $v0 = registre numéro 2
				struct quad* q_return = new_quad(label_quad,"li",tmp17,NULL,tmpv0);
				label_quad++;
				
				// 3ème quad -> syscall;
				
				struct quad* sys = new_quad(label_quad,"syscall",NULL,NULL,NULL);
				label_quad++;
				
				concat (&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				
				
				quad_add(&(yyval.code_gen).code,q_returnCode);
				quad_add(&(yyval.code_gen).code,q_return);
				quad_add(&(yyval.code_gen).code,sys);
				
			}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 463 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				// génération d'un quad qui sera celui de l'affectation
				
				// génération d'un symbole qui sera le nom du temporaire avec comme valeur 0 (fait par défaut)
				struct symbol* s = symbol_lookup(tds,(yyvsp[-2].identificateur));
				if (s == NULL)
				{
					s = symbol_add(&tds,(yyvsp[-2].identificateur));	
				}
				s->isConstant = 0;
				
				// affecter une valeur à une variable entière <=> li en mips
				struct quad* q_assign = new_quad(label_quad,"=",(yyvsp[0].code_gen).result,NULL,s);
				label_quad++;
				
				concat (&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
				quad_add (&(yyval.code_gen).code, q_assign);
			}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 483 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				
			}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 489 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
			}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 494 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				// affectation d'une valeur à un élément du tableau
				
				// on vérifie que le tableau existe bien
				
				struct symbol* id = symbol_lookup(tds,(yyvsp[-3].identificateur));
				if (id == NULL)
				{
					yyerror("Le tableau n'est pas été définis correctement\n");
					return -1;
				}
				
				struct symbol* ptr = alloc(); // pour ne pas modifier les éléments de la table des symboles
				ptr->name = strdup(id->name);
				
				// tab contient un tableau d'entiers : i,j,k où i = l'entier contenu entre les premiers crochets...
				
				
				int i,index= 0;
				for (i = 0;i< (yyvsp[-2].tab).nb_dimension-1; i++)
				{
					if (id->dimension_size[i] < (yyvsp[-2].tab).tab[i])
					{
						yyerror("overflow in tab\n");
						return -1;
					}
					index += id->dimension_size[i] * (yyvsp[-2].tab).tab[i+1] ;
				}
				index += (yyvsp[-2].tab).tab[i];
				
				
				// si on arrive ici c'est que l'étiquette a bien été définie auparavant et on a l'index
				if ((yyvsp[-2].tab).indexDefined == 1) // index connu tab[5] par exemple
					ptr ->isVar=2; // on stocke une valeur dans le tableau
				else // index inconnu tab[i] par exemple
					ptr->isVar = 3;
				ptr ->value = index;
				
				
				struct quad* q_assign = new_quad(label_quad,"=",(yyvsp[0].code_gen).result,NULL,ptr);
				label_quad++;
				
				
				// WARNING -> pour l'ordre des quads, il faut d'abord évaluer l'expression (pour utilisation moindre des registres)
				concat (&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
				concat (&(yyval.code_gen).code,(yyvsp[-2].tab).code);
				quad_add (&(yyval.code_gen).code, q_assign);
			}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 544 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				struct symbol* tab = new_tab((yyvsp[-1].identificateur),(yyvsp[0].tab).tab,(yyvsp[0].tab).nb_dimension);
				tab_add(&tds,tab);
				concat(&(yyval.code_gen).code,(yyvsp[0].tab).code);
			}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 553 "proj.y" /* yacc.c:1646  */
    {
				// initialisation du tableau avec les informations contenues dans tab -> création d'un étiquette est de n éléments après le .word
				
				(yyval.code_gen).code = NULL;
				struct symbol* tab = new_tab((yyvsp[-5].identificateur),(yyvsp[-4].tab).tab,(yyvsp[-4].tab).nb_dimension);
				tab_add(&tds,tab);
				
				// récupération des données contenues dans la liste entre les accolades 
				tab_complete (&tab,(yyvsp[-1].tab).tab);
				concat (&(yyval.code_gen).code,(yyvsp[-4].tab).code);
			}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 565 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				struct symbol* tab = new_tab((yyvsp[-8].identificateur),(yyvsp[-7].tab).tab,(yyvsp[-7].tab).nb_dimension);
				tab_add(&tds,tab);
				
				// concaténation de la dernière liste entre accolades avec les autres listes contenues dans init
				
				int * elem = realloc ((yyvsp[-4].tab).tab, (yyvsp[-4].tab).nb_dimension + (yyvsp[-2].tab).nb_dimension);
				int i;
				for (i=0; i < (yyvsp[-2].tab).nb_dimension; i++)
				{
					elem[(yyvsp[-4].tab).nb_dimension + i] = (yyvsp[-2].tab).tab[i];
				}
				
				
				// on complète les élements contenus dans le tableau avec ce qu'on a récupéré de la liste d'initialisation
				tab_complete (&tab,elem);
				
				concat (&(yyval.code_gen).code,(yyvsp[-7].tab).code);
			}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 586 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				struct symbol* s = symbol_lookup(tds,(yyvsp[0].identificateur));
				if (s == NULL)
				{
					s = symbol_add(&tds,(yyvsp[0].identificateur));	
				}
				s->isConstant = 0;
				
				// en mettant le champ arg1 à un null on sait que c'est une déclaration sans initialisation -> pas besoin de faire de quad

			}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 631 "proj.y" /* yacc.c:1646  */
    {
				(yyval.tab).code = NULL;
				(yyval.tab).nb_dimension = 0;
				int* d = malloc (sizeof (int));
				// si l'expression est une variable (exemple tab[i]), on commence par stocker i dans $t1
				
				if ((yyvsp[-1].code_gen).result->isVar==0)
				{
					d[0] = (yyvsp[-1].code_gen).result->value;
					(yyval.tab).indexDefined = 1;
				}
				else // dans ce cas, expr est soit une variable, soit un tab[i]
				{
					// on veut stocker la valeur contenue dans la variable dans $t1
					struct symbol* n_t1 = alloc();
					n_t1->value = 9 ; // 9 -> code pour $t1
					struct quad* q_load = new_quad(label_quad,"lw",(yyvsp[-1].code_gen).result,NULL,n_t1);
					label_quad ++;
					quad_add (&(yyval.tab).code,q_load);
					(yyval.tab).indexDefined = 0;
				}
				
				// faire même chose en bas et vérifier que tab[i] et bien accessible (modifier l'ordre des actions dans traitemenTab
				(yyval.tab).nb_dimension ++;
				(yyval.tab).tab = d;
				concat (&(yyval.tab).code,(yyvsp[-1].code_gen).code);
			}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 659 "proj.y" /* yacc.c:1646  */
    {
				(yyval.tab).code = NULL;
				// realloc + une case et écriture
				int*d  =  realloc((yyvsp[-3].tab).tab,(yyvsp[-3].tab).nb_dimension +1);
				
				if ((yyvsp[-1].code_gen).result->isVar==0)
				{
					d[(yyvsp[-3].tab).nb_dimension] = (yyvsp[-1].code_gen).result->value;
					(yyval.tab).indexDefined = (yyvsp[-3].tab).indexDefined;
					
				}
				else // nécessite de faire un load word d'abord avant 
				{
					(yyval.tab).indexDefined = 0;
					// on veut stocker la valeur contenue dans la variable dans $t1
					struct symbol* n_t1 = alloc();
					n_t1->value = 9 ; // 9 -> code pour $t1
					struct quad* q_load = new_quad(label_quad,"lw",(yyvsp[-1].code_gen).result,NULL,n_t1);
					label_quad++;
					quad_add (&(yyval.tab).code,q_load);
				}
				
				(yyval.tab).nb_dimension = (yyvsp[-3].tab).nb_dimension+1;
				(yyval.tab).tab = d;
				concat (&(yyval.tab).code,(yyvsp[-3].tab).code);
				concat (&(yyval.tab).code,(yyvsp[-1].code_gen).code);
				
			}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 691 "proj.y" /* yacc.c:1646  */
    {
				(yyval.tab).tab=NULL;
				(yyval.tab).tab = (yyvsp[-2].tab).tab;
				(yyval.tab).nb_dimension = (yyvsp[-2].tab).nb_dimension;
			}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 698 "proj.y" /* yacc.c:1646  */
    {
				(yyval.tab).tab=NULL;
				(yyval.tab).tab = realloc ((yyvsp[-4].tab).tab, (yyvsp[-4].tab).nb_dimension + (yyvsp[-2].tab).nb_dimension);
				int i;
				for (i=0; i < (yyvsp[-2].tab).nb_dimension; i++)
				{
					(yyval.tab).tab[(yyvsp[-4].tab).nb_dimension +i ] = (yyvsp[-2].tab).tab[i];
				}
				
				(yyval.tab).nb_dimension = (yyvsp[-4].tab).nb_dimension + (yyvsp[-2].tab).nb_dimension;
			}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 712 "proj.y" /* yacc.c:1646  */
    {
				(yyval.tab).nb_dimension = 1;
				(yyval.tab).tab = malloc (sizeof (int));
				(yyval.tab).tab[0] = (yyvsp[0].value);
			}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 718 "proj.y" /* yacc.c:1646  */
    {
				(yyval.tab).nb_dimension = (yyvsp[-2].tab).nb_dimension +1;
				(yyval.tab).tab = realloc((yyvsp[-2].tab).tab,(yyvsp[-2].tab).nb_dimension +1);
				(yyval.tab).tab[(yyvsp[-2].tab).nb_dimension] = (yyvsp[0].value);
			}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 756 "proj.y" /* yacc.c:1646  */
    {
				// génération d'un symbole qui sera le nom du temporaire avec comme valeur 0 (fait par défaut)
				struct symbol* s = symbol_lookup(tds,(yyvsp[0].identificateur));
				if (s == NULL)
				{
					s = symbol_add(&tds,(yyvsp[0].identificateur));	
				}
				s->isConstant = 0;
				(yyval.code_gen).result = s;
			}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 767 "proj.y" /* yacc.c:1646  */
    {
				struct symbol* tmp = new_tmp (&tds);
				tmp->value = (yyvsp[0].value);
				(yyval.code_gen).result = tmp;
				
			}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 774 "proj.y" /* yacc.c:1646  */
    {
				
				// renvoie le symbole correspondant à l'élement du tableau souhaité
				
				// on vérifie que le tableau existe bien
				
				struct symbol* id = symbol_lookup(tds,(yyvsp[-1].identificateur));
				if (id == NULL)
				{
					yyerror("Le tableau n'est pas été définis correctement\n");
/* 					return -1; */
				}
				
				
				struct symbol* ptr = alloc();
				
				// tab contient un tableau d'entiers : i,j,k où i = l'entier contenu entre les premiers crochets...
				
				int i,index=0;
				
				// ATTENTION la taille des dimensions sont stockés dans le sens inverse 
				
				for (i = 0;i< (yyvsp[0].tab).nb_dimension-1; i++)
				{
					if (id->dimension_size[i] < (yyvsp[0].tab).tab[i])
					{
						yyerror("overflow in tab");
						return -1;
					}
/* 					printf("dimension_size %d = %d\n",i,id->dimension_size[i]); */
					index += (id->dimension_size[i+1]) * (yyvsp[0].tab).tab[i] ;
				}
				index += (yyvsp[0].tab).tab[i];
				
				
				// on stocke l'index dans id->value
				
				if ((yyvsp[0].tab).indexDefined == 1)
					ptr -> isVar = 2;// c'est un élément de tableau
				else
					ptr-> isVar = 3;// on ne connait pas l'index à l'avance -> par exemple tab[i] demande d'abord une évaluation de i 
				ptr -> name = strdup (id->name);
				ptr -> value = index;
				
				concat (&(yyval.code_gen).code, (yyvsp[0].tab).code);
				
/* 				printf("expression temporaire détéctée -> id : %s\n",$1); */
/* 				quad_list_print($$.code); */
				
				
				(yyval.code_gen).result = ptr;
			}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 827 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				concat (&(yyval.code_gen).code, (yyvsp[-1].code_gen).code);
				(yyval.code_gen).result = (yyvsp[-1].code_gen).result;
			}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 833 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				
				// ATTENTION -> pour gérer le chainage des quads, et les priorités, on ajoutera les quads en fin de chaine ici (après $3.code)
				
				
				
				// concaténation si les expressions elles-même portent du code
				concat_ope (&(yyval.code_gen).code,(yyvsp[-2].code_gen).code, (yyvsp[0].code_gen).code);
				
				
				if ((yyvsp[-2].code_gen).result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
				
					
					if ((yyvsp[-2].code_gen).result->isVar == 0)
						quad_a1 =  new_quad(label_quad,"li",(yyvsp[-2].code_gen).result,NULL,n_t5);
					else
						quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-2].code_gen).result,NULL,n_t5);
					label_quad ++ ;
					
					quad_add (&(yyval.code_gen).code,quad_a1);
				}
				
				
				if ((yyvsp[0].code_gen).result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ((yyvsp[0].code_gen).result->isVar == 0)
						quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,n_t3);
					else
						quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,n_t3);
					label_quad ++;
					quad_add (&(yyval.code_gen).code,quad_a3);
				}
				
				
				struct quad* quad_a = new_quad(label_quad,"add",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad++;
				
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&(yyval.code_gen).code, quad_a);
				
				(yyval.code_gen).result = tmp;
			}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 894 "proj.y" /* yacc.c:1646  */
    {
/* 				printf("mult d'abord\n"); */
				(yyval.code_gen).code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				if ((yyvsp[-2].code_gen).result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
					
					
/* 					printf("1er quad de $1 -> %d\n",$1.code->node->label); */
					
					if ((yyvsp[-2].code_gen).result->isVar == 0)
						quad_a1 =  new_quad(next_quad((yyvsp[-2].code_gen).code),"li",(yyvsp[-2].code_gen).result,NULL,n_t5);
					else
						quad_a1 =  new_quad(next_quad((yyvsp[-2].code_gen).code),"lw",(yyvsp[-2].code_gen).result,NULL,n_t5);
					label_quad ++ ;
				
					quad_add (&(yyvsp[-2].code_gen).code,quad_a1);
				}
				
				
				if ((yyvsp[0].code_gen).result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ((yyvsp[0].code_gen).result->isVar == 0)
						quad_a3 =  new_quad(next_quad((yyvsp[0].code_gen).code),"li",(yyvsp[0].code_gen).result,NULL,n_t3);
					else
						quad_a3 =  new_quad(next_quad((yyvsp[0].code_gen).code),"lw",(yyvsp[0].code_gen).result,NULL,n_t3);
					label_quad ++;
					quad_add (&(yyvsp[0].code_gen).code,quad_a3);
				}
				
				
				struct quad* quad_m = new_quad(label_quad,"mul",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad++;
				
				// concaténation si les expressions elles-même portent du code
				concat (&(yyval.code_gen).code,(yyvsp[-2].code_gen).code);
				concat (&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&(yyval.code_gen).code, quad_m);
				(yyval.code_gen).result = tmp;
			}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 951 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				if ((yyvsp[-2].code_gen).result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
					
					
/* 					printf("1er quad de $1 -> %d\n",$1.code->node->label); */
					
					if ((yyvsp[-2].code_gen).result->isVar == 0)
						quad_a1 =  new_quad(next_quad((yyvsp[-2].code_gen).code),"li",(yyvsp[-2].code_gen).result,NULL,n_t5);
					else
						quad_a1 =  new_quad(next_quad((yyvsp[-2].code_gen).code),"lw",(yyvsp[-2].code_gen).result,NULL,n_t5);
					label_quad ++ ;
				
					quad_add (&(yyvsp[-2].code_gen).code,quad_a1);
				}
				
				
				if ((yyvsp[0].code_gen).result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ((yyvsp[0].code_gen).result->isVar == 0)
						quad_a3 =  new_quad(next_quad((yyvsp[0].code_gen).code),"li",(yyvsp[0].code_gen).result,NULL,n_t3);
					else
						quad_a3 =  new_quad(next_quad((yyvsp[0].code_gen).code),"lw",(yyvsp[0].code_gen).result,NULL,n_t3);
					label_quad ++;
					quad_add (&(yyvsp[0].code_gen).code,quad_a3);
				}
				
				
				struct quad* quad_d = new_quad(label_quad,"div",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad++;
				
				// concaténation si les expressions elles-même portent du code
				concat (&(yyval.code_gen).code,(yyvsp[-2].code_gen).code);
				concat (&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&(yyval.code_gen).code, quad_d);
				(yyval.code_gen).result = tmp;
			}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1007 "proj.y" /* yacc.c:1646  */
    {
				printf("ici\n");
				(yyval.code_gen).code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				
				// concaténation si les expressions elles-même portent du code
				concat_ope (&(yyval.code_gen).code,(yyvsp[-2].code_gen).code, (yyvsp[0].code_gen).code);
				
				
				if ((yyvsp[-2].code_gen).result->isConstant != 3) // si expr1 est déjà le résultat d'une sous expression! dans ce cas le résultat précédent est dans $t6
				{	
					struct symbol * n_t5 = alloc (); // stocker la première opérande
					n_t5 -> value = 13;
					
					struct quad* quad_a1 = NULL;
				
					
					if ((yyvsp[-2].code_gen).result->isVar == 0)
						quad_a1 =  new_quad(label_quad,"li",(yyvsp[-2].code_gen).result,NULL,n_t5);
					else
						quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-2].code_gen).result,NULL,n_t5);
					label_quad ++ ;
					
					quad_add (&(yyval.code_gen).code,quad_a1);
				}
				
				
				if ((yyvsp[0].code_gen).result->isConstant != 3)
				{	
					struct symbol * n_t3 = alloc (); // stocker la seconde opérande
					n_t3 -> value = 11;
					
					struct quad* quad_a3 = NULL;
					
					
					if ((yyvsp[0].code_gen).result->isVar == 0)
						quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,n_t3);
					else
						quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,n_t3);
					label_quad ++;
					quad_add (&(yyval.code_gen).code,quad_a3);
				}
				
				
				struct quad* quad_s = new_quad(label_quad,"sub",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad++;
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&(yyval.code_gen).code, quad_s);
				(yyval.code_gen).result = tmp;
			}
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1062 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				// création d'un symbole temporaire qui contiendra le résulat de l'addition
				struct symbol* tmp = new_tmp(&tds);
				tmp->isConstant = 3; // résulat temporaire d'une sous-expression
				
				struct quad* quad_n = new_quad(label_quad,"neg",(yyvsp[0].code_gen).result,NULL,tmp);
				label_quad++;
				
				concat (&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
				
				// on ajoute le quad correspondant à l'addition
				quad_add (&(yyval.code_gen).code, quad_n);
				(yyval.code_gen).result = tmp;
			}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1078 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
			}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1085 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				concat (&(yyval.code_gen).code,(yyvsp[-1].code_gen).code);
				
				struct symbol* s_1 = alloc();
				s_1->value = 1;
				
				struct symbol* n_t5 = alloc();
				n_t5 -> value = 13;
				
				struct quad* quad_a1 =  new_quad (label_quad,"li",s_1,NULL,n_t5);
				label_quad++;
				
				quad_add(&(yyval.code_gen).code,quad_a1);
				
				struct symbol* n_t3 =  alloc();
				n_t3->value = 11;
				
				struct quad* quad_a3 = NULL;
				
					
				if ((yyvsp[-1].code_gen).result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",(yyvsp[-1].code_gen).result,NULL,n_t3);
				else
					quad_a3 =  new_quad(label_quad,"lw",(yyvsp[-1].code_gen).result,NULL,n_t3);
				label_quad ++ ;
				
				quad_add (&(yyval.code_gen).code,quad_a3);
				
				
				struct quad* q_incr = new_quad(label_quad,"add", n_t5, n_t3, (yyvsp[-1].code_gen).result);
				label_quad++;
				
				quad_add(&(yyval.code_gen).code,q_incr);
				
				struct symbol* res = new_tmp(&tds);
				res->isConstant=0;
				
				
				
				struct quad* q_assign = new_quad(label_quad,"=",(yyvsp[-1].code_gen).result,NULL,res);
				label_quad++;
				
				quad_add(&(yyval.code_gen).code,q_assign);
				
				(yyval.code_gen).result = res;
				
			}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1135 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
			}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1140 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
			}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1144 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
			}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1152 "proj.y" /* yacc.c:1646  */
    {
				// génération d'un nouveau symbole pour TRUE -> pour la table des symboles
				(yyval.code_gen).code = NULL;

				struct symbol* s_true = symbol_lookup(tds,"TRUE");
				{
					if (s_true == NULL)
					{
						s_true = new_cst (&tds,1);
					}
				}
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// création d'un quad -> goto vers (on ne sait pas)

					// création d'un symbole tmp qui sera juste un entier qui correspondra au label où aller

				struct symbol* tmp = new_tmp(&tds);

				struct quad* q_new = new_quad(label_quad,"goto",NULL,NULL,tmp);
				label_quad++;

				// completer la true_liste et la false_list des quads 

					// ici on ne peut que remplir que la true_list 

				(yyvsp[0].code_gen).true_list = new_quad_list(q_new);

				(yyval.code_gen).true_list = (yyvsp[0].code_gen).true_list;

				// le code qui est porté est simplement le quad généré avec le "goto"

/* 				$$.result = s_true; */
				
				quad_add (&(yyval.code_gen).code,q_label);
				quad_add (&(yyval.code_gen).code,q_new);
			}
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1197 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = (yyval.code_gen).true_list = (yyval.code_gen).false_list =NULL;
				// génération d'un nouveau symbole pour FALSE -> pour la table des symboles

				struct symbol* s_false = symbol_lookup(tds,"FALSE");
				{
					if (s_false == NULL)
					{
						s_false = new_cst (&tds,0);
					}
				}
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// création d'un quad -> goto vers (on ne sait pas)

					// création d'un symbole tmp qui sera juste un entier qui correspondra au label où aller

				struct symbol* tmp = new_tmp(&tds);

				struct quad* q_new = new_quad(label_quad,"goto",NULL,NULL,tmp);
				label_quad++;

				// completer la true_liste et la false_list des quads 

					// ici on ne peut que remplir que la false_list 

				(yyvsp[0].code_gen).false_list = new_quad_list(q_new);

				(yyval.code_gen).false_list = (yyvsp[0].code_gen).false_list;

				// le code qui est porté est simplement le quad généré avec le "goto"

/* 				$$.result = s_false; */
				
				quad_add (&(yyval.code_gen).code,q_label);
				quad_add (&(yyval.code_gen).code,q_new);
			}
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1242 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ((yyvsp[-2].code_gen).result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",(yyvsp[-2].code_gen).result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-2].code_gen).result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ((yyvsp[0].code_gen).result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"==",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&(yyval.code_gen).code,q_label);
				quad_add(&(yyval.code_gen).code,quad_a1);
				quad_add(&(yyval.code_gen).code,quad_a3);
				quad_add(&(yyval.code_gen).code,q_eval);
				quad_add(&(yyval.code_gen).code,q_goto);
				(yyval.code_gen).true_list = new_quad_list(q_eval);
				(yyval.code_gen).false_list = new_quad_list(q_goto);
				
			}
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1308 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ((yyvsp[-2].code_gen).result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",(yyvsp[-2].code_gen).result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-2].code_gen).result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ((yyvsp[0].code_gen).result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"!=",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&(yyval.code_gen).code,q_label);
				quad_add(&(yyval.code_gen).code,quad_a1);
				quad_add(&(yyval.code_gen).code,quad_a3);
				quad_add(&(yyval.code_gen).code,q_eval);
				quad_add(&(yyval.code_gen).code,q_goto);
				(yyval.code_gen).true_list = new_quad_list(q_goto);
				(yyval.code_gen).false_list = new_quad_list(q_eval);
				
			}
#line 2803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1374 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ((yyvsp[-2].code_gen).result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",(yyvsp[-2].code_gen).result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-2].code_gen).result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ((yyvsp[0].code_gen).result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,">",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&(yyval.code_gen).code,q_label);
				quad_add(&(yyval.code_gen).code,quad_a1);
				quad_add(&(yyval.code_gen).code,quad_a3);
				quad_add(&(yyval.code_gen).code,q_eval);
				quad_add(&(yyval.code_gen).code,q_goto);
				(yyval.code_gen).true_list = new_quad_list(q_eval);
				(yyval.code_gen).false_list = new_quad_list(q_goto);
			}
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1439 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ((yyvsp[-2].code_gen).result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",(yyvsp[-2].code_gen).result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-2].code_gen).result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ((yyvsp[0].code_gen).result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"<",(yyvsp[-2].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&(yyval.code_gen).code,q_label);
				quad_add(&(yyval.code_gen).code,quad_a1);
				quad_add(&(yyval.code_gen).code,quad_a3);
				quad_add(&(yyval.code_gen).code,q_eval);
				quad_add(&(yyval.code_gen).code,q_goto);
				(yyval.code_gen).true_list = new_quad_list(q_eval);
				(yyval.code_gen).false_list = new_quad_list(q_goto);
			}
#line 2941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1504 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ((yyvsp[-3].code_gen).result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",(yyvsp[-3].code_gen).result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-3].code_gen).result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ((yyvsp[0].code_gen).result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,">=",(yyvsp[-3].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&(yyval.code_gen).code,q_label);
				quad_add(&(yyval.code_gen).code,quad_a1);
				quad_add(&(yyval.code_gen).code,quad_a3);
				quad_add(&(yyval.code_gen).code,q_eval);
				quad_add(&(yyval.code_gen).code,q_goto);
				(yyval.code_gen).true_list = new_quad_list(q_eval);
				(yyval.code_gen).false_list = new_quad_list(q_goto);
			}
#line 3010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1569 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = NULL;
				
				// création d'une étiquette ici 
				
				struct symbol* new_label = new_tmp(&tds);
				new_label->isVar = 5; // création d'un symbole qui sera une étiquette dans le code Mips
				
				struct quad* q_label = new_quad(label_quad,"label",NULL,NULL,new_label);
				label_quad++;
				
				// créer un nouveau symbole qui contiendra le résultat de la condition
				struct symbol* tmp = new_tmp(&tds);
				// le symbole tmp sera le résultat du quad créer par cette condition
					//on ne connait pas encore le résultat de ce test
				
				
				// stocke l'argument 1 dans $t6
				
				struct symbol* s_t6 = alloc();
				s_t6->value = 14;
				
				struct quad* quad_a1 = NULL;
				
					
				if ((yyvsp[-3].code_gen).result->isVar == 0)
					quad_a1 =  new_quad(label_quad,"li",(yyvsp[-3].code_gen).result,NULL,s_t6);
				else
					quad_a1 =  new_quad(label_quad,"lw",(yyvsp[-3].code_gen).result,NULL,s_t6);
				label_quad ++ ;
				
				
				// stocke l'argument 2 dans $t7
				
				struct symbol* s_t7 = alloc();
				s_t7->value = 15;
				
				struct quad* quad_a3 = NULL;
				
					
				if ((yyvsp[0].code_gen).result->isVar == 0)
					quad_a3 =  new_quad(label_quad,"li",(yyvsp[0].code_gen).result,NULL,s_t7);
				else
					quad_a3 =  new_quad(label_quad,"lw",(yyvsp[0].code_gen).result,NULL,s_t7);
				label_quad ++ ;
				
				
				struct quad* q_eval = new_quad(label_quad,"<=",(yyvsp[-3].code_gen).result,(yyvsp[0].code_gen).result,tmp);
				label_quad ++;// incrémentation du label

				// création d'un label de goto 
					// le symbole tmp2 est un symbole qui est considéré comme un entier pour le label du goto
				struct symbol* tmp2 = new_tmp (&tds);
				struct quad* q_goto = new_quad(label_quad,"goto",NULL,NULL,tmp2);
				label_quad ++;
				
				quad_add(&(yyval.code_gen).code,q_label);
				quad_add(&(yyval.code_gen).code,quad_a1);
				quad_add(&(yyval.code_gen).code,quad_a3);
				quad_add(&(yyval.code_gen).code,q_eval);
				quad_add(&(yyval.code_gen).code,q_goto);
				(yyval.code_gen).true_list = new_quad_list(q_eval);
				(yyval.code_gen).false_list = new_quad_list(q_goto);
			}
#line 3079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1634 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = (yyval.code_gen).true_list = (yyval.code_gen).false_list =  NULL;
				(yyval.code_gen).code = (yyvsp[-1].code_gen).code;
				(yyval.code_gen).true_list = (yyvsp[-1].code_gen).true_list;
				(yyval.code_gen).false_list = (yyvsp[-1].code_gen).false_list;
			}
#line 3090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1641 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = (yyval.code_gen).true_list = (yyval.code_gen).false_list = NULL;
				// on ne peut rien dire sur la condition courante 

				// on peut completer la false_list de la première condition

				complete(&(yyvsp[-2].code_gen).false_list,(yyvsp[0].code_gen).code->node->label);


				concat(&(yyval.code_gen).true_list,(yyvsp[-2].code_gen).true_list);
				concat(&(yyval.code_gen).true_list,(yyvsp[0].code_gen).true_list);



				(yyval.code_gen).false_list=(yyvsp[0].code_gen).false_list;

				concat(&(yyval.code_gen).code,(yyvsp[-2].code_gen).code);
				concat(&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
			}
#line 3114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1661 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = (yyval.code_gen).true_list = (yyval.code_gen).false_list = NULL;

				// on peut completer la true_list de la première condition

				complete(&(yyvsp[-2].code_gen).true_list,(yyvsp[0].code_gen).code->node->label);


				concat(&(yyval.code_gen).false_list,(yyvsp[-2].code_gen).false_list);
				concat(&(yyval.code_gen).false_list,(yyvsp[0].code_gen).false_list);



				(yyval.code_gen).true_list=(yyvsp[0].code_gen).true_list;

				concat(&(yyval.code_gen).code,(yyvsp[-2].code_gen).code);
				concat(&(yyval.code_gen).code,(yyvsp[0].code_gen).code);
			}
#line 3137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1680 "proj.y" /* yacc.c:1646  */
    {
				(yyval.code_gen).code = (yyval.code_gen).true_list = (yyval.code_gen).false_list = NULL;
				(yyval.code_gen).true_list=(yyvsp[0].code_gen).false_list;
				(yyval.code_gen).false_list = (yyvsp[0].code_gen).true_list;
				(yyval.code_gen).code = (yyvsp[0].code_gen).code;
			}
#line 3148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1690 "proj.y" /* yacc.c:1646  */
    {
				(yyval.value) = (yyvsp[0].value);
			}
#line 3156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1694 "proj.y" /* yacc.c:1646  */
    {
				(yyval.value) = (yyvsp[0].value);
			}
#line 3164 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3168 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1700 "proj.y" /* yacc.c:1906  */



int main()
{
/* 	printf ("-----------------------------------------------------\n"); */
/* 	printf("\t\tYacc Compilateur StenC:\n"); */
/* 	printf ("-----------------------------------------------------\n"); */
	if (yyparse())
	{
		fprintf(stdout,"erreur\n");
		return -1;
	}
	
	
	
/* 	print_tds(tds); // effectuer un traitement sur cette liste des symboles */
/* 	quad_list_print(q_Globallist);	 */
	
	fprintf(stderr,"\n\nfin analyse\n");
	fprintf(stderr,"\n---> Début traitement\n\n");
	
	traitementQList(q_Globallist);
	traitementTds(tds);
	
	
	return 0;
}
