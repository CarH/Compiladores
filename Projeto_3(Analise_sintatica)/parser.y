%{
#include <stdio.h>     
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include "myscanner.h"

using namespace std;


// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" int YYRECOVERING();
extern "C" FILE *yyin;
extern "C" FILE *yytext;
extern int line_num;
char found[10000];
char needed[10000];
%}

//%locations
// %define parse.error verbose
///home/sanches/projects/Compiladores/Projeto_3(Analise_sintatica)/tests/test1.in
%union 
{
    int numi;
    float numf;
    char *str;
}        /* definições do yacc */

%start programa
%token ERRODESC              
%token <str>IDENT                 // NOME DO PROGRAMA, POR EXEMPLO
%token <str>SEMICOLON             // ;
%token <str>ENDPOINT              // .
%token <str>ATTRIBUTION           // :=
%token <str>CONST_IDENT           // SERÁ QUE É O MESMO DE IDENT ? PQ EU ACHO Q A REGRA DISSO = REGRA DO IDENT
%token <str>COLON                 // :
%token <str>TYPE                 // integer/real
%token <str>COMMA                // ,
%token <str>PROCEDURE_IDENT      // NOME DO PROCEDIMENTO
%token <str>OPEN_PAR             // (
%token <str>CLOSE_PAR            // )
%token <str>EQUAL                // =
%token <str>DIF                  // <>
%token <str>GREATER_EQUAL        // >=
%token <str>LESSER_EQUAL         // <=
%token <str>GREATER              // >
%token <str>LESSER               // <
%token <str>PLUS                 // +
%token <str>MINUS                // -
%token <str>MULT                 // *
%token <str>DIV                  // /
%token <str>INTEGER_NUMBER       // NUMERO INTEIRO
%token <str>REAL_NUMBER          // NUMERO REAL DIFERENTE DE INTEIRO
%token <str>UNEXPECTED_CHAR      // Unexpected character
%token <str>ERROINT
%token <str>ERROIDENT
%token <str>ERROFLOAT
%token <str>ERROTAM
%token <str>PROGRAM           
%token <str>BEG           
%token <str>END           
%token <str>IF           
%token <str>ELSE           
%token <str>CONST           
%token <str>VAR           
%token <str>PROCEDURE           
%token <str>REAL           
%token <str>INTEGER           
%token <str>READ
%token <str>WRITE
%token <str>WHILE
%token <str>DO
%token <str>THEN
%token <str>FOR
%token <str>TO

// Struct to the symbolTable:



%%

/* Gramática da linguagem. 
   Cada regra é associada a uma ação, descrita em código C. 
   Um ponto e vírgula significa não fazer nada. */


programa : PROGRAM IDENT SEMICOLON corpo ENDPOINT                           {;}
        | error SEMICOLON corpo ENDPOINT                                    {;}
        | error ENDPOINT                                                    {;}
        | error '\n'                                                        {;}
        ;
corpo : dc BEG comandos END                                                 {;}
        | error BEG comandos END                                            {;}
        | error END                                                         {;}
        ;
dc : dc_c dc_v dc_p                                                         {;}
        ;
dc_c : CONST IDENT EQUAL numero SEMICOLON dc_c                              {;}
        | error EQUAL numero SEMICOLON dc_c                                 {;}
        | error SEMICOLON dc_c                                              {;}
        | /*vazio*/                                                         {;}
        ;
dc_v : VAR variaveis COLON tipo_var SEMICOLON dc_v                          {;}
        | error COLON tipo_var SEMICOLON dc_v                               {;}
        | error SEMICOLON dc_v                                              {;}
        | /*vazio*/                                                         {;}
        ;
tipo_var : REAL                                                             {;}
        | INTEGER                                                           {;}
        ;
variaveis : IDENT mais_var                                                  {;}
        ;
mais_var : COMMA variaveis                                                  {;}
        | /*vazio*/                                                         {;}
        ;
dc_p : PROCEDURE IDENT parametros SEMICOLON corpo_p dc_p                    {;}
        | error SEMICOLON corpo_p dc_p                                      {;}
        | /*vazio*/                                                         {;}
        ;
parametros : OPEN_PAR lista_par CLOSE_PAR                                   {;}
        | /*vazio*/                                                         {;}
        ;
lista_par : variaveis COLON tipo_var mais_par                               {;}
        | error COLON tipo_var mais_par                                     {;}
        ;
mais_par : SEMICOLON lista_par                                              {;}
        | /*vazio*/                                                         {;}
        ;
corpo_p : dc_loc BEG comandos END SEMICOLON                                 {;}
        | error BEG comandos END SEMICOLON                                  {;}
        | error SEMICOLON                                                   {;}
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
pfalsa : ELSE cmd                                                           {;}
        | /*vazio*/                                                         {;}
        ;
comandos : cmd SEMICOLON comandos                                           {;}
        | /*vazio*/                                                         {;}
        ;
cmd : READ OPEN_PAR variaveis CLOSE_PAR                                     {;}
        | WRITE OPEN_PAR variaveis CLOSE_PAR                                {;}
        | WHILE OPEN_PAR condicao CLOSE_PAR DO cmd                          {;}
        | IF condicao THEN cmd pfalsa                                       {;}
        | IDENT ATTRIBUTION expressao                                       {;}
        | IDENT lista_arg                                                   {;}
        | BEG comandos END                                                  {;}
        | FOR IDENT ATTRIBUTION numero TO numero DO BEG comandos END        {;}
        | error THEN cmd pfalsa                                             {;}
        | error END                                                         {;}
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

/**/

int main(int argc, char const *argv[]){
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
    printf("%s", str);
}
