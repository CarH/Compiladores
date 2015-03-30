%{  
#include "myscanner.h"
%}
%option nounput yylineno


%%

[a-zA-Z][_a-zA-Z0-9]*   					return IDENT;
[0-9]+(.)[0-9]+   	 						return REAL_NUMBER;
(0|[1-9][0-9]*)            					return INTEGER_NUMBER;
(:=)										return ATTRIBUTION;
(<>)										return DIF;
(>=)										return GREATER_EQUAL;
(<=)										return LESSER_EQUAL;
(>)											return GREATER;
(<)											return LESSER;
(;)											return SEMICOLON;
(\.)										return ENDPOINT;
(:)											return COLON;
(,)											return COMMA;
(\()										return OPEN_PAR;  
(\))										return CLOSE_PAR;
(\+)										return PLUS;
(\-)										return MINUS;
(\*)										return MULT;
(\/)										return DIV;
\{.*\}										;
[\ \t\n]                					;
.                       					return ERRO;

%%


int yywrap(void){
    return 1;
}

