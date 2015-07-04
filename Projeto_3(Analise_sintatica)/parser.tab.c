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
#line 11 "parser.y" /* yacc.c:339  */

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
string tmp;
string tmp2;


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

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope, int numParams);
bool find(int scope, string cadeia);
bool updateType(vector<string> cadeia, string type, int scope);
void printSymbolTable();
void printProcParameters(string procName);
bool find(string cadeia, string category);
string getType(string cadeia, string category);
void checkProcedureParameters(string procName, vector<string> types);

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
vector<string> t_type_params;
vector<string> t_cadeias;
string t_var_type;

/****************************************
|       Parameters of the Procedures    |
****************************************/
unordered_map<string, vector<Element> > procParams;
string curr_proc_name;

/****************************************
|           Control Flags               |
****************************************/
bool is_proc_parameter  = false;
bool is_valid_procedure = false;
bool is_procedure       = false;
bool is_division        = false;
bool check_var_type     = false;
bool has_diff_type      = false;

string MSG_BEGIN_ERROR = "[Erro] Linha ";
/*****************************************************************************************/

map<string, string> m;


#line 174 "parser.tab.c" /* yacc.c:339  */

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
#line 122 "parser.y" /* yacc.c:355  */

    int numi;
    float numf;
    char *str;

#line 266 "parser.tab.c" /* yacc.c:355  */
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

#line 295 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   269

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       0,   179,   179,   179,   185,   189,   190,   194,   195,   196,
     197,   201,   205,   206,   207,   208,   212,   213,   214,   215,
     216,   220,   248,   279,   279,   301,   302,   306,   326,   331,
     306,   344,   345,   346,   347,   351,   351,   353,   354,   358,
     359,   360,   364,   365,   369,   370,   371,   375,   379,   379,
     383,   384,   388,   388,   400,   401,   405,   406,   407,   411,
     412,   413,   423,   423,   436,   436,   449,   450,   451,   451,
     467,   475,   476,   480,   484,   485,   486,   487,   488,   489,
     490,   494,   498,   499,   500,   504,   505,   509,   510,   514,
     518,   529,   533,   534,   538,   557,   558,   562,   573
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
  "$accept", "programa", "$@1", "corpo", "dc", "dc_c", "dc_v", "tipo_var",
  "variaveis", "$@2", "mais_var", "dc_p", "$@3", "$@4", "$@5",
  "parametros", "$@6", "lista_par", "mais_par", "corpo_p", "dc_loc",
  "lista_arg", "$@7", "argumentos", "$@8", "mais_ident", "pfalsa",
  "comandos", "cmd", "$@9", "$@10", "$@11", "condicao", "relacao",
  "expressao", "op_un", "outros_termos", "op_ad", "termo", "mais_fatores",
  "op_mul", "fator", "numero", YY_NULLPTR
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

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    12,    20,    38,    53,  -114,  -114,   162,    39,    68,
      35,    62,    79,   102,   180,  -114,  -114,    89,    97,   -20,
    -114,  -114,   104,   114,  -114,    27,    27,     9,    26,    53,
    -114,   189,    22,  -114,  -114,   120,  -114,   125,   172,  -114,
     131,  -114,   180,    56,    27,    84,    27,    95,   137,   139,
     145,   147,   128,   157,   140,    62,   181,  -114,   199,   200,
     130,  -114,    26,   188,   201,    28,   141,    18,   141,   203,
    -114,   215,  -114,  -114,    33,  -114,   190,  -114,  -114,   179,
     223,   146,   182,  -114,  -114,    95,   219,  -114,    27,  -114,
    -114,    18,  -114,    89,  -114,   153,   198,    27,  -114,    27,
    -114,    67,   221,   216,  -114,  -114,   225,    46,  -114,    26,
     226,  -114,   180,    95,   230,   238,  -114,    78,  -114,  -114,
    -114,  -114,  -114,  -114,    95,  -114,    95,   183,  -114,  -114,
    -114,  -114,    95,    89,    89,   232,    56,  -114,  -114,   198,
     213,   214,    28,   241,  -114,   141,  -114,    62,   110,  -114,
      62,   242,  -114,  -114,  -114,  -114,   237,    94,  -114,   239,
    -114,  -114,  -114,   146,   182,   240,   243,   207,   208,   247,
     250,  -114,  -114,   241,  -114,  -114,    18,   251,  -114,    78,
      78,  -114,  -114,   183,  -114,  -114,  -114,    78,    56,  -114,
    -114,  -114,  -114,   238,  -114,  -114,  -114,  -114,  -114,   217,
      26,  -114,   227,  -114,    27,   229,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     1,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,     0,     0,     9,
       8,    10,     0,     0,     4,     0,     0,     0,     0,     0,
      23,     0,     0,    14,    19,     0,    33,     0,     0,    13,
       0,    27,     0,     0,     0,    51,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,    26,
       0,    18,     0,     0,     0,     0,     0,     0,     0,    38,
      12,     0,    60,    68,     0,    70,     0,    82,    83,     0,
      80,     0,    86,    62,    64,    84,     0,     6,     0,     5,
      18,     0,     3,     0,    24,     0,     0,     0,    32,     0,
      37,    43,     0,     0,    21,    22,     0,     0,    47,     0,
       0,    28,     0,    84,     0,     0,    71,     0,    74,    75,
      76,    77,    78,    79,    84,    94,    84,    91,    95,    87,
      88,    81,    84,     0,     0,     0,     0,    59,    25,     0,
       0,     0,     0,    43,    41,     0,    36,     0,     0,    31,
       0,     0,    11,    69,    50,    52,     0,     0,    73,     0,
      92,    93,    89,     0,    86,     0,     0,     0,     0,     0,
       0,    42,    40,    43,    17,    16,     0,    55,    49,     0,
       0,    67,    96,    91,    85,    63,    65,     0,     0,    45,
      44,    39,    29,     0,    53,    57,    56,    90,    66,     0,
       0,    54,     0,    30,     0,     0,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,   233,  -114,     4,    -6,   -59,   -13,  -114,
    -114,    -7,  -114,  -114,  -114,   192,  -114,   116,  -113,   -61,
    -114,  -114,  -114,    70,  -114,  -114,  -114,   -24,  -110,  -114,
    -114,  -114,   184,  -114,    48,  -114,   100,  -114,   133,    83,
    -114,   105,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    12,     9,    10,    33,    34,   106,    35,    59,
      94,    36,    69,   151,   200,    37,    65,   103,   144,    62,
      63,    75,   115,   156,   177,   194,   181,    52,    53,   133,
     134,   113,    79,   124,    80,    81,   131,   132,    82,   162,
     163,   127,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    20,    54,    71,    40,    28,   109,   157,    11,   110,
      27,    19,     1,    30,    55,   -14,   -14,     4,    39,   107,
      72,    57,    76,    64,     5,    61,   -35,    56,    44,   101,
     172,    45,    30,    11,   114,    39,    25,   -48,     6,   -20,
       2,   128,   143,    23,    17,   -20,    70,    27,   -20,    90,
      30,   148,   102,    17,     7,    98,   -34,    46,   -61,    47,
     191,   108,    18,    27,   137,    26,    48,    49,    50,   195,
     196,    51,   142,   140,    24,   141,    97,   198,    15,    16,
     138,    17,    45,   -15,    29,   108,   173,     8,   -15,   -15,
      90,    73,   -20,    30,    74,   179,   168,    17,   -20,   -58,
      39,    41,   149,    13,   104,   105,    30,    31,    46,    42,
      47,    27,    32,    77,    78,   192,   152,    48,    49,    50,
     165,   166,    51,   128,    15,    16,    43,   180,    66,   102,
      67,    95,   -15,    90,    30,    96,     8,    17,    18,    68,
     -20,   174,    90,    39,   175,    17,   -46,    83,   199,    84,
     125,    86,    15,    16,    95,    85,   126,    30,   139,    87,
      97,   153,    88,    13,     8,    17,   -15,    14,    15,    16,
     108,    89,   158,    38,   159,    15,    16,    14,   104,   105,
     205,    38,    56,   -15,    15,    16,    91,     8,    17,   -15,
      60,    32,   -15,   203,    15,    16,     8,    17,    18,    95,
     129,   130,   -15,   160,   161,    92,     8,   -15,   -15,    93,
     -15,   -34,   100,    32,     8,   -15,   -15,    18,    99,   -15,
     112,   116,   117,     8,    17,   -15,   136,   146,   -15,   145,
     147,   150,     8,    17,   -15,   118,   119,   120,   121,   122,
     123,   154,   155,   167,   169,   170,   142,   176,   178,   187,
     182,   185,   189,   188,   186,   190,   193,   204,   171,   202,
     206,   111,    58,   201,   184,   164,   197,     0,   183,   135
};

static const yytype_int16 yycheck[] =
{
       7,     7,    26,    43,    17,    11,    67,   117,     4,    68,
       1,     7,     1,     4,     5,    35,    36,     5,    14,     1,
      44,    28,    46,     1,     4,    31,     4,     1,     1,     1,
     143,     4,     4,    29,     1,    31,     1,     4,     0,    30,
      29,    81,   101,     4,    35,    36,    42,     1,    30,    55,
       4,     5,    65,    35,     1,    62,    30,    30,    31,    32,
     173,    67,    36,     1,    88,    30,    39,    40,    41,   179,
     180,    44,     5,    97,     6,    99,    30,   187,    22,    23,
      93,    35,     4,    30,     5,    91,   145,    34,    35,    36,
      96,     7,    30,     4,    10,     1,   136,    35,    36,     5,
      96,     4,   109,     1,    37,    38,     4,     5,    30,     5,
      32,     1,    10,    18,    19,   176,   112,    39,    40,    41,
     133,   134,    44,   163,    22,    23,    12,    33,     8,   142,
       5,     1,    30,   139,     4,     5,    34,    35,    36,     8,
      30,   147,   148,   139,   150,    35,    36,    10,   188,    10,
       4,     4,    22,    23,     1,    10,    10,     4,     5,    31,
      30,   113,     5,     1,    34,    35,    36,     5,    22,    23,
     176,    31,   124,     1,   126,    22,    23,     5,    37,    38,
     204,     1,     1,    30,    22,    23,     5,    34,    35,    36,
       1,    10,    30,   200,    22,    23,    34,    35,    36,     1,
      18,    19,    30,    20,    21,     6,    34,    35,    36,     9,
      30,    30,    11,    10,    34,    35,    36,    36,    30,    30,
       5,    31,    43,    34,    35,    36,     7,    11,    30,     8,
       5,     5,    34,    35,    36,    12,    13,    14,    15,    16,
      17,    11,     4,    11,    31,    31,     5,     5,    11,    42,
      11,    11,     5,    45,    11,     5,     5,    30,   142,    42,
      31,    69,    29,   193,   164,   132,   183,    -1,   163,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    29,    47,     5,     4,     0,     1,    34,    49,
      50,    51,    48,     1,     5,    22,    23,    35,    36,    51,
      52,    57,    88,     4,     6,     1,    30,     1,    52,     5,
       4,     5,    10,    51,    52,    54,    57,    61,     1,    51,
      54,     4,     5,    12,     1,     4,    30,    32,    39,    40,
      41,    44,    73,    74,    73,     5,     1,    57,    49,    55,
       1,    52,    65,    66,     1,    62,     8,     5,     8,    58,
      51,    88,    73,     7,    10,    67,    73,    18,    19,    78,
      80,    81,    84,    10,    10,    10,     4,    31,     5,    31,
      52,     5,     6,     9,    56,     1,     5,    30,    57,    30,
      11,     1,    54,    63,    37,    38,    53,     1,    52,    65,
      53,    61,     5,    77,     1,    68,    31,    43,    12,    13,
      14,    15,    16,    17,    79,     4,    10,    87,    88,    18,
      19,    82,    83,    75,    76,    78,     7,    73,    54,     5,
      73,    73,     5,    53,    64,     8,    11,     5,     5,    57,
       5,    59,    51,    80,    11,     4,    69,    74,    80,    80,
      20,    21,    85,    86,    84,    54,    54,    11,    88,    31,
      31,    63,    64,    53,    52,    52,     5,    70,    11,     1,
      33,    72,    11,    87,    82,    11,    11,    42,    45,     5,
       5,    64,    65,     5,    71,    74,    74,    85,    74,    88,
      60,    69,    42,    57,    30,    73,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    48,    47,    47,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    55,    54,    56,    56,    58,    59,    60,
      57,    57,    57,    57,    57,    62,    61,    61,    61,    63,
      63,    63,    64,    64,    65,    65,    65,    66,    68,    67,
      67,    67,    70,    69,    71,    71,    72,    72,    72,    73,
      73,    73,    75,    74,    76,    74,    74,    74,    77,    74,
      74,    74,    74,    78,    79,    79,    79,    79,    79,    79,
      79,    80,    81,    81,    81,    82,    82,    83,    83,    84,
      85,    85,    86,    86,    87,    87,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     4,     4,     4,     3,     2,     2,
       2,     6,     4,     3,     2,     0,     6,     6,     3,     2,
       0,     1,     1,     0,     3,     2,     0,     0,     0,     0,
       9,     5,     4,     2,     0,     0,     4,     3,     0,     4,
       3,     2,     2,     0,     5,     5,     2,     1,     0,     4,
       3,     0,     0,     3,     2,     0,     2,     2,     0,     3,
       2,     0,     0,     5,     0,     5,     6,     5,     0,     4,
       2,     3,    10,     3,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     0,     3,     0,     1,     1,     3,
       3,     0,     1,     1,     1,     1,     3,     1,     1
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
#line 179 "parser.y" /* yacc.c:1646  */
    {
                                                                                insert((yyvsp[0].str), IDENT, NONE, CAT_PROGRAM_NAME, NONE, line_num, CURR_SCOPE, 0);                                                                                
                                                                                if (DEBUG) printSymbolTable();
                                                                            }
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 183 "parser.y" /* yacc.c:1646  */
    {;}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 185 "parser.y" /* yacc.c:1646  */
    {;}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 189 "parser.y" /* yacc.c:1646  */
    {;}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 190 "parser.y" /* yacc.c:1646  */
    {;}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 194 "parser.y" /* yacc.c:1646  */
    {;}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 195 "parser.y" /* yacc.c:1646  */
    {;}
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 196 "parser.y" /* yacc.c:1646  */
    {;}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 197 "parser.y" /* yacc.c:1646  */
    {;}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 201 "parser.y" /* yacc.c:1646  */
    {
                                                                                insert((yyvsp[-4].str), IDENT, t_type, CAT_CONSTANT, t_num, line_num, CURR_SCOPE, 0);
                                                                                if (DEBUG) printSymbolTable();
                                                                            }
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 205 "parser.y" /* yacc.c:1646  */
    {;}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 206 "parser.y" /* yacc.c:1646  */
    {;}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 207 "parser.y" /* yacc.c:1646  */
    {;}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 208 "parser.y" /* yacc.c:1646  */
    {;}
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 212 "parser.y" /* yacc.c:1646  */
    {;}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 213 "parser.y" /* yacc.c:1646  */
    {;}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 214 "parser.y" /* yacc.c:1646  */
    {;}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 215 "parser.y" /* yacc.c:1646  */
    {;}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 216 "parser.y" /* yacc.c:1646  */
    {;}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 220 "parser.y" /* yacc.c:1646  */
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
                                                                                        // insert procedure parameter into the procParams
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            if(DEBUG) cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";
                                                                                        }
                                                                                    }
                                                                                }
                                                                                t_cadeias.clear();
                                                                            
                                                                            }
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 248 "parser.y" /* yacc.c:1646  */
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
                                                                                        // insert procedure parameter into the procParams
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            if (DEBUG) cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";

                                                                                        }
                                                                                    }
                                                                                }
                                                                                t_cadeias.clear();
                                                                            }
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 279 "parser.y" /* yacc.c:1646  */
    {
                                                                                if(check_var_type){ /* The variable is already declared */
                                                                                    if(find((yyvsp[0].str), CAT_VARIABLE)){
                                                                                        if (t_var_type == NONE){
                                                                                            t_var_type = getType((yyvsp[0].str), CAT_VARIABLE);
                                                                                        } else {
                                                                                            if (t_var_type != getType((yyvsp[0].str), CAT_VARIABLE)){
                                                                                                has_diff_type = true;
                                                                                            }
                                                                                        }
                                                                                    } else {
                                                                                        cout << MSG_BEGIN_ERROR << line_num << ": variável '"<< (yyvsp[0].str) <<"' não declarada ou '"<< (yyvsp[0].str) <<"' não é do tipo variável.\n";                                 
                                                                                    }
                                                                                }
                                                                            }
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 294 "parser.y" /* yacc.c:1646  */
    {
                                                                                if(DEBUG) cout << "inseriu " << (yyvsp[-2].str) << " em t_cadeias\n";
                                                                                t_cadeias.push_back((yyvsp[-2].str));
                                                                            }
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 301 "parser.y" /* yacc.c:1646  */
    {;}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 302 "parser.y" /* yacc.c:1646  */
    {;}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 306 "parser.y" /* yacc.c:1646  */
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
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 326 "parser.y" /* yacc.c:1646  */
    {
                                                                                is_proc_parameter = false;
                                                                                if (DEBUG) printProcParameters(curr_proc_name);
                                                                            }
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 331 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (DEBUG) printSymbolTable();
                                                                                if (DEBUG) cout << " ! REMOVING SCOPE " << CURR_SCOPE << "\n";
                                                                                
                                                                                // Delete the symbol Table from the CURR_SCOPE
                                                                                symbolTableVector.erase(CURR_SCOPE);

                                                                                if (DEBUG) printSymbolTable();
                                                                                CURR_SCOPE--;
                                                                                is_procedure = false;
                                                                            }
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 343 "parser.y" /* yacc.c:1646  */
    {;}
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 344 "parser.y" /* yacc.c:1646  */
    {;}
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 345 "parser.y" /* yacc.c:1646  */
    {;}
#line 1912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 346 "parser.y" /* yacc.c:1646  */
    {;}
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 347 "parser.y" /* yacc.c:1646  */
    {;}
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 351 "parser.y" /* yacc.c:1646  */
    { t_cadeias.clear(); }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 352 "parser.y" /* yacc.c:1646  */
    {; }
#line 1936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 353 "parser.y" /* yacc.c:1646  */
    {;}
#line 1942 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 354 "parser.y" /* yacc.c:1646  */
    {;}
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 358 "parser.y" /* yacc.c:1646  */
    {;}
#line 1954 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 359 "parser.y" /* yacc.c:1646  */
    {;}
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 360 "parser.y" /* yacc.c:1646  */
    {;}
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 364 "parser.y" /* yacc.c:1646  */
    {;}
#line 1972 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 365 "parser.y" /* yacc.c:1646  */
    {;}
#line 1978 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 369 "parser.y" /* yacc.c:1646  */
    {;}
#line 1984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 370 "parser.y" /* yacc.c:1646  */
    {;}
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 371 "parser.y" /* yacc.c:1646  */
    {;}
#line 1996 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 375 "parser.y" /* yacc.c:1646  */
    {;}
#line 2002 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 379 "parser.y" /* yacc.c:1646  */
    {
                                                                                t_type_params.clear();
                                                                            }
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 382 "parser.y" /* yacc.c:1646  */
    {;}
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 383 "parser.y" /* yacc.c:1646  */
    {;}
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 384 "parser.y" /* yacc.c:1646  */
    {;}
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 388 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (DEBUG) printSymbolTable();
                                                                                if(find((yyvsp[0].str), CAT_VARIABLE)){
                                                                                    t_type_params.push_back(getType((yyvsp[0].str), CAT_VARIABLE)); // TODO
                                                                                } else {
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": '" << (yyvsp[0].str) << "' não foi declarado.\n";
                                                                                }
                                                                            }
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 396 "parser.y" /* yacc.c:1646  */
    {;}
#line 2047 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 400 "parser.y" /* yacc.c:1646  */
    {;}
#line 2053 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 401 "parser.y" /* yacc.c:1646  */
    {;}
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 405 "parser.y" /* yacc.c:1646  */
    {;}
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 406 "parser.y" /* yacc.c:1646  */
    {;}
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 407 "parser.y" /* yacc.c:1646  */
    {;}
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 411 "parser.y" /* yacc.c:1646  */
    {;}
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 412 "parser.y" /* yacc.c:1646  */
    {;}
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 413 "parser.y" /* yacc.c:1646  */
    {;}
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 423 "parser.y" /* yacc.c:1646  */
    { 
                                                                                t_var_type = NONE;
                                                                                check_var_type = true;
                                                                                has_diff_type  = false; 
                                                                            }
#line 2105 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 428 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (has_diff_type){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": comando 'read' apresenta variáveis de tipos diferentes.\n";
                                                                                }
                                                                                check_var_type = false;
                                                                                has_diff_type  = false; 
                                                                                t_var_type = NONE;
                                                                            }
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 436 "parser.y" /* yacc.c:1646  */
    {
                                                                                t_var_type = NONE;
                                                                                check_var_type = true;
                                                                                has_diff_type  = false; 
                                                                            }
#line 2128 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 441 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (has_diff_type){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": comando 'write' apresenta variáveis de tipos diferentes.\n";
                                                                                }
                                                                                check_var_type = false;
                                                                                has_diff_type  = false; 
                                                                                t_var_type = NONE;
                                                                            }
#line 2141 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 449 "parser.y" /* yacc.c:1646  */
    {;}
#line 2147 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 450 "parser.y" /* yacc.c:1646  */
    {;}
#line 2153 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 451 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (!find((yyvsp[-1].str), CAT_VARIABLE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": variável '"<< (yyvsp[-1].str) <<"' não declarada ou fora do escopo.\n";
                                                                                }
                                                                            }
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 456 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (find((yyvsp[-3].str), CAT_VARIABLE))
                                                                                {
                                                                                    string type = getType((yyvsp[-3].str), CAT_VARIABLE);
                                                                                    if (type == INT_TYPE && tmp == REAL_TYPE)
                                                                                    {
                                                                                        cout << MSG_BEGIN_ERROR << line_num << ": Possivel perda de precisão devido a atribuição de um real para um inteiro.\n";
                                                                                    }
                                                                                }
                                                                                tmp.clear();
                                                                            }
#line 2179 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 467 "parser.y" /* yacc.c:1646  */
    {
                                                                                /* Procedure */
                                                                                if (!find((yyvsp[-1].str), CAT_PROCEDURE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": procedimento '"<< (yyvsp[-1].str) <<"' não declarado.\n";
                                                                                } else {
                                                                                    checkProcedureParameters((yyvsp[-1].str), t_type_params);
                                                                                }   
                                                                            }
#line 2192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 475 "parser.y" /* yacc.c:1646  */
    {;}
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 476 "parser.y" /* yacc.c:1646  */
    {;}
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 480 "parser.y" /* yacc.c:1646  */
    {;}
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 484 "parser.y" /* yacc.c:1646  */
    {;}
#line 2216 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 485 "parser.y" /* yacc.c:1646  */
    {;}
#line 2222 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 486 "parser.y" /* yacc.c:1646  */
    {;}
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 487 "parser.y" /* yacc.c:1646  */
    {;}
#line 2234 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 488 "parser.y" /* yacc.c:1646  */
    {;}
#line 2240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 489 "parser.y" /* yacc.c:1646  */
    {;}
#line 2246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 490 "parser.y" /* yacc.c:1646  */
    {;}
#line 2252 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 494 "parser.y" /* yacc.c:1646  */
    {;}
#line 2258 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 498 "parser.y" /* yacc.c:1646  */
    {;}
#line 2264 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 499 "parser.y" /* yacc.c:1646  */
    {;}
#line 2270 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 500 "parser.y" /* yacc.c:1646  */
    {;}
#line 2276 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 504 "parser.y" /* yacc.c:1646  */
    {;}
#line 2282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 505 "parser.y" /* yacc.c:1646  */
    {;}
#line 2288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 509 "parser.y" /* yacc.c:1646  */
    {;}
#line 2294 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 510 "parser.y" /* yacc.c:1646  */
    {;}
#line 2300 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 514 "parser.y" /* yacc.c:1646  */
    {;}
#line 2306 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 518 "parser.y" /* yacc.c:1646  */
    {
                                                                                 if (is_division)
                                                                                {
                                                                                    if (tmp2 == REAL_TYPE)
                                                                                    {
                                                                                        cout << MSG_BEGIN_ERROR << line_num << ": Divisão não é entre números inteiros, só é permitida a divisão entre números inteiros.\n";
                                                                                    }
                                                                                    tmp2.clear();
                                                                                    is_division = false;
                                                                                }
                                                                            }
#line 2322 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 529 "parser.y" /* yacc.c:1646  */
    {;}
#line 2328 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 533 "parser.y" /* yacc.c:1646  */
    {;}
#line 2334 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 534 "parser.y" /* yacc.c:1646  */
    {is_division = true;}
#line 2340 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 538 "parser.y" /* yacc.c:1646  */
    {
                                                                                if (!find((yyvsp[0].str), CAT_VARIABLE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": variável '"<< (yyvsp[0].str) <<"' não declarada.\n";
                                                                                }

                                                                                if (find((yyvsp[0].str), CAT_VARIABLE))
                                                                                {
                                                                                    string tmp2 = getType((yyvsp[0].str), CAT_VARIABLE);
                                                                                    if (tmp != REAL_TYPE)
                                                                                        tmp = tmp2;
                                                                                }
                                                                                if (find((yyvsp[0].str), CAT_CONSTANT))
                                                                                {
                                                                                    string tmp2 = getType((yyvsp[0].str), CAT_CONSTANT);
                                                                                      if (tmp != REAL_TYPE)
                                                                                        tmp = tmp2;
                                                                                }
                                                                                tmp2 = tmp;
                                                                            }
#line 2364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 557 "parser.y" /* yacc.c:1646  */
    {;}
#line 2370 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 558 "parser.y" /* yacc.c:1646  */
    {;}
#line 2376 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 562 "parser.y" /* yacc.c:1646  */
    {
                                                                                // printf("val: %s, text: %s\n", yylval, yytext);
                                                                                t_num = yylval.str;
                                                                                t_type = INT_TYPE;
                                                                                if (tmp.size() == 0)
                                                                                {
                                                                                    tmp = INT_TYPE;
                                                                                    tmp2 = tmp;
                                                                                }

                                                                            }
#line 2392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 573 "parser.y" /* yacc.c:1646  */
    {
                                                                                tmp = INT_TYPE;
                                                                                tmp2 = tmp;
                                                                                t_num = yylval.str;
                                                                                t_type = REAL_TYPE;
                                                                            }
#line 2403 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2407 "parser.tab.c" /* yacc.c:1646  */
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
#line 580 "parser.y" /* yacc.c:1906  */


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
    string strS = str;
    bool hasExpecting = true;
    if (strS.find("syntax error") != string::npos)
    {
        int pos = strS.find("expecting");
        if (pos == string::npos)
        {
            hasExpecting = false;
            pos = strS.find("unexpected");
            pos += 11;
        }
        else
        {
            pos += 10;
        }
        string expected;
        bool moreThanOneWord = false;
        string word;
        while (pos < strS.size())
        {

            if (expected.size() && !moreThanOneWord)
            {
                moreThanOneWord = true;
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

        if (moreThanOneWord)
        {
            expected += " também são opções validas )";
        }
        if (hasExpecting)
            printf("[Erro] Linha %d: Esperava-se encontrar %s porém encontrou-se '%s'\n", line_num, expected.c_str(), yylval.str); // qq coisa mudar yylval para yytext
        else
            printf("[Erro] Linha %d: %s inesperado\n", line_num, expected.c_str());
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

    // current scope
    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            if (it2->second.cat == category) {
                return true;
            }
        }
    }

    // global scope
    it1 = symbolTableVector.find(0);

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

    // global scope
    it1 = symbolTableVector.find(0);

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


// Check if the number of parameters is right and the type of the parameters
void checkProcedureParameters(string procName, vector<string> types) {
    if(DEBUG) printProcParameters(procName);


    unordered_map<string, vector<Element> >::iterator it;
    it = procParams.find(procName);
    if (it != procParams.end()){

        // Check the number of parameters:
        if (it->second.size() > types.size() || it->second.size() < types.size()) {
            cout << MSG_BEGIN_ERROR << line_num << ": Esperava-se " << it->second.size() << " argumento(s), mas encontrou-se " << types.size() << " argumento(s)\n";
            return;
        }

        // Check the type of the parameters:
        for (int i = 0; i < it->second.size(); i++) { // For each param
            if (it->second[i].type != types[i]){
                cout << MSG_BEGIN_ERROR << line_num << ": Tipo incompatível de argumento. Esperava-se tipo '" << it->second[i].type << "', mas o argumento " << i+1 << " é do tipo '" << types[i] << "'\n";
            }
            if (DEBUG) cout << "\tcadeia: " << it->second[i].cadeia << " , type: " << it->second[i].type << "\n";
        }
    }
}
/*****************************************************************************************/
