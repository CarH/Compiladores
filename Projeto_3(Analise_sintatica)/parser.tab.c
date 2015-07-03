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
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>     
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include "myscanner.h"

using namespace std;


// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" int YYRECOVERING();
extern "C" FILE *yyin;
extern "C" FILE *yytext;
extern int line_num;

char found[10000];
char needed[10000];


/****************************************************************************************
                                'SYMBOL TABLE'
                            TODO: por em outro .h 
*****************************************************************************************/
// Struct to the symbolTable: str.
struct Element
{
    string cadeia;
    string type;
    string cat;
    string val;
    int token;
    int line;
    int scope;
};

int CURR_SCOPE = 0;
unordered_map<int, unordered_map<string, Element> > symbolTableVector;
// unordered_map<string, Element> symbolTable;

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope);
bool find(int scope, string cadeia);
void printSymbolTable();

//       Definitions of some attributes
string CAT_PROGRAM_NAME = "main_prog_name";
string NONE             = "";


/*****************************************************************************************/


#line 123 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 62 "parser.y" /* yacc.c:355  */

    int numi;
    float numf;
    char *str;

#line 218 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   121,   121,   130,   131,   132,   134,   135,   136,   138,
     140,   141,   142,   143,   145,   146,   147,   148,   150,   151,
     153,   155,   156,   158,   159,   160,   162,   163,   165,   166,
     168,   169,   171,   172,   173,   175,   177,   178,   180,   181,
     182,   184,   185,   187,   188,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   201,   203,   204,   205,   206,
     207,   208,   209,   211,   213,   214,   215,   217,   218,   220,
     221,   223,   225,   226,   228,   229,   231,   232,   233,   235,
     236
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
  "op_ad", "termo", "mais_fatores", "op_mul", "fator", "numero", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    10
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   152,  -102,   -12,   -11,   -73,   -14,  -102,  -101,
    -102,    -5,     1,    25,  -102,  -102,    49,  -102,    48,   -21,
     -49,   111,  -102,   -47,  -102,    42,  -102,    71,    29,  -102,
      45,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    11,    12,    13,    72,    75,   143,    77,    49,
     117,   144,   173,   114,   115,    56,    85,   121,   119,    39,
      40,    60,    94,    61,    62,   101,   102,    63,   128,   129,
      97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
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
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
     '$$ = $1'.

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
#line 121 "parser.y" /* yacc.c:1646  */
    {   
                                                                                // CURR_SCOPE = 0;
                                                                                printf("IDENT: %d\n", IDENT);
                                                                                cout << "find(): "<< find(CURR_SCOPE, (yyvsp[-3].str)) << "\n";
                                                                                insert((yyvsp[-3].str), IDENT, NONE, CAT_PROGRAM_NAME, NONE, line_num, CURR_SCOPE);
                                                                                cout << "find(): "<< find(CURR_SCOPE, (yyvsp[-3].str)) << "\n";
                                                                                
                                                                                printSymbolTable();
                                                                            }
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 130 "parser.y" /* yacc.c:1646  */
    {;}
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 131 "parser.y" /* yacc.c:1646  */
    {;}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 132 "parser.y" /* yacc.c:1646  */
    {;}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "parser.y" /* yacc.c:1646  */
    {;}
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "parser.y" /* yacc.c:1646  */
    {;}
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "parser.y" /* yacc.c:1646  */
    {;}
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 138 "parser.y" /* yacc.c:1646  */
    {;}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 140 "parser.y" /* yacc.c:1646  */
    {;}
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "parser.y" /* yacc.c:1646  */
    {;}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 142 "parser.y" /* yacc.c:1646  */
    {;}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "parser.y" /* yacc.c:1646  */
    {;}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "parser.y" /* yacc.c:1646  */
    {;}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 146 "parser.y" /* yacc.c:1646  */
    {;}
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "parser.y" /* yacc.c:1646  */
    {;}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "parser.y" /* yacc.c:1646  */
    {;}
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "parser.y" /* yacc.c:1646  */
    {;}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 151 "parser.y" /* yacc.c:1646  */
    {;}
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 153 "parser.y" /* yacc.c:1646  */
    {;}
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 155 "parser.y" /* yacc.c:1646  */
    {;}
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 156 "parser.y" /* yacc.c:1646  */
    {;}
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 158 "parser.y" /* yacc.c:1646  */
    {;}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 159 "parser.y" /* yacc.c:1646  */
    {;}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 160 "parser.y" /* yacc.c:1646  */
    {;}
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "parser.y" /* yacc.c:1646  */
    {;}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 163 "parser.y" /* yacc.c:1646  */
    {;}
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 165 "parser.y" /* yacc.c:1646  */
    {;}
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 166 "parser.y" /* yacc.c:1646  */
    {;}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 168 "parser.y" /* yacc.c:1646  */
    {;}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 169 "parser.y" /* yacc.c:1646  */
    {;}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 171 "parser.y" /* yacc.c:1646  */
    {;}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 172 "parser.y" /* yacc.c:1646  */
    {;}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 173 "parser.y" /* yacc.c:1646  */
    {;}
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 175 "parser.y" /* yacc.c:1646  */
    {;}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 177 "parser.y" /* yacc.c:1646  */
    {;}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 178 "parser.y" /* yacc.c:1646  */
    {;}
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 180 "parser.y" /* yacc.c:1646  */
    {;}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 181 "parser.y" /* yacc.c:1646  */
    {;}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 182 "parser.y" /* yacc.c:1646  */
    {;}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 184 "parser.y" /* yacc.c:1646  */
    {;}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "parser.y" /* yacc.c:1646  */
    {;}
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 187 "parser.y" /* yacc.c:1646  */
    {;}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 188 "parser.y" /* yacc.c:1646  */
    {;}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 190 "parser.y" /* yacc.c:1646  */
    {;}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 191 "parser.y" /* yacc.c:1646  */
    {;}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 192 "parser.y" /* yacc.c:1646  */
    {;}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 193 "parser.y" /* yacc.c:1646  */
    {;}
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 194 "parser.y" /* yacc.c:1646  */
    {;}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 195 "parser.y" /* yacc.c:1646  */
    {;}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 196 "parser.y" /* yacc.c:1646  */
    {;}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 197 "parser.y" /* yacc.c:1646  */
    {;}
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 198 "parser.y" /* yacc.c:1646  */
    {;}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 199 "parser.y" /* yacc.c:1646  */
    {;}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 201 "parser.y" /* yacc.c:1646  */
    {;}
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 203 "parser.y" /* yacc.c:1646  */
    {;}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 204 "parser.y" /* yacc.c:1646  */
    {;}
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 205 "parser.y" /* yacc.c:1646  */
    {;}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 206 "parser.y" /* yacc.c:1646  */
    {;}
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 207 "parser.y" /* yacc.c:1646  */
    {;}
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 208 "parser.y" /* yacc.c:1646  */
    {;}
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 209 "parser.y" /* yacc.c:1646  */
    {;}
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 211 "parser.y" /* yacc.c:1646  */
    {;}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 213 "parser.y" /* yacc.c:1646  */
    {;}
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 214 "parser.y" /* yacc.c:1646  */
    {;}
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 215 "parser.y" /* yacc.c:1646  */
    {;}
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 217 "parser.y" /* yacc.c:1646  */
    {;}
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 218 "parser.y" /* yacc.c:1646  */
    {;}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 220 "parser.y" /* yacc.c:1646  */
    {;}
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 221 "parser.y" /* yacc.c:1646  */
    {;}
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 223 "parser.y" /* yacc.c:1646  */
    {;}
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 225 "parser.y" /* yacc.c:1646  */
    {;}
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 226 "parser.y" /* yacc.c:1646  */
    {;}
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 228 "parser.y" /* yacc.c:1646  */
    {;}
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 229 "parser.y" /* yacc.c:1646  */
    {;}
#line 1988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 231 "parser.y" /* yacc.c:1646  */
    {;}
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 232 "parser.y" /* yacc.c:1646  */
    {;}
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 233 "parser.y" /* yacc.c:1646  */
    {;}
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "parser.y" /* yacc.c:1646  */
    {;}
#line 2012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 236 "parser.y" /* yacc.c:1646  */
    {;}
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2022 "parser.tab.c" /* yacc.c:1646  */
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 242 "parser.y" /* yacc.c:1906  */


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
    printf("%s", str);
}


/*****************************************************************************************
                
                            Symbol Table functions 

*****************************************************************************************/

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope) {
    cout << " >> Inserindo cadeia: " << cadeia << " | token: " << token << " | type: " << type << " | cat: " << cat << " | val: " << val << " | line: " << line << " | scope: " << scope << "\n";
    unordered_map<int, unordered_map<string, Element> >::iterator it;
    it = symbolTableVector.find(scope);
    
    if (it == symbolTableVector.end()) { // Is there a symbolTable to this scope?
        // Create a new symbolTable for this scope
        unordered_map<string, Element> symbolTable;
        pair<int, unordered_map<string, Element> > symbolTableVectorItem (scope, symbolTable);
        symbolTableVector.insert(symbolTableVectorItem);
    }
    
    /**
        it->first   : scope
        it->second  : symbolTable of the scope
    */
    it = symbolTableVector.find(scope);
    Element elem;
    elem.cadeia = cadeia;
    elem.token  = token;
    elem.type   = type;
    elem.cat    = cat;
    elem.val    = val;
    elem.line   = line;
    elem.scope  = scope;

    pair<string, Element> tableItem (cadeia, elem);
    it->second.insert(tableItem);

}

bool find(int scope, string cadeia) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;

    it1 = symbolTableVector.find(scope);
    
    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            return true;
        }
    }
    return false;
}

void printSymbolTable() {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;

    cout << "\n>> Printing Symbol Tables from all scopes:" << "\n\n";

    for(it1 = symbolTableVector.begin(); it1 != symbolTableVector.end(); it1++){ // For each scope
        cout << "|SCOPE : " << it1->first << "\n";
        cout << " ________________________________________________________________________________ \n";
        cout << "|   CADEIA   |  TOKEN |   TYPE   |      CATEGORY      |   VAL  |  LINE  |  SCOPE |" << endl;
        cout << "|____________|________|__________|____________________|________|________|________|\n";
        for(it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {  
            printf("|%12s|%8d|%10s|%20s|%8s|%8d|%8d|\n", it2->second.cadeia.c_str(), it2->second.token, it2->second.type.c_str(), it2->second.cat.c_str(), it2->second.val.c_str(), it2->second.line, it2->second.scope);
        }
        cout << "|____________|________|__________|____________________|________|________|________|\n\n";
    }

    cout << "\n";
} 
/*****************************************************************************************/
