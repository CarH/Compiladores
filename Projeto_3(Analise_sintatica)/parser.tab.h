/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

union YYSTYPE
{
#line 109 "parser.y" /* yacc.c:1909  */

    int numi;
    float numf;
    char *str;

#line 106 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
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
