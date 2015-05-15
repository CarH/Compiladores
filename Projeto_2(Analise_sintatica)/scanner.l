%{  
#include "scanner.h"
%}

%%
[a-zA-Z][_a-zA-Z0-9]*   return IDENT;
[1-9][0-9]*             return INTEGER_NUMBER;
[\ \t\n]                ;
.                       printf("unexpected character\n");

%%
int yywrap()
{
	return 1;
}
