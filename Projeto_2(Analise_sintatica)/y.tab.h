/* A Bison parser, made by GNU Bison 2.6.  */

/* Bison interface for Yacc-like parsers in C
   
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

#ifndef YY_Y_TAB_H
# define YY_Y_TAB_H
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
/* Tokens.  */
#define ERRODESC 258
#define IDENT 259
#define SEMICOLON 260
#define ENDPOINT 261
#define ATTRIBUTION 262
#define CONST_IDENT 263
#define COLON 264
#define TYPE 265
#define COMMA 266
#define PROCEDURE_IDENT 267
#define OPEN_PAR 268
#define CLOSE_PAR 269
#define EQUAL 270
#define DIF 271
#define GREATER_EQUAL 272
#define LESSER_EQUAL 273
#define GREATER 274
#define LESSER 275
#define PLUS 276
#define MINUS 277
#define MULT 278
#define DIV 279
#define INTEGER_NUMBER 280
#define REAL_NUMBER 281
#define UNEXPECTED_CHAR 282
#define ERROINT 283
#define ERROIDENT 284
#define ERROFLOAT 285
#define ERROTAM 286
#define PROGRAM 287
#define BEG 288
#define END 289
#define IF 290
#define ELSE 291
#define CONST 292
#define VAR 293
#define PROCEDURE 294
#define REAL 295
#define INTEGER 296
#define READ 297
#define WRITE 298
#define WHILE 299
#define DO 300
#define THEN 301
#define FOR 302
#define TO 303



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2050 of yacc.c  */
#line 23 "parser.y"

    int numi;
    float numf;
    char *str;



/* Line 2050 of yacc.c  */
#line 162 "y.tab.h"
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

#endif /* !YY_Y_TAB_H  */
