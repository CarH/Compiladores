%{  
#include "myscanner.h"
#include <string.h>
#include "parser.tab.h"
#include <string.h>
#define YY_DECL extern "C" int yylex()
using namespace std;
extern void yyerror (const char *s);
char str[10000];


int line_num = 1;

yytokentype test(char *s)
{
	yylval.str = strdup(s);
	if(!strcmp(s, "program"))
    {
       return PROGRAM ;
    }
    if(!strcmp(s, "begin"))
    {
       return BEG;
    }
    if(!strcmp(s, "end"))
    {
       return END;
    }
    if(!strcmp(s, "if"))
    {
       return IF;
    }
    if(!strcmp(s, "else"))
    {
       return ELSE;
    }
    if(!strcmp(s, "const"))
    {
       return CONST;
    }
    if(!strcmp(s, "var"))
    {
       return VAR;
    }
    if(!strcmp(s, "procedure"))
    {
       return PROCEDURE;
    }
    if(!strcmp(s, "real"))
    {
       return REAL ;
    }
    if(!strcmp(s, "integer"))
    {
       return INTEGER;
    }
    if(!strcmp(s, "read"))
    {
       return READ;
    }
    if(!strcmp(s, "write"))
    {
       return WRITE;
    }
    if(!strcmp(s, "while"))
    {
       return WHILE;
    }
    if(!strcmp(s, "do"))
    {
       return DO;
    }
    if(!strcmp(s, "then"))
    {
       return THEN;
    }
    if(!strcmp(s, "for"))
    {
       return FOR;
    }
    if(!strcmp(s, "to"))
    {
       return TO;
    }

    int tam = strlen(s);
    if (tam > MAIORTAMANHO)
    {
        char *erro = (char*)malloc(256 * sizeof(char));
        sprintf(erro, "Linha %d: A variavel %s excede tamanho maximo de %d caracteres (Possui %d caracteres)\n",line_num, s,MAIORTAMANHO,tam);
        yyerror(erro);
        yylval.str = strdup("skip");
        free(erro);
        return ERROTAM;
    }
    return IDENT;
}
%}
%%

[a-zA-Z][_a-zA-Z0-9]*   												return {test(yytext)};
[0-9]+(\.)[0-9]+   	 														{yylval.str = strdup(yytext); return REAL_NUMBER;}
(0|[1-9][0-9]*)            											{yylval.str = strdup(yytext);	return INTEGER_NUMBER;}
(:=)																						{yylval.str = strdup(yytext); return ATTRIBUTION;}
(<>)																						{yylval.str = strdup(yytext); return DIF;}
(>=)																						{yylval.str = strdup(yytext); return GREATER_EQUAL;}
(<=)																						{yylval.str = strdup(yytext); return LESSER_EQUAL;}
(>)																							{yylval.str = strdup(yytext); return GREATER;}
(<)																							{yylval.str = strdup(yytext); return LESSER;}
(\;)																						{yylval.str = strdup(yytext); return SEMICOLON;}
(\.)																						{yylval.str = strdup(yytext); return ENDPOINT;}
(:)																							{yylval.str = strdup(yytext); return COLON;}
(,)																							{yylval.str = strdup(yytext); return COMMA;}
(\()																						{yylval.str = strdup(yytext); return OPEN_PAR; }
(\))																						{yylval.str = strdup(yytext); return CLOSE_PAR;}
(\+)																						{yylval.str = strdup(yytext); return PLUS;}
(\-)																						{yylval.str = strdup(yytext); return MINUS;}
(\*)																						{yylval.str = strdup(yytext); return MULT;}
(\/)                                            {yylval.str = strdup(yytext); return DIV;}
(=)																						  {yylval.str = strdup(yytext); return EQUAL;}
\{.*\}																						;
[\ \t]                																		;
[\n]																						{++line_num;}
[0-9][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   												{
																								sprintf(str, "Linha %d: Encontrou-se %s que é considerado um inteiro mal formado", line_num, yytext);
																								yyerror(str); 
                                                yylval.str = strdup("skip");
																								return ERROINT;
																							};
[0-9][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*\.[^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   			{
																								sprintf(str, "Linha %d: Encontrou-se %s que é considerado um float mal formado", line_num, yytext);
																								yyerror(str);
                                                yylval.str = strdup("skip");
																								return ERROFLOAT;
																							};
[A-Za-z][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   												{
																								sprintf(str, "Linha %d: Encontrou-se %s que é considerado um identificador mal formado", line_num, yytext);
																								yyerror(str);
                                                yylval.str = strdup("skip");
																								return ERROIDENT;
																							};
.                       																	{
																								sprintf(str, "Linha %d: Encontrou-se %s que é considerado como um caracter desconhecido",line_num, yytext);
																								yyerror(str);
                                                yylval.str = strdup("skip");
																								return UNEXPECTED_CHAR;
																							};

%%


int yywrap(void){
    return 1;
}

