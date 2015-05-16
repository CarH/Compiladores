%{
#include <stdio.h>     
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include "myscanner.h"

using namespace std;


// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
void check(char* ident, char *expected);
extern int line_num;
%}

%locations
%define parse.error verbose
%union 
{
    int numi;
    float numf;
    char *str;
}        /* definições do yacc */

%start programa
%token ERRODESC              
%token <str> IDENT                 // NOME DO PROGRAMA, POR EXEMPLO
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
%token INTEGER_NUMBER       // NUMERO INTEIRO
%token REAL_NUMBER          // NUMERO REAL DIFERENTE DE INTEIRO
%token UNEXPECTED_CHAR      // Unexpected character
%token ERROINT
%token ERROIDENT
%token ERROFLOAT
%token <str> RESERVADA           //token de palavra reservada
%%

/* Gramática da linguagem. 
   Cada regra é associada a uma ação, descrita em código C. 
   Um ponto e vírgula significa não fazer nada. */


programa : RESERVADA IDENT SEMICOLON corpo ENDPOINT                         {
                                                                                check($1, (char *)"program");
                                                                            }
        ;
corpo : dc RESERVADA comandos RESERVADA                                     {
                                                                                check($2, (char *)"begin"); 
                                                                                check($4, (char *)"end");
                                                                            }
        ;
dc : dc_c dc_v dc_p                                                         {;}
        ;
dc_c : RESERVADA IDENT EQUAL numero SEMICOLON dc_c                          {
                                                                                check($1, (char *)"const");
                                                                            }
        | /*vazio*/                                                         {;}
        ;
dc_v : RESERVADA variaveis COLON tipo_var SEMICOLON dc_v                    {
                                                                                check($1, (char *)"var");
                                                                            }
        | /*vazio*/                                                         {;}
        ;
tipo_var : RESERVADA                                                        {
                                                                                check($1, (char *)"real");
                                                                            }
        | RESERVADA                                                         {
                                                                                check($1, (char *)"integer");
                                                                            }
variaveis : IDENT mais_var                                                  {;}
        ;
mais_var : COMMA variaveis                                                  {;}
        | /*vazio*/                                                         {;}
        ;
dc_p : RESERVADA IDENT parametros SEMICOLON corpo_p dc_p                    {
                                                                                check($1, (char *)"procedure");
                                                                            }
        | /*vazio*/                                                         {;}
        ;
parametros : OPEN_PAR lista_par CLOSE_PAR                                   {;}
        | /*vazio*/                                                         {;}
        ;
lista_par : variaveis : tipo_var mais_par                                   {;}
        ;
mais_par : SEMICOLON lista_par                                              {;}
        | /*vazio*/                                                         {;}
        ;
corpo_p : dc_loc RESERVADA comandos RESERVADA SEMICOLON                     {
                                                                                check($2, (char *)"begin"); 
                                                                                check($4, (char *)"end");
                                                                            }
        ;
dc_loc : dc_v                                                               {;}
        ;
lista_arg : OPEN_PAR argumentos CLOSE_PAR                                   {;}
        | /*vazio*/                                                         {;}
        ;
argumentos : IDENT mais_ident                                               {;}
mais_ident : SEMICOLON argumentos                                           {;}
        | /*vazio*/                                                         {;}
        ;
pfalsa : RESERVADA cmd                                                      {
                                                                                check($1, (char *)"else");
                                                                            }
        | /*vazio*/                                                         {;}
        ;
comandos : cmd SEMICOLON comandos                                           {;}
        | /*vazio*/                                                         {;}
        ;
cmd : RESERVADA OPEN_PAR variaveis CLOSE_PAR                                {
                                                                                check($1, (char *)"read");
                                                                            }
        | RESERVADA OPEN_PAR variaveis CLOSE_PAR                            {
                                                                                check($1, (char *)"write");
                                                                            }
        | RESERVADA OPEN_PAR condicao CLOSE_PAR RESERVADA cmd               {
                                                                                check($1, (char *)"while");
                                                                                check($5, (char *)"do");
                                                                            }
        | RESERVADA condicao RESERVADA cmd pfalsa                           {
                                                                                check($1, (char *)"if");
                                                                                check($3, (char *)"then");
                                                                            }
        | IDENT ATTRIBUTION expressao                                       {;}
        | IDENT lista_arg                                                   {;}
        | RESERVADA comandos RESERVADA                                      {
                                                                                check($1, (char *)"begin"); 
                                                                                check($3, (char *)"end");
                                                                            }
        ;
condicao : expressao relacao expressao                                      {;}
        ;
relacao : EQUAL                                                             {;}
        | DIF                                                               {;}
        | GREATER_EQUAL                                                     {;}
        | LESSER_EQUAL                                                      {;}
        | GREATER                                                           {;}
        | LESSER                                                            {;}
        | /*vazio*/                                                         {;}
        ;
expressao : termo outros_termos                                             {;}
        ;
op_un : PLUS                                                                {;}
        | MINUS                                                             {;}
        | /*vazio*/                                                         {;}
        ;
outros_termos : op_ad termo outros_termos                                   {;}
        | /*vazio*/                                                         {;}
        ;
op_ad : PLUS                                                                {;}
        | MINUS                                                             {;}
        ;
termo : op_un fator mais_fatores                                            {;}
        ;
mais_fatores : op_mul fator mais_fatores                                    {;}
        | /*vazio*/                                                         {;}
        ;
op_mul : MULT                                                               {;}
        | DIV                                                               {;}
        ;
fator : IDENT                                                               {;}
        | numero                                                            {;}
        | OPEN_PAR expressao CLOSE_PAR                                      {;}
        ;
numero : INTEGER_NUMBER                                                     {;}
        | REAL_NUMBER                                                       {;}
        ;




%%

/* Código C inserido diretamente no arquivo gerado pelo yacc */

void check(char* ident, char *expected)
{  
    char *erro = (char*)malloc(256 * sizeof(char));
    
    if (strcmp(ident, expected))
    {
        sprintf(erro, "Era esperada a palavra reservada %s, encontrou-se %s",expected, ident);
        yyerror(erro);
    }
    else
    {
        int tam = strlen(ident);
        if (tam > MAIORTAMANHO)
        {
            sprintf(erro, "%s excede tamanho maximo de %d caracteres (Possui %d caracteres)\n",ident,MAIORTAMANHO,tam);
            yyerror(erro);
        }
    }
    free(erro);
}
/**/

int main(int argc, char const *argv[]){
    int ntoken;
    int tam;

    /// Inicializa a TRIE apropriadamente
    if ( initializeTrie() ) { return 1; }
    ///

    return yyparse ( );
}
void yyerror(const char *str)
{
    fprintf(stderr,"Line %d: %s\n",line_num,str);
    exit(-1);
}
