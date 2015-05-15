%{  
#include "myscanner.h"
#include "parser.tab.h"
#define YY_DECL extern "C" int yylex()

using namespace std;

int line_num = 1;

int check(char *s)
{
	query(root, yytext)
}
%}

%%

[a-zA-Z][_a-zA-Z0-9]*   																	return {check(yytext)? yytext : IDENT};
[0-9]+(\.)[0-9]+   	 																		return REAL_NUMBER;
(0|[1-9][0-9]*)            																	return INTEGER_NUMBER;
(:=)																						return ATTRIBUTION;
(<>)																						return DIF;
(>=)																						return GREATER_EQUAL;
(<=)																						return LESSER_EQUAL;
(>)																							return GREATER;
(<)																							return LESSER;
(;)																							return SEMICOLON;
(\.)																						return ENDPOINT;
(:)																							return COLON;
(,)																							return COMMA;
(\()																						return OPEN_PAR;  
(\))																						return CLOSE_PAR;
(\+)																						return PLUS;
(\-)																						return MINUS;
(\*)																						return MULT;
(\/)																						return DIV;
\{.*\}																						;
[\ \t]                																		;
[\n]																						{++line_num;}
[0-9][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   												return ERROINT;
[0-9][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*\.[^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   			return ERROFLOAT;
[A-Za-z][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   												return ERROIDENT;
.                       																	return ERRODESC;

%%


int yywrap(void){
    return 1;
}

