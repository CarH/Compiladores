%{
#include <stdio.h>     
#include <stdlib.h>
// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
void yyerror (char *s);
%}

%locations
%define parse.error verbose
%union {int numi; string id; float numf}         /* definições do yacc */
%start commands
%token ERRODESC              
%token <id> IDENT                 // NOME DO PROGRAMA, POR EXEMPLO
%token SEMICOLON             // ;
%token ENDPOINT              // .
%token ATTRIBUTION           // :=
%token CONST_IDENT           // SERÁ QUE É O MESMO DE IDENT ? PQ EU ACHO Q A REGRA DISSO = REGRA DO IDENT
%token COLON                 // :
%token TYPE                 // integer/real
%token COMMA                // ,
%token PROCEDURE_IDENT      // NOME DO PROCEDIMENTO
%token OPEN_PAR             // (
%token CLOSE_PAR            // )
%token EQUAL                // =
%token DIF                  // <>
%token GREATER_EQUAL        // >=
%token LESSER_EQUAL         // <=
%token GREATER              // >
%token LESSER               // <
%token PLUS                 // +
%token MINUS                // -
%token MULT                 // *
%token DIV                  // /
%token <numi> INTEGER_NUMBER       // NUMERO INTEIRO
%token <numf> REAL_NUMBER          // NUMERO REAL DIFERENTE DE INTEIRO
%token UNEXPECTED_CHAR      // Unexpected character
%token ERROINT
%token ERROIDENT
%token ERROFLOAT
%%

/* Gramática da linguagem. 
   Cada regra é associada a uma ação, descrita em código C. 
   Um ponto e vírgula significa não fazer nada. */


programa : 'program' IDENT ';' corpo .                                       {;}
        ;
corpo : dc 'begin' comandos 'end'                                            {;}
        ;
dc : dc_c dc_v dc_p                                                          {;}
        ;
dc_c : 'const' IDENT = numero ';' dc_c                                       {;}
        | /*vazio*/                                                          {;}
        ;
dc_v : 'var' variaveis ':' tipo_var ';' dc_v                                 {;}
        | /*vazio*/                                                          {;}
        ;
tipo_var : 'real'                                                            {;}
        | 'integer'                                                          {;}
        ;
variaveis : IDENT mais_var                                                   {;}
        ;
dc_p : 'procedure' IDENT parametros ';' corpo_p dc_p                         {;}
        | /*vazio*/                                                          {;}
        ;
parametros : '(' lista_par ')'                                               {;}
        | /*vazio*/                                                          {;}
        ;
lista_par : variaveis : tipo_var mais_par                                    {;}
        ;
mais_par : ; lista_par                                                       {;}
        | /*vazio*/                                                          {;}
        ;
corpo_p : dc_loc 'begin' comandos 'end' ;                                    {;}
        ;
dc_loc : dc_v                                                                {;}
        ;
lista_arg : '(' argumentos ')'                                               {;}
        | /*vazio*/                                                          {;}
        ;
argumentos : IDENT mais_ident                                                {;}
mais_ident : ';' argumentos                                                  {;}
        | /*vazio*/                                                          {;}
        ;
pfalsa : 'else' cmd                                                          {;}
        | /*vazio*/                                                          {;}
        ;
comandos : cmd ';' comandos                                                  {;}
        | /*vazio*/                                                          {;}
        ;
cmd : 'read' '(' variaveis ')'                                               {;}
        | 'write' '(' variaveis ')'                                          {;}
        | 'while' '(' condicao ')' 'do' cmd                                  {;}
        | 'if' condicao 'then' cmd pfalsa                                    {;}
        | IDENT ':=' expressão                                               {;}
        | IDENT lista_arg                                                    {;}
        | 'write' '(' variaveis ')'                                          {;}
        | 'while' '(' condicao ')' 'do' cmd                                  {;}
        | 'if' condicao 'then' cmd pfalsa                                    {;}
        | IDENT ':=' expressão                                               {;}
        | IDENT lista_arg                                                    {;}
        | 'begin' comandos 'end'                                             {;}
        ;
condicao : expressao relacao expressao                                       {;}
        ;
relacao : '='                                                                {;}
        | '<>'                                                               {;}
        | '>='                                                               {;}
        | '='                                                                {;}
        | '>'                                                                {;}
        | /*vazio*/                                                          {;}
        ;
expressao : termo outros_termos                                              {;}
        ;
op_un : '+'                                                                  {;}
        | '-'                                                                {;}
        | /*vazio*/                                                          {;}
        ;
outros_termos : op_ad termo outros_termos                                    {;}
        | /*vazio*/                                                          {;}
        ;
op_ad : '+'                                                                  {;}
        | '-'                                                                {;}
        ;
termo : op_un fator mais_fatores                                             {;}
        ;
mais_fatores : op_mul fator mais_fatores                                     {;}
        | /*vazio*/                                                          {;}
        ;
op_mul : '*'                                                                 {;}
        | '/'                                                                {;}
        ;
fator : IDENT                                                                {check($1)}
        | numero                                                             {;}
        | '(' expressao ')'                                                  {;}
        ;
numero : INTEGER_NUMBER                                                      {;}
        | REAL_NUMBER                                                        {;}
        ;




%%

/* Código C inserido diretamente no arquivo gerado pelo yacc */

void check(string ident)
{  
    char *erro = (char*)malloc(256 * sizeof(char));
    if (ident.size() > MAIORTAMANHO)
    {
        sprintf(erro, "%s excede tamanho maximo de %d caracteres (Possui %d caracteres)\n",yytext,MAIORTAMANHO,tam);
        yyerror(erro);
    }
    free(erro);
}
/**/

int main (void) {
    return yyparse ( );
}

void yyerror(char *str)
{
    fprintf(stderr,"Line %d: %s\n",yylineno,str);
}
