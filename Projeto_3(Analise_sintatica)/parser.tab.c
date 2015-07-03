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
#include <map>
#include <vector>
#include <string>
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

// Enable/disable the debugging mode
#define DEBUG false

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
    int numParams;
};

int CURR_SCOPE = 0;
unordered_map<int, unordered_map<string, Element> > symbolTableVector;
// unordered_map<string, Element> symbolTable;

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope, int numParams);
bool find(int scope, string cadeia);
bool updateType(vector<string> cadeia, string type, int scope);
void printSymbolTable();
int getNumberOfParams(string procName);
void printProcParameters(string procName);
Element getElement(string cadeia);
bool find(string cadeia, string category);
string getType(string cadeia, string category);


/****************************************
|   Definitions of some attributes      |
****************************************/
// Categories:
string CAT_PROGRAM_NAME = "main_prog_name";
string CAT_PROCEDURE    = "procedure";
string CAT_CONSTANT     = "constant";
string CAT_VARIABLE     = "variable";
string NONE             = "";

// Types
string INT_TYPE         = "integer";
string REAL_TYPE        = "real";


/****************************************
|   Temp variables to hold data         |
|  during the handle recognition        |
****************************************/
string t_num;
string t_type;
vector<string> t_cadeias;

/****************************************
|       Parameters of the Procedures    |
****************************************/
unordered_map<string, vector<Element> > procParams;
string curr_proc_name;
bool is_proc_parameter = false;
bool is_valid_procedure = false;
bool is_procedure = false;


string MSG_BEGIN_ERROR = "[Erro] Linha ";
/*****************************************************************************************/

map<string, string> m;


#line 167 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    COLON = 263,
    COMMA = 264,
    OPEN_PAR = 265,
    CLOSE_PAR = 266,
    EQUAL = 267,
    DIF = 268,
    GREATER_EQUAL = 269,
    LESSER_EQUAL = 270,
    GREATER = 271,
    LESSER = 272,
    PLUS = 273,
    MINUS = 274,
    MULT = 275,
    DIV = 276,
    INTEGER_NUMBER = 277,
    REAL_NUMBER = 278,
    UNEXPECTED_CHAR = 279,
    ERROINT = 280,
    ERROIDENT = 281,
    ERROFLOAT = 282,
    ERROTAM = 283,
    PROGRAM = 284,
    BEG = 285,
    END = 286,
    IF = 287,
    ELSE = 288,
    CONST = 289,
    VAR = 290,
    PROCEDURE = 291,
    REAL = 292,
    INTEGER = 293,
    READ = 294,
    WRITE = 295,
    WHILE = 296,
    DO = 297,
    THEN = 298,
    FOR = 299,
    TO = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 106 "parser.y" /* yacc.c:355  */

    int numi;
    float numf;
    char *str;

#line 259 "parser.tab.c" /* yacc.c:355  */
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

#line 288 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   173,   177,   178,   182,   183,   184,   185,
     189,   194,   195,   196,   197,   201,   202,   203,   204,   205,
     209,   237,   268,   275,   276,   280,   300,   305,   280,   317,
     318,   319,   320,   324,   324,   326,   327,   331,   332,   333,
     337,   338,   342,   343,   344,   348,   352,   352,   356,   357,
     361,   361,   372,   373,   377,   378,   379,   383,   384,   385,
     395,   396,   397,   398,   399,   399,   405,   405,   411,   412,
     416,   420,   421,   422,   423,   424,   425,   426,   430,   434,
     435,   436,   440,   441,   445,   446,   450,   454,   455,   459,
     460,   464,   465,   466,   470,   475
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERRODESC", "IDENT", "SEMICOLON",
  "ENDPOINT", "ATTRIBUTION", "COLON", "COMMA", "OPEN_PAR", "CLOSE_PAR",
  "EQUAL", "DIF", "GREATER_EQUAL", "LESSER_EQUAL", "GREATER", "LESSER",
  "PLUS", "MINUS", "MULT", "DIV", "INTEGER_NUMBER", "REAL_NUMBER",
  "UNEXPECTED_CHAR", "ERROINT", "ERROIDENT", "ERROFLOAT", "ERROTAM",
  "PROGRAM", "BEG", "END", "IF", "ELSE", "CONST", "VAR", "PROCEDURE",
  "REAL", "INTEGER", "READ", "WRITE", "WHILE", "DO", "THEN", "FOR", "TO",
  "$accept", "programa", "corpo", "dc", "dc_c", "dc_v", "tipo_var",
  "variaveis", "mais_var", "dc_p", "$@1", "$@2", "$@3", "parametros",
  "$@4", "lista_par", "mais_par", "corpo_p", "dc_loc", "lista_arg", "$@5",
  "argumentos", "$@6", "mais_ident", "pfalsa", "comandos", "cmd", "$@7",
  "$@8", "condicao", "relacao", "expressao", "op_un", "outros_termos",
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
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    14,    25,    50,    31,    26,  -109,   159,    74,    90,
       9,    12,    31,   112,    69,  -109,  -109,    78,    98,   -12,
    -109,  -109,   115,   116,  -109,    13,    13,   132,    71,   118,
     140,    76,    29,  -109,  -109,   143,  -109,   150,   168,  -109,
     151,  -109,    69,    15,    13,   154,    13,    68,   155,   160,
     170,   197,   190,   201,   191,    12,    79,  -109,  -109,    78,
    -109,   122,  -109,    71,   198,   218,   117,   137,   162,   137,
     221,  -109,   227,  -109,  -109,   223,   206,  -109,  -109,   192,
     203,   204,   205,    78,    78,    68,   229,  -109,    13,  -109,
    -109,   162,  -109,   149,   175,    13,  -109,    13,  -109,    22,
     226,   228,  -109,  -109,   233,   195,  -109,    71,   235,  -109,
      69,    68,   128,  -109,  -109,    51,  -109,  -109,  -109,  -109,
    -109,  -109,    68,  -109,    68,   166,  -109,  -109,  -109,  -109,
      68,   230,   231,   232,    15,  -109,   175,   213,   214,   117,
     241,  -109,   137,  -109,    12,   177,  -109,    12,   242,  -109,
    -109,   237,   245,    92,  -109,   239,  -109,  -109,  -109,   204,
     205,  -109,  -109,   209,   207,   248,   249,  -109,  -109,   241,
    -109,  -109,   162,  -109,  -109,   244,    51,    51,  -109,  -109,
     166,  -109,    51,    15,  -109,  -109,  -109,  -109,   251,  -109,
    -109,  -109,  -109,  -109,   215,    71,   245,  -109,   234,  -109,
    -109,    13,   236,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     8,
       7,     9,     0,     0,     3,     0,     0,     0,     0,     0,
      24,     0,     0,    13,    18,     0,    31,     0,     0,    12,
       0,    25,     0,     0,     0,    66,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     2,     0,
      22,     0,    17,     0,     0,     0,     0,     0,     0,     0,
      36,    11,     0,    58,    64,    49,     0,    79,    80,     0,
      77,     0,    83,     0,     0,    81,     0,     5,     0,     4,
      17,     0,    23,     0,     0,     0,    30,     0,    35,    41,
       0,     0,    20,    21,     0,     0,    45,     0,     0,    26,
       0,    81,     0,    67,    68,     0,    71,    72,    73,    74,
      75,    76,    81,    91,    81,    88,    92,    84,    85,    78,
      81,     0,     0,     0,     0,    57,     0,     0,     0,     0,
      41,    39,     0,    34,     0,     0,    29,     0,     0,    10,
      65,     0,     0,     0,    70,     0,    89,    90,    86,     0,
      83,    60,    61,     0,     0,     0,     0,    40,    38,    41,
      16,    15,     0,    48,    50,     0,     0,     0,    63,    93,
      88,    82,     0,     0,    43,    42,    37,    27,    53,    47,
      55,    54,    87,    62,     0,     0,     0,    51,     0,    28,
      52,     0,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,   246,  -109,     4,    -6,   -63,    -8,  -109,    -7,
    -109,  -109,  -109,   189,  -109,   121,  -106,   -64,  -109,  -109,
    -109,    65,  -109,  -109,  -109,   -24,  -108,  -109,  -109,   178,
    -109,   -96,  -109,   102,  -109,   135,    86,  -109,   109,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     9,    10,    33,    34,   104,    35,    60,    36,
      70,   148,   195,    37,    66,   101,   141,    63,    64,   113,
     152,   175,   188,   197,   178,    52,    53,   111,    75,    79,
     122,    80,    81,   129,   130,    82,   158,   159,   125,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    20,    54,    72,   107,    28,   108,   153,    11,    40,
      25,    19,     1,    27,    44,   150,    11,    45,    39,     4,
      73,    57,    76,   -13,   -13,    62,   154,   139,   155,     5,
      65,    12,     7,   -33,   168,    39,   140,    15,    16,    26,
       2,   126,   -19,    46,   -59,    47,    71,    17,   -19,    90,
       6,    92,    48,    49,    50,    45,    96,    51,   100,   102,
     103,   -14,   106,   186,   135,     8,   -14,   -14,   190,   191,
      38,   137,    56,   138,   193,   131,   132,    61,    23,   169,
      56,    46,    30,    47,    91,   106,    77,    78,    90,    32,
      48,    49,    50,   176,   164,    51,    24,   -56,    39,   -14,
     146,   -32,    41,     8,   -14,   -14,   -14,    18,   187,   -32,
       8,    17,   -14,    13,   149,    18,    30,    31,    99,   126,
      42,    30,    32,    93,    58,   177,    30,    94,    43,   151,
      90,   100,   -46,    27,    15,    16,    30,    55,   170,    90,
      39,   171,   -14,   194,    15,    16,     8,    17,    18,    59,
      93,    67,    95,    30,   136,    68,     8,    17,   -14,    69,
      13,    74,   -19,   105,    14,    83,   106,    17,   -19,    38,
      84,    15,    16,    14,   102,   103,    93,   202,    27,   -14,
      85,    15,    16,     8,    17,   -14,   156,   157,   199,   -14,
      15,    16,   -19,     8,    17,    18,    27,    17,   -14,    30,
     145,    86,     8,   -14,   -14,   -14,    88,   -19,   123,     8,
      17,   -14,    17,   -44,   124,   116,   117,   118,   119,   120,
     121,    87,    89,   127,   128,    95,    15,    16,    97,    98,
      17,    32,   110,   112,   142,   115,   134,   114,   144,   143,
     147,   161,   162,   163,   165,   166,   139,   172,   173,   174,
     179,   182,   183,   184,   185,   189,   196,   198,    29,   109,
     167,   200,   181,   133,   201,   160,   192,   203,   180
};

static const yytype_uint8 yycheck[] =
{
       7,     7,    26,    43,    68,    11,    69,   115,     4,    17,
       1,     7,     1,     1,     1,   111,    12,     4,    14,     5,
      44,    28,    46,    35,    36,    31,   122,     5,   124,     4,
       1,     5,     1,     4,   140,    31,    99,    22,    23,    30,
      29,    81,    30,    30,    31,    32,    42,    35,    36,    55,
       0,    59,    39,    40,    41,     4,    63,    44,    66,    37,
      38,    30,    68,   169,    88,    34,    35,    36,   176,   177,
       1,    95,     1,    97,   182,    83,    84,     1,     4,   142,
       1,    30,     4,    32,     5,    91,    18,    19,    94,    10,
      39,    40,    41,     1,   134,    44,     6,     5,    94,    30,
     107,    30,     4,    34,    35,    36,    30,    36,   172,    30,
      34,    35,    36,     1,   110,    36,     4,     5,     1,   159,
       5,     4,    10,     1,     6,    33,     4,     5,    12,     1,
     136,   139,     4,     1,    22,    23,     4,     5,   144,   145,
     136,   147,    30,   183,    22,    23,    34,    35,    36,     9,
       1,     8,    30,     4,     5,     5,    34,    35,    36,     8,
       1,     7,    30,     1,     5,    10,   172,    35,    36,     1,
      10,    22,    23,     5,    37,    38,     1,   201,     1,    30,
      10,    22,    23,    34,    35,    36,    20,    21,   195,    30,
      22,    23,    30,    34,    35,    36,     1,    35,    30,     4,
       5,     4,    34,    35,    36,    30,     5,    30,     4,    34,
      35,    36,    35,    36,    10,    12,    13,    14,    15,    16,
      17,    31,    31,    18,    19,    30,    22,    23,    30,    11,
      35,    10,     5,    10,     8,    43,     7,    31,     5,    11,
       5,    11,    11,    11,    31,    31,     5,     5,    11,     4,
      11,    42,    45,     5,     5,    11,     5,    42,    12,    70,
     139,   196,   160,    85,    30,   130,   180,    31,   159
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    29,    47,     5,     4,     0,     1,    34,    48,
      49,    50,     5,     1,     5,    22,    23,    35,    36,    50,
      51,    55,    85,     4,     6,     1,    30,     1,    51,    48,
       4,     5,    10,    50,    51,    53,    55,    59,     1,    50,
      53,     4,     5,    12,     1,     4,    30,    32,    39,    40,
      41,    44,    71,    72,    71,     5,     1,    55,     6,     9,
      54,     1,    51,    63,    64,     1,    60,     8,     5,     8,
      56,    50,    85,    71,     7,    74,    71,    18,    19,    75,
      77,    78,    81,    10,    10,    10,     4,    31,     5,    31,
      51,     5,    53,     1,     5,    30,    55,    30,    11,     1,
      53,    61,    37,    38,    52,     1,    51,    63,    52,    59,
       5,    73,    10,    65,    31,    43,    12,    13,    14,    15,
      16,    17,    76,     4,    10,    84,    85,    18,    19,    79,
      80,    53,    53,    75,     7,    71,     5,    71,    71,     5,
      52,    62,     8,    11,     5,     5,    55,     5,    57,    50,
      77,     1,    66,    72,    77,    77,    20,    21,    82,    83,
      81,    11,    11,    11,    85,    31,    31,    61,    62,    52,
      51,    51,     5,    11,     4,    67,     1,    33,    70,    11,
      84,    79,    42,    45,     5,     5,    62,    63,    68,    11,
      72,    72,    82,    72,    85,    58,     5,    69,    42,    55,
      67,    30,    71,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    49,    49,    49,
      50,    50,    50,    50,    50,    51,    51,    51,    51,    51,
      52,    52,    53,    54,    54,    56,    57,    58,    55,    55,
      55,    55,    55,    60,    59,    59,    59,    61,    61,    61,
      62,    62,    63,    63,    63,    64,    66,    65,    65,    65,
      68,    67,    69,    69,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    72,    73,    72,    74,    72,    72,    72,
      75,    76,    76,    76,    76,    76,    76,    76,    77,    78,
      78,    78,    79,    79,    80,    80,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     4,     3,     2,     2,     2,
       6,     4,     3,     2,     0,     6,     6,     3,     2,     0,
       1,     1,     2,     2,     0,     0,     0,     0,     9,     5,
       4,     2,     0,     0,     4,     3,     0,     4,     3,     2,
       2,     0,     5,     5,     2,     1,     0,     4,     3,     0,
       0,     3,     2,     0,     2,     2,     0,     3,     2,     0,
       4,     4,     6,     5,     0,     4,     0,     3,     3,    10,
       3,     1,     1,     1,     1,     1,     1,     0,     2,     1,
       1,     0,     3,     0,     1,     1,     3,     3,     0,     1,
       1,     1,     1,     3,     1,     1
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
#line 163 "parser.y" /* yacc.c:1646  */
    {   
                                                                                // CURR_SCOPE = 0;
                                                                                printf("IDENT: %d\n", IDENT);
                                                                                cout << "find(): "<< find(CURR_SCOPE, (yyvsp[-3].str)) << "\n";
                                                                                insert((yyvsp[-3].str), IDENT, NONE, CAT_PROGRAM_NAME, NONE, line_num, CURR_SCOPE, 0);
                                                                                cout << "find(): "<< find(CURR_SCOPE, (yyvsp[-3].str)) << "\n";
                                                                                
                                                                                printSymbolTable();
                                                                            }
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 173 "parser.y" /* yacc.c:1646  */
    {;}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 177 "parser.y" /* yacc.c:1646  */
    {;}
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 178 "parser.y" /* yacc.c:1646  */
    {;}
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 182 "parser.y" /* yacc.c:1646  */
    {;}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 183 "parser.y" /* yacc.c:1646  */
    {;}
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 184 "parser.y" /* yacc.c:1646  */
    {;}
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 185 "parser.y" /* yacc.c:1646  */
    {;}
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 189 "parser.y" /* yacc.c:1646  */
    {
                                                                               // printf("numero: %s\n", $4);
                                                                                insert((yyvsp[-4].str), IDENT, t_type, CAT_CONSTANT, t_num, line_num, CURR_SCOPE, 0);
                                                                                printSymbolTable();
                                                                            }
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 194 "parser.y" /* yacc.c:1646  */
    {;}
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 195 "parser.y" /* yacc.c:1646  */
    {;}
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 196 "parser.y" /* yacc.c:1646  */
    {;}
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 197 "parser.y" /* yacc.c:1646  */
    {;}
#line 1697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 201 "parser.y" /* yacc.c:1646  */
    {;}
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 202 "parser.y" /* yacc.c:1646  */
    {;}
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 203 "parser.y" /* yacc.c:1646  */
    {;}
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 204 "parser.y" /* yacc.c:1646  */
    {;}
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 205 "parser.y" /* yacc.c:1646  */
    {;}
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 209 "parser.y" /* yacc.c:1646  */
    {
                                                                                t_type = REAL_TYPE;
                                                                                for (int i=0; i < t_cadeias.size(); i++) { // for each variable in the list
                                                                                    if (find(CURR_SCOPE, t_cadeias[i])){
                                                                                        cout << "[Erro] Linha "<< line_num <<": a variável '"<< t_cadeias[i] <<"' foi declarada mais de uma vez.\n";
                                                                                    } else {
                                                                                        if (is_procedure) {
                                                                                            if (is_valid_procedure) {
                                                                                                insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                            }
                                                                                        } else {
                                                                                            insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                        }
                                                                                        // insert procedure parameter intro procParams
                                                                                        // TODO copiar isso pro INTEGER tbm !!!
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";
                                                                                        }
                                                                                    }
                                                                                }
                                                                                t_cadeias.clear();
                                                                            }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 237 "parser.y" /* yacc.c:1646  */
    {
                                                                                t_type = INT_TYPE;
                                                                                for (int i=0; i < t_cadeias.size(); i++) {
                                                                                    if (find(CURR_SCOPE, t_cadeias[i])){
                                                                                        cout << "[Erro] Linha "<< line_num <<": a variável '"<< t_cadeias[i] <<"' foi declarada mais de uma vez.\n";
                                                                                    } else {
                                                                                        if (is_procedure) {
                                                                                            if (is_valid_procedure) {
                                                                                                insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                            }
                                                                                        } else {
                                                                                            insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                        }
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            // pair<string, vector<Element> > item ();
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";

                                                                                        }
                                                                                    }
                                                                                }
                                                                                t_cadeias.clear();
                                                                            }
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 268 "parser.y" /* yacc.c:1646  */
    {
                                                                                if(DEBUG) cout << "inseriu " << (yyvsp[-1].str) << " em t_cadeias\n";
                                                                                t_cadeias.push_back((yyvsp[-1].str));
                                                                            }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 275 "parser.y" /* yacc.c:1646  */
    {;}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 276 "parser.y" /* yacc.c:1646  */
    {;}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 280 "parser.y" /* yacc.c:1646  */
    { 
                                                                                t_cadeias.clear();
                                                                                if (!find(CURR_SCOPE, (yyvsp[0].str))) {
                                                                                    insert((yyvsp[0].str), IDENT, NONE, CAT_PROCEDURE, NONE, line_num, CURR_SCOPE, 0);
                                                                                    
                                                                                    curr_proc_name = (yyvsp[0].str); //For control purpose: current procedure name
                                                                                    
                                                                                    vector<Element> v;
                                                                                    pair<string, vector<Element> > item ((yyvsp[0].str), v);
                                                                                    procParams.insert(item);
                                                                                    
                                                                                    is_valid_procedure = true;
                                                                                } else {
                                                                                    cout << MSG_BEGIN_ERROR << line_num <<": procedimento declarado mais de uma vez.\n";
                                                                                    is_valid_procedure = false;
                                                                                }
                                                                                CURR_SCOPE++;
                                                                                is_proc_parameter = true;
                                                                                is_procedure = true;
                                                                            }
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 300 "parser.y" /* yacc.c:1646  */
    {
                                                                                is_proc_parameter = false;
                                                                                printProcParameters(curr_proc_name);
                                                                            }
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 305 "parser.y" /* yacc.c:1646  */
    {
                                                                                // TODO delete the symbolTable from the CURR_SCOPE
                                                                                CURR_SCOPE--;
                                                                                is_procedure = false;
                                                                            }
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 311 "parser.y" /* yacc.c:1646  */
    {
                                                                                printf(" +++++ REGRA 9\n");
                                                                                // TODO atualizar numParams do procedimento na symbolTable!!
                                                                                int numParams = getNumberOfParams((yyvsp[-7].str));
                                                                                
                                                                            }
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 317 "parser.y" /* yacc.c:1646  */
    {;}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 318 "parser.y" /* yacc.c:1646  */
    {;}
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 319 "parser.y" /* yacc.c:1646  */
    {;}
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 320 "parser.y" /* yacc.c:1646  */
    {;}
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 324 "parser.y" /* yacc.c:1646  */
    { t_cadeias.clear(); }
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 325 "parser.y" /* yacc.c:1646  */
    {; }
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 326 "parser.y" /* yacc.c:1646  */
    {;}
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 327 "parser.y" /* yacc.c:1646  */
    {;}
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 331 "parser.y" /* yacc.c:1646  */
    {; }
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 332 "parser.y" /* yacc.c:1646  */
    {;}
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 333 "parser.y" /* yacc.c:1646  */
    {;}
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 337 "parser.y" /* yacc.c:1646  */
    {;}
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 338 "parser.y" /* yacc.c:1646  */
    {;}
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 342 "parser.y" /* yacc.c:1646  */
    {;}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 343 "parser.y" /* yacc.c:1646  */
    {;}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 344 "parser.y" /* yacc.c:1646  */
    {;}
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 348 "parser.y" /* yacc.c:1646  */
    {;}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 352 "parser.y" /* yacc.c:1646  */
    {
                                                                                t_type.clear();
                                                                            }
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 355 "parser.y" /* yacc.c:1646  */
    {;}
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 356 "parser.y" /* yacc.c:1646  */
    {;}
#line 1991 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 357 "parser.y" /* yacc.c:1646  */
    {;}
#line 1997 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 361 "parser.y" /* yacc.c:1646  */
    {
                                                                                if(find((yyvsp[0].str), CAT_VARIABLE)){
                                                                                    // t_type.push_back(getType($1, CAT_VARIABLE));// TODO
                                                                                } else {
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": " << (yyvsp[0].str) << " não foi declarado.\n";
                                                                                }
                                                                            }
#line 2009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 368 "parser.y" /* yacc.c:1646  */
    {;}
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 372 "parser.y" /* yacc.c:1646  */
    {;}
#line 2021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 373 "parser.y" /* yacc.c:1646  */
    {;}
#line 2027 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 377 "parser.y" /* yacc.c:1646  */
    {;}
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 378 "parser.y" /* yacc.c:1646  */
    {;}
#line 2039 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 379 "parser.y" /* yacc.c:1646  */
    {;}
#line 2045 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 383 "parser.y" /* yacc.c:1646  */
    {;}
#line 2051 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 384 "parser.y" /* yacc.c:1646  */
    {;}
#line 2057 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 385 "parser.y" /* yacc.c:1646  */
    {;}
#line 2063 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 395 "parser.y" /* yacc.c:1646  */
    {;}
#line 2069 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 396 "parser.y" /* yacc.c:1646  */
    {;}
#line 2075 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 397 "parser.y" /* yacc.c:1646  */
    {;}
#line 2081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 398 "parser.y" /* yacc.c:1646  */
    {;}
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 399 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (!find((yyvsp[-1].str), CAT_VARIABLE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << " variável não declarada.\n";
                                                                                }
                                                                            }
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 404 "parser.y" /* yacc.c:1646  */
    {;}
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 405 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (!find((yyvsp[0].str), CAT_PROCEDURE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << " procedimento não declarado.\n";
                                                                                }
                                                                            }
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 410 "parser.y" /* yacc.c:1646  */
    {;}
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 411 "parser.y" /* yacc.c:1646  */
    {;}
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 412 "parser.y" /* yacc.c:1646  */
    {;}
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 416 "parser.y" /* yacc.c:1646  */
    {;}
#line 2137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 420 "parser.y" /* yacc.c:1646  */
    {;}
#line 2143 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 421 "parser.y" /* yacc.c:1646  */
    {;}
#line 2149 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 422 "parser.y" /* yacc.c:1646  */
    {;}
#line 2155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 423 "parser.y" /* yacc.c:1646  */
    {;}
#line 2161 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 424 "parser.y" /* yacc.c:1646  */
    {;}
#line 2167 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 425 "parser.y" /* yacc.c:1646  */
    {;}
#line 2173 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 426 "parser.y" /* yacc.c:1646  */
    {;}
#line 2179 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 430 "parser.y" /* yacc.c:1646  */
    {;}
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 434 "parser.y" /* yacc.c:1646  */
    {;}
#line 2191 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 435 "parser.y" /* yacc.c:1646  */
    {;}
#line 2197 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 436 "parser.y" /* yacc.c:1646  */
    {;}
#line 2203 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 440 "parser.y" /* yacc.c:1646  */
    {;}
#line 2209 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 441 "parser.y" /* yacc.c:1646  */
    {;}
#line 2215 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 445 "parser.y" /* yacc.c:1646  */
    {;}
#line 2221 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 446 "parser.y" /* yacc.c:1646  */
    {;}
#line 2227 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 450 "parser.y" /* yacc.c:1646  */
    {;}
#line 2233 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 454 "parser.y" /* yacc.c:1646  */
    {;}
#line 2239 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 455 "parser.y" /* yacc.c:1646  */
    {;}
#line 2245 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 459 "parser.y" /* yacc.c:1646  */
    {;}
#line 2251 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 460 "parser.y" /* yacc.c:1646  */
    {;}
#line 2257 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 464 "parser.y" /* yacc.c:1646  */
    {;}
#line 2263 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 465 "parser.y" /* yacc.c:1646  */
    {;}
#line 2269 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 466 "parser.y" /* yacc.c:1646  */
    {;}
#line 2275 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 470 "parser.y" /* yacc.c:1646  */
    {
                                                                                // printf("val: %s, text: %s\n", yylval, yytext);
                                                                                t_num = yylval.str;
                                                                                t_type = INT_TYPE;
                                                                            }
#line 2285 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 475 "parser.y" /* yacc.c:1646  */
    {
                                                                                t_num = yylval.str;
                                                                                t_type = REAL_TYPE;
                                                                            }
#line 2294 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2298 "parser.tab.c" /* yacc.c:1646  */
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
#line 481 "parser.y" /* yacc.c:1906  */


/**/


int main(int argc, char const *argv[]){

    m["IDENT"] = "identificador";
    m["SEMICOLON"] = ";";
    m["ENDPOINT"] = ".";
    m["ATTRIBUTION"] = ":=";
    m["CONST"] = "const";
    m["COLON"] = ":";
    m["COMMA"] = ",";
    m["OPEN_PAR"] = "(";
    m["CLOSE_PAR"] = ")";
    m["EQUAL"] = "=";
    m["DIF"] = "<>";
    m["GREATER_EQUAL"] = ">=";
    m["LESSER_EQUAL"] = "<=";
    m["GREATER"] = ">";
    m["LESSER"] = "<";
    m["PLUS"] = "+";
    m["MINUS"] = "-";
    m["MULT"] = "*";
    m["DIV"] = "/";
    m["INTEGER_NUMBER"] = "numero inteiro";
    m["REAL_NUMBER"] = "numero real";
    m["INTEGER"] = "integer";
    m["REAL"] = "real";
    m["PROGRAM"] = "program";
    m["BEG"] = "begin";
    m["END"] = "end";
    m["IF"] = "if";
    m["ELSE"] = "else";
    m["CONST"] = "const";
    m["VAR"] = "var";
    m["PROCEDURE"] = "procedure";
    m["READ"] = "read";
    m["WRITE"] = "write";
    m["WHILE"] = "while";
    m["DO"] = "do";
    m["THEN"] = "then";
    m["FOR"] = "for";
    m["TO"] = "to";
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
    string tmp = str;
    if (tmp.find("syntax error") != string::npos)
    {
        string strS = str;
        int pos = strS.find("expecting");
        pos += 10;
        string expected;
        bool test = false;
        string word;
        while (pos < strS.size())
        {

            if (expected.size() && !test)
            {
                test = true;
                expected += " (Note que ";
            }
            else if (expected.size())
            {
                expected += ", ";
            }
            while (pos < strS.size() && strS[pos] != ' ')
            {
                word += strS[pos];
                pos++;
            }
            expected += "\"";
            expected += m[word];
            expected += "\"";
            word.clear();
            pos += 4;
        }

        if (test)
        {
            expected += " também são opções validas )";
        }

        printf("Linha %d: Esperava-se encontrar %s porém encontrou-se '%s'\n", line_num, expected.c_str(), yylval.str); // qq coisa mudar yylval para yytext
    }
    else
    {
        printf("%s\n",str);
    }
}


/*****************************************************************************************
                
                            Symbol Table functions 

*****************************************************************************************/

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope, int numParams) {
    if(DEBUG) cout << " >> Inserindo cadeia: " << cadeia << " | token: " << token << " | type: " << type << " | cat: " << cat << " | val: " << val << " | line: " << line << " | scope: " << scope << "\n";
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
    elem.cadeia     = cadeia;
    elem.token      = token;
    elem.type       = type;
    elem.cat        = cat;
    elem.val        = val;
    elem.line       = line;
    elem.scope      = scope;
    elem.numParams  = numParams;
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

// Search into the current scope and in the global scope (0)
bool find(string cadeia, string category) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;
    it1 = symbolTableVector.find(CURR_SCOPE);

    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            if (it2->second.cat == category) {
                return true;
            }
        }
    }
    return false;
}


bool updateType(vector<string> cadeia, string type, int scope) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;
    it1 = symbolTableVector.find(scope);

    if (it1 != symbolTableVector.end()) {
        for (int i = 0; i < cadeia.size(); i++) {
            cout << " >> CADEIA: " << cadeia[i] << "\n";
            it2 = it1->second.find(cadeia[i]);
            if (it2 != it1->second.end()){
                printf("ATUALIZOU TIPO DE : %s   PARA : %s\n", cadeia[i].c_str(), type.c_str());
                it2->second.type = type;
            }
        }
        return true;
    }
    return false;
}

int getNumberOfParams(string procName) {
    unordered_map<string, vector<Element> >::iterator it;
    it = procParams.find(procName);
    if (it != procParams.end())
        return it->second.size();
    return 0;
}

void printProcParameters(string procName) {
    unordered_map<string, vector<Element> >::iterator it;
    it = procParams.find(procName);
    if (it != procParams.end()){
        cout << " >> Parameters of the procedure " << procName << "\n";
        for (int i = 0; i < it->second.size(); i++) {
            cout << "\tcadeia: " << it->second[i].cadeia << " , type: " << it->second[i].type << "\n";
        }
    }
}

// Search into the current scope and in the global scope (0)
string getType(string cadeia, string category) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;
    it1 = symbolTableVector.find(CURR_SCOPE);

    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            if (it2->second.cat == category) {
                return it2->second.type;
            }
        }
    }
    return NULL;
}

// Search into the current scope and in the global scope (0)
Element getElement(string cadeia){
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;

    it1 = symbolTableVector.find(CURR_SCOPE);
    if (it1 != symbolTableVector.end()){
        it2 = it1->second.find(cadeia);
        if(it2 != it1->second.end()){
            return it2->second;
        } else {
            // seach in the global scope:
            it1 = symbolTableVector.find(0);
            if (it1 != symbolTableVector.end()){
                it2 = it1->second.find(cadeia);
                if (it2 != it1->second.end()){
                    return it2->second;
                }
            }
        }

    }
    // return NULL;
}


// Check if the number of parameters is right and the type of the parameters
// void checkProcedureParameters(string procName, ) {

// }
/*****************************************************************************************/
