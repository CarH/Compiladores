/* A Bison parser, made by GNU Bison 2.6.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 336 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>     
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include "myscanner.h"

using namespace std;


// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" int YYRECOVERING();
extern "C" FILE *yyin;
extern "C" FILE *yytext;
extern int line_num;


/* Line 336 of yacc.c  */
#line 89 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.tab.h".  */
#ifndef YY_PARSER_TAB_H
# define YY_PARSER_TAB_H
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ERRODESC = 258,
     IDENT = 259,
     SEMICOLON = 260,
     ENDPOINT = 261,
     ATTRIBUTION = 262,
     CONST_IDENT = 263,
     COLON = 264,
     TYPE = 265,
     COMMA = 266,
     PROCEDURE_IDENT = 267,
     OPEN_PAR = 268,
     CLOSE_PAR = 269,
     EQUAL = 270,
     DIF = 271,
     GREATER_EQUAL = 272,
     LESSER_EQUAL = 273,
     GREATER = 274,
     LESSER = 275,
     PLUS = 276,
     MINUS = 277,
     MULT = 278,
     DIV = 279,
     INTEGER_NUMBER = 280,
     REAL_NUMBER = 281,
     UNEXPECTED_CHAR = 282,
     ERROINT = 283,
     ERROIDENT = 284,
     ERROFLOAT = 285,
     ERROTAM = 286,
     PROGRAM = 287,
     BEG = 288,
     END = 289,
     IF = 290,
     ELSE = 291,
     CONST = 292,
     VAR = 293,
     PROCEDURE = 294,
     REAL = 295,
     INTEGER = 296,
     READ = 297,
     WRITE = 298,
     WHILE = 299,
     DO = 300,
     THEN = 301,
     FOR = 302,
     TO = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 350 of yacc.c  */
#line 23 "parser.y"

    int numi;
    float numf;
    char *str;



/* Line 350 of yacc.c  */
#line 189 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_PARSER_TAB_H  */

/* Copy the second part of user declarations.  */


/* Line 353 of yacc.c  */
#line 231 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    14,    17,    20,    25,    30,    33,
      37,    44,    50,    54,    55,    62,    68,    72,    73,    75,
      77,    80,    83,    84,    91,    96,    97,   101,   102,   107,
     112,   115,   116,   122,   128,   131,   133,   137,   138,   141,
     144,   145,   148,   149,   153,   154,   159,   164,   171,   177,
     181,   184,   188,   199,   204,   207,   211,   213,   215,   217,
     219,   221,   223,   224,   227,   229,   231,   232,   236,   237,
     239,   241,   245,   249,   250,   252,   254,   256,   258,   262,
     264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    32,     4,     5,    52,     6,    -1,     1,
       5,    52,     6,    -1,     1,     6,    -1,     1,    49,    -1,
      53,    33,    69,    34,    -1,     1,    33,    69,    34,    -1,
       1,    34,    -1,    54,    55,    59,    -1,    37,     4,    15,
      81,     5,    54,    -1,     1,    15,    81,     5,    54,    -1,
       1,     5,    54,    -1,    -1,    38,    57,     9,    56,     5,
      55,    -1,     1,     9,    56,     5,    55,    -1,     1,     5,
      55,    -1,    -1,    40,    -1,    41,    -1,     4,    58,    -1,
      11,    57,    -1,    -1,    39,     4,    60,     5,    63,    59,
      -1,     1,     5,    63,    59,    -1,    -1,    13,    61,    14,
      -1,    -1,    57,     9,    56,    62,    -1,     1,     9,    56,
      62,    -1,     5,    61,    -1,    -1,    64,    33,    69,    34,
       5,    -1,     1,    33,    69,    34,     5,    -1,     1,     5,
      -1,    55,    -1,    13,    66,    14,    -1,    -1,     4,    67,
      -1,     5,    66,    -1,    -1,    36,    70,    -1,    -1,    70,
       5,    69,    -1,    -1,    42,    13,    57,    14,    -1,    43,
      13,    57,    14,    -1,    44,    13,    71,    14,    45,    70,
      -1,    35,    71,    46,    70,    68,    -1,     4,     7,    73,
      -1,     4,    65,    -1,    33,    69,    34,    -1,    47,     4,
       7,    81,    48,    81,    45,    33,    69,    34,    -1,     1,
      46,    70,    68,    -1,     1,    34,    -1,    73,    72,    73,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    20,    -1,    -1,    77,    75,    -1,    21,    -1,    22,
      -1,    -1,    76,    77,    75,    -1,    -1,    21,    -1,    22,
      -1,    74,    80,    78,    -1,    79,    80,    78,    -1,    -1,
      23,    -1,    24,    -1,     4,    -1,    81,    -1,    13,    73,
      14,    -1,    25,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    84,    85,    86,    88,    89,    90,    92,
      94,    95,    96,    97,    99,   100,   101,   102,   104,   105,
     107,   109,   110,   112,   113,   114,   116,   117,   119,   120,
     122,   123,   125,   126,   127,   129,   131,   132,   134,   135,
     136,   138,   139,   141,   142,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   155,   157,   158,   159,   160,
     161,   162,   163,   165,   167,   168,   169,   171,   172,   174,
     175,   177,   179,   180,   182,   183,   185,   186,   187,   189,
     190
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERRODESC", "IDENT", "SEMICOLON",
  "ENDPOINT", "ATTRIBUTION", "CONST_IDENT", "COLON", "TYPE", "COMMA",
  "PROCEDURE_IDENT", "OPEN_PAR", "CLOSE_PAR", "EQUAL", "DIF",
  "GREATER_EQUAL", "LESSER_EQUAL", "GREATER", "LESSER", "PLUS", "MINUS",
  "MULT", "DIV", "INTEGER_NUMBER", "REAL_NUMBER", "UNEXPECTED_CHAR",
  "ERROINT", "ERROIDENT", "ERROFLOAT", "ERROTAM", "PROGRAM", "BEG", "END",
  "IF", "ELSE", "CONST", "VAR", "PROCEDURE", "REAL", "INTEGER", "READ",
  "WRITE", "WHILE", "DO", "THEN", "FOR", "TO", "'\\n'", "$accept",
  "programa", "corpo", "dc", "dc_c", "dc_v", "tipo_var", "variaveis",
  "mais_var", "dc_p", "parametros", "lista_par", "mais_par", "corpo_p",
  "dc_loc", "lista_arg", "argumentos", "mais_ident", "pfalsa", "comandos",
  "cmd", "condicao", "relacao", "expressao", "op_un", "outros_termos",
  "op_ad", "termo", "mais_fatores", "op_mul", "fator", "numero", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    52,    52,    52,    53,
      54,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      57,    58,    58,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    64,    65,    65,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    72,    72,    72,    72,
      72,    72,    72,    73,    74,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    80,    81,
      81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     2,     4,     4,     2,     3,
       6,     5,     3,     0,     6,     5,     3,     0,     1,     1,
       2,     2,     0,     6,     4,     0,     3,     0,     4,     4,
       2,     0,     5,     5,     2,     1,     3,     0,     2,     2,
       0,     2,     0,     3,     0,     4,     4,     6,     5,     3,
       2,     3,    10,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     0,     3,     0,     1,
       1,     3,     3,     0,     1,     1,     1,     1,     3,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     5,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       3,     0,     0,     0,     0,     0,     0,    12,    79,    80,
       0,     0,    37,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     9,
       2,     0,    54,     0,    66,     0,    50,     0,    64,    65,
       0,    62,     0,    68,     0,     0,    66,     0,     7,     0,
       0,     6,    16,    18,    19,     0,     0,    20,     0,     0,
      27,    11,    42,    49,    40,     0,    51,     0,    56,    57,
      58,    59,    60,    61,    66,    76,    66,    73,    77,    69,
      70,    63,    66,     0,     0,     0,     0,    43,     0,     0,
      21,     0,     0,    35,     0,     0,     0,     0,     0,    53,
       0,    38,    36,    42,    55,     0,    74,    75,    71,     0,
      68,    45,    46,     0,     0,    10,    15,     0,     0,     0,
      24,     0,     0,     0,     0,     0,    41,    39,    48,    78,
      73,    67,     0,     0,    14,     0,     0,     0,     0,    26,
       0,    72,    47,     0,     0,     0,    31,    31,    23,     0,
      33,    32,     0,    29,    28,     0,    30,     0,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    11,    12,    13,    72,    75,   143,    77,    49,
     117,   144,   173,   114,   115,    56,    85,   121,   119,    39,
      40,    60,    94,    61,    62,   101,   102,    63,   128,   129,
      97,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
       5,    11,    24,    30,    39,  -102,  -102,    31,  -102,    56,
      37,    58,    55,    41,    39,    62,     9,    10,  -102,    79,
    -102,    10,    20,    98,    72,    91,    18,  -102,  -102,  -102,
      99,   -26,     8,    10,    60,    97,   102,   106,   117,    88,
     101,     9,    89,    41,    68,   113,   116,   128,   131,  -102,
    -102,    62,  -102,    23,    60,   132,  -102,   103,  -102,  -102,
      94,   112,     6,    92,    98,    98,    60,   134,  -102,    10,
     137,  -102,  -102,  -102,  -102,   138,    98,  -102,    68,    74,
     126,  -102,   108,  -102,   140,   133,  -102,    23,  -102,  -102,
    -102,  -102,  -102,  -102,    60,  -102,    60,    93,  -102,  -102,
    -102,  -102,    60,   135,   136,   139,     9,  -102,    62,    41,
    -102,   141,    13,  -102,    72,   115,    82,   146,    23,  -102,
     132,  -102,  -102,   108,  -102,   142,  -102,  -102,  -102,     6,
      92,  -102,  -102,   107,   109,  -102,  -102,    41,    54,    10,
    -102,    10,   149,   150,   147,    74,  -102,  -102,  -102,  -102,
      93,  -102,    23,     9,  -102,   121,   129,    68,    68,  -102,
      72,  -102,  -102,   119,   155,   157,   160,   160,  -102,   143,
    -102,  -102,    82,  -102,  -102,    10,  -102,   144,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   152,  -102,   -12,   -11,   -73,   -14,  -102,  -101,
    -102,    -5,     1,    25,  -102,  -102,    49,  -102,    48,   -21,
     -49,   111,  -102,   -47,  -102,    42,  -102,    71,    29,  -102,
      45,   -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      42,    30,    24,    27,    82,   111,     1,    83,    52,    46,
      95,    31,    57,   140,    32,    54,     4,     5,   138,    96,
      53,    55,    44,    15,    31,    43,    70,    32,     7,    44,
       8,    28,    29,    16,    28,    29,    14,     2,   123,    81,
       9,    19,    22,    33,   -44,    34,   139,   124,   107,   125,
     103,   104,    35,    36,    37,    22,    33,    38,    34,   168,
       6,    15,   110,    26,    20,    35,    36,    37,   113,   146,
      38,    16,   -13,    47,   -17,   112,    10,   -13,   -13,    23,
     -17,    58,    59,   142,   166,   167,    45,   -17,    21,    17,
      18,   134,    23,   -34,    41,   -13,   135,    50,   136,    10,
     -13,   -13,    45,   162,    51,   -25,    69,   -17,    73,    74,
      64,    48,    23,    99,   100,    65,   126,   127,   155,    66,
     156,    67,    68,    71,    76,    78,   154,    88,    89,    90,
      91,    92,    93,    79,   113,    80,    84,    86,   163,   116,
      87,   106,   108,   109,   118,   120,   137,   122,   141,   131,
     132,   145,   152,   133,   177,   164,   149,   153,   157,   158,
     170,   159,   171,   165,   169,   172,    25,   176,   174,   147,
     160,   148,   151,   130,   150,     0,   175,   105,   178,   161
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-102))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      21,    16,    13,    15,    53,    78,     1,    54,    34,    23,
       4,     1,    33,   114,     4,     7,     5,     6,     5,    13,
      46,    13,     9,     5,     1,     5,    41,     4,     4,     9,
       0,    25,    26,    15,    25,    26,     5,    32,    87,    51,
       1,     4,     1,    33,    34,    35,    33,    94,    69,    96,
      64,    65,    42,    43,    44,     1,    33,    47,    35,   160,
      49,     5,    76,     1,     6,    42,    43,    44,    79,   118,
      47,    15,    33,     1,    33,     1,    37,    38,    39,    38,
      39,    21,    22,     1,   157,   158,     4,    33,    33,    33,
      34,   106,    38,    39,    15,    33,   108,     6,   109,    37,
      38,    39,     4,   152,     5,    33,     5,    33,    40,    41,
      13,    39,    38,    21,    22,    13,    23,    24,   139,    13,
     141,     4,    34,    34,    11,     9,   137,    15,    16,    17,
      18,    19,    20,     5,   145,     4,     4,    34,   153,    13,
      46,     7,     5,     5,    36,     5,     5,    14,    33,    14,
      14,     5,    45,    14,   175,    34,    14,    48,     9,     9,
       5,    14,     5,    34,    45,     5,    14,   172,   167,   120,
     145,   123,   130,   102,   129,    -1,    33,    66,    34,   150
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    32,    51,     5,     6,    49,     4,     0,     1,
      37,    52,    53,    54,     5,     5,    15,    33,    34,     4,
       6,    33,     1,    38,    55,    52,     1,    54,    25,    26,
      81,     1,     4,    33,    35,    42,    43,    44,    47,    69,
      70,    15,    69,     5,     9,     4,    57,     1,    39,    59,
       6,     5,    34,    46,     7,    13,    65,    69,    21,    22,
      71,    73,    74,    77,    13,    13,    13,     4,    34,     5,
      81,    34,    55,    40,    41,    56,    11,    58,     9,     5,
       4,    54,    70,    73,     4,    66,    34,    46,    15,    16,
      17,    18,    19,    20,    72,     4,    13,    80,    81,    21,
      22,    75,    76,    57,    57,    71,     7,    69,     5,     5,
      57,    56,     1,    55,    63,    64,    13,    60,    36,    68,
       5,    67,    14,    70,    73,    73,    23,    24,    78,    79,
      77,    14,    14,    14,    81,    54,    55,     5,     5,    33,
      59,    33,     1,    57,    61,     5,    70,    66,    68,    14,
      80,    75,    45,    48,    55,    69,    69,     9,     9,    14,
      63,    78,    70,    81,    34,    34,    56,    56,    59,    45,
       5,     5,     5,    62,    62,    33,    61,    69,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1788 of yacc.c  */
#line 83 "parser.y"
    {;}
    break;

  case 3:

/* Line 1788 of yacc.c  */
#line 84 "parser.y"
    {;}
    break;

  case 4:

/* Line 1788 of yacc.c  */
#line 85 "parser.y"
    {;}
    break;

  case 5:

/* Line 1788 of yacc.c  */
#line 86 "parser.y"
    {;}
    break;

  case 6:

/* Line 1788 of yacc.c  */
#line 88 "parser.y"
    {;}
    break;

  case 7:

/* Line 1788 of yacc.c  */
#line 89 "parser.y"
    {;}
    break;

  case 8:

/* Line 1788 of yacc.c  */
#line 90 "parser.y"
    {;}
    break;

  case 9:

/* Line 1788 of yacc.c  */
#line 92 "parser.y"
    {;}
    break;

  case 10:

/* Line 1788 of yacc.c  */
#line 94 "parser.y"
    {;}
    break;

  case 11:

/* Line 1788 of yacc.c  */
#line 95 "parser.y"
    {;}
    break;

  case 12:

/* Line 1788 of yacc.c  */
#line 96 "parser.y"
    {;}
    break;

  case 13:

/* Line 1788 of yacc.c  */
#line 97 "parser.y"
    {;}
    break;

  case 14:

/* Line 1788 of yacc.c  */
#line 99 "parser.y"
    {;}
    break;

  case 15:

/* Line 1788 of yacc.c  */
#line 100 "parser.y"
    {;}
    break;

  case 16:

/* Line 1788 of yacc.c  */
#line 101 "parser.y"
    {;}
    break;

  case 17:

/* Line 1788 of yacc.c  */
#line 102 "parser.y"
    {;}
    break;

  case 18:

/* Line 1788 of yacc.c  */
#line 104 "parser.y"
    {;}
    break;

  case 19:

/* Line 1788 of yacc.c  */
#line 105 "parser.y"
    {;}
    break;

  case 20:

/* Line 1788 of yacc.c  */
#line 107 "parser.y"
    {;}
    break;

  case 21:

/* Line 1788 of yacc.c  */
#line 109 "parser.y"
    {;}
    break;

  case 22:

/* Line 1788 of yacc.c  */
#line 110 "parser.y"
    {;}
    break;

  case 23:

/* Line 1788 of yacc.c  */
#line 112 "parser.y"
    {;}
    break;

  case 24:

/* Line 1788 of yacc.c  */
#line 113 "parser.y"
    {;}
    break;

  case 25:

/* Line 1788 of yacc.c  */
#line 114 "parser.y"
    {;}
    break;

  case 26:

/* Line 1788 of yacc.c  */
#line 116 "parser.y"
    {;}
    break;

  case 27:

/* Line 1788 of yacc.c  */
#line 117 "parser.y"
    {;}
    break;

  case 28:

/* Line 1788 of yacc.c  */
#line 119 "parser.y"
    {;}
    break;

  case 29:

/* Line 1788 of yacc.c  */
#line 120 "parser.y"
    {;}
    break;

  case 30:

/* Line 1788 of yacc.c  */
#line 122 "parser.y"
    {;}
    break;

  case 31:

/* Line 1788 of yacc.c  */
#line 123 "parser.y"
    {;}
    break;

  case 32:

/* Line 1788 of yacc.c  */
#line 125 "parser.y"
    {;}
    break;

  case 33:

/* Line 1788 of yacc.c  */
#line 126 "parser.y"
    {;}
    break;

  case 34:

/* Line 1788 of yacc.c  */
#line 127 "parser.y"
    {;}
    break;

  case 35:

/* Line 1788 of yacc.c  */
#line 129 "parser.y"
    {;}
    break;

  case 36:

/* Line 1788 of yacc.c  */
#line 131 "parser.y"
    {;}
    break;

  case 37:

/* Line 1788 of yacc.c  */
#line 132 "parser.y"
    {;}
    break;

  case 38:

/* Line 1788 of yacc.c  */
#line 134 "parser.y"
    {;}
    break;

  case 39:

/* Line 1788 of yacc.c  */
#line 135 "parser.y"
    {;}
    break;

  case 40:

/* Line 1788 of yacc.c  */
#line 136 "parser.y"
    {;}
    break;

  case 41:

/* Line 1788 of yacc.c  */
#line 138 "parser.y"
    {;}
    break;

  case 42:

/* Line 1788 of yacc.c  */
#line 139 "parser.y"
    {;}
    break;

  case 43:

/* Line 1788 of yacc.c  */
#line 141 "parser.y"
    {;}
    break;

  case 44:

/* Line 1788 of yacc.c  */
#line 142 "parser.y"
    {;}
    break;

  case 45:

/* Line 1788 of yacc.c  */
#line 144 "parser.y"
    {;}
    break;

  case 46:

/* Line 1788 of yacc.c  */
#line 145 "parser.y"
    {;}
    break;

  case 47:

/* Line 1788 of yacc.c  */
#line 146 "parser.y"
    {;}
    break;

  case 48:

/* Line 1788 of yacc.c  */
#line 147 "parser.y"
    {;}
    break;

  case 49:

/* Line 1788 of yacc.c  */
#line 148 "parser.y"
    {;}
    break;

  case 50:

/* Line 1788 of yacc.c  */
#line 149 "parser.y"
    {;}
    break;

  case 51:

/* Line 1788 of yacc.c  */
#line 150 "parser.y"
    {;}
    break;

  case 52:

/* Line 1788 of yacc.c  */
#line 151 "parser.y"
    {;}
    break;

  case 53:

/* Line 1788 of yacc.c  */
#line 152 "parser.y"
    {;}
    break;

  case 54:

/* Line 1788 of yacc.c  */
#line 153 "parser.y"
    {;}
    break;

  case 55:

/* Line 1788 of yacc.c  */
#line 155 "parser.y"
    {;}
    break;

  case 56:

/* Line 1788 of yacc.c  */
#line 157 "parser.y"
    {;}
    break;

  case 57:

/* Line 1788 of yacc.c  */
#line 158 "parser.y"
    {;}
    break;

  case 58:

/* Line 1788 of yacc.c  */
#line 159 "parser.y"
    {;}
    break;

  case 59:

/* Line 1788 of yacc.c  */
#line 160 "parser.y"
    {;}
    break;

  case 60:

/* Line 1788 of yacc.c  */
#line 161 "parser.y"
    {;}
    break;

  case 61:

/* Line 1788 of yacc.c  */
#line 162 "parser.y"
    {;}
    break;

  case 62:

/* Line 1788 of yacc.c  */
#line 163 "parser.y"
    {;}
    break;

  case 63:

/* Line 1788 of yacc.c  */
#line 165 "parser.y"
    {;}
    break;

  case 64:

/* Line 1788 of yacc.c  */
#line 167 "parser.y"
    {;}
    break;

  case 65:

/* Line 1788 of yacc.c  */
#line 168 "parser.y"
    {;}
    break;

  case 66:

/* Line 1788 of yacc.c  */
#line 169 "parser.y"
    {;}
    break;

  case 67:

/* Line 1788 of yacc.c  */
#line 171 "parser.y"
    {;}
    break;

  case 68:

/* Line 1788 of yacc.c  */
#line 172 "parser.y"
    {;}
    break;

  case 69:

/* Line 1788 of yacc.c  */
#line 174 "parser.y"
    {;}
    break;

  case 70:

/* Line 1788 of yacc.c  */
#line 175 "parser.y"
    {;}
    break;

  case 71:

/* Line 1788 of yacc.c  */
#line 177 "parser.y"
    {;}
    break;

  case 72:

/* Line 1788 of yacc.c  */
#line 179 "parser.y"
    {;}
    break;

  case 73:

/* Line 1788 of yacc.c  */
#line 180 "parser.y"
    {;}
    break;

  case 74:

/* Line 1788 of yacc.c  */
#line 182 "parser.y"
    {;}
    break;

  case 75:

/* Line 1788 of yacc.c  */
#line 183 "parser.y"
    {;}
    break;

  case 76:

/* Line 1788 of yacc.c  */
#line 185 "parser.y"
    {;}
    break;

  case 77:

/* Line 1788 of yacc.c  */
#line 186 "parser.y"
    {;}
    break;

  case 78:

/* Line 1788 of yacc.c  */
#line 187 "parser.y"
    {;}
    break;

  case 79:

/* Line 1788 of yacc.c  */
#line 189 "parser.y"
    {;}
    break;

  case 80:

/* Line 1788 of yacc.c  */
#line 190 "parser.y"
    {;}
    break;



/* Line 1788 of yacc.c  */
#line 2199 "parser.tab.c"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2049 of yacc.c  */
#line 196 "parser.y"


/**/

int main(int argc, char const *argv[]){
    int ntoken;
    int tam;
    return yyparse ( );
}
void yyerror(const char *str)
{
    if (!strcmp(yylval.str, "skip"))
    {
        yylval.str = strdup("");
        return;
    }
    printf("Line: %d: %s (found %s)\n", line_num, str, yytext);
}

