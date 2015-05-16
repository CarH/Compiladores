%{  
#include "myscanner.h"
#include "parser.tab.h"
#define YY_DECL extern "C" int yylex()
using namespace std;
extern void yyerror (const char *s);
trie * root;


int line_num = 1;

void alloc(trie ** node)
{
    (*node) = (trie *)malloc(sizeof(trie));

    int i;
    for (i = 0; i < 256; ++i)
        (*node)->filhos[i] = NULL;
    (*node)->hasWord = 0;
}

void insert(trie * node, char * word)
{
    if (word[0] == '\0')
    {
        node->hasWord = 1;
        return;
    }
    if (node->filhos[word[0]] == NULL)
    {
        alloc(&(node->filhos[word[0]]));
    }

    insert(node->filhos[word[0]], word + 1);
}

int initializeTrie (){
    FILE *fp;
    int i=0;
    char word[1000];

    if ( (fp = fopen("palavras_reservadas.txt", "r")) == NULL ){
        fprintf(stderr, "Nao foi possivel encontrar o arquivo de palavras reservadas. Verifique se o arquivo 'palavras_reservadas.txt' encontra-se no diretorio atual.\n");
        return 1;
    }


    alloc(&root);
    while ( fscanf (fp, "%s", word) != EOF ){
        insert(root, word);
    }

    fclose(fp);
    return 0;
}

int query(trie * node, char * word)
{
    if (word[0] == '\0')
    {
        return node->hasWord;
    }

    if (node->filhos[word[0]] == NULL)
    {
        return 0;
    }

    return query(node->filhos[word[0]], word + 1);
}

yytokentype test(char *s)
{
	yylval.str = strdup(s);
	if (query(root, s))
	{
		return RESERVADA;
	}
	return IDENT;
}
%}

%%

[a-zA-Z][_a-zA-Z0-9]*   																	return {test(yytext)};
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
[0-9][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   												{
																								char str[256];
																								sprintf(str, "Inteiro mal formado (%s)\n",yytext);
																								yyerror(str); 
																								return ERROINT;
																							};
[0-9][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*\.[^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   			{
																								char str[256];
																								sprintf(str, "Float mal formado (%s)\n",yytext);
																								yyerror(str);
																								return ERROFLOAT;
																							};
[A-Za-z][^\.\(\)\[\]\ \n\r\t;:,\+\-\*\/<>#]*   												{
																								char str[256];
																								sprintf(str, "Identificador mal formado (%s)\n",yytext);
																								yyerror(str);
																								return ERROIDENT;
																							};
.                       																	{
																								char str[256];
																								sprintf(str, "Caracter desconhecido (%s)\n",yytext);
																								yyerror(str);
																								return UNEXPECTED_CHAR;
																							};

%%


int yywrap(void){
    return 1;
}

