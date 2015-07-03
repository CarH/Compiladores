%{
#include <stdio.h>     
#include <stdlib.h>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include "myscanner.h"

using namespace std;


// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" int YYRECOVERING();
extern "C" FILE *yyin;
extern "C" FILE *yytext;
extern int line_num;
map<string, string> m;

%}

%locations
%define parse.error verbose
///home/sanches/projects/Compiladores/Projeto_3(Analise_sintatica)/tests/test2.in
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
%token <str>COLON                 // :
%token <str>COMMA                // ,
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
%%

/* Gramática da linguagem. 
   Cada regra é associada a uma ação, descrita em código C. 
   Um ponto e vírgula significa não fazer nada. */


programa : PROGRAM IDENT SEMICOLON corpo ENDPOINT                           {;}
        |  error IDENT SEMICOLON corpo ENDPOINT                             {;}
        |  PROGRAM error SEMICOLON corpo ENDPOINT                           {;}
        ;
corpo : dc BEG comandos END                                                 {;}
        | error END                                                         {;}
        | dc BEG error END                                                  {;}
        ;
dc : dc_c dc_v dc_p                                                         {;}
        | error VAR                                                         {;}
        | error PROCEDURE                                                   {;}
        | error BEG                                                         {;}
        ;
dc_c : CONST IDENT EQUAL numero SEMICOLON dc_c                              {;}
        | CONST IDENT EQUAL error SEMICOLON                                 {;}
        | CONST IDENT EQUAL error MULT                                      {;}
        | CONST IDENT EQUAL error DIV                                       {;}
        | CONST IDENT EQUAL error PLUS                                      {;}
        | CONST IDENT EQUAL error MINUS                                     {;}
        | CONST IDENT EQUAL error CLOSE_PAR                                 {;}
        | CONST IDENT EQUAL error THEN                                      {;}
        | CONST IDENT EQUAL error ELSE                                      {;}
        | CONST IDENT EQUAL error EQUAL                                     {;}
        | CONST IDENT EQUAL error DIF                                       {;}
        | CONST IDENT EQUAL error GREATER_EQUAL                             {;}
        | CONST IDENT EQUAL error LESSER_EQUAL                              {;}
        | CONST IDENT EQUAL error GREATER                                   {;}
        | CONST IDENT EQUAL error LESSER                                    {;}
        | /*vazio*/                                                         {;}
        ;
dc_v : VAR variaveis COLON tipo_var SEMICOLON dc_v                          {;}
        | VAR error CLOSE_PAR                                               {;}
        | VAR error COLON                                                   {;}
        | VAR variaveis COLON error SEMICOLON                               {;}
        | VAR variaveis COLON tipo_var SEMICOLON error VAR                  {;}
        | /*vazio*/                                                         {;}
        ;
tipo_var : REAL                                                             {;}
        | INTEGER                                                           {;}
        ;
variaveis : IDENT mais_var                                                  {;}
        | IDENT error CLOSE_PAR                                             {;}
        ;
mais_var : COMMA variaveis                                                  {;}
        |  COMMA error CLOSE_PAR                                            {;}
        | /*vazio*/                                                         {;}
        ;
dc_p : PROCEDURE IDENT parametros SEMICOLON corpo_p dc_p                    {;}
        | PROCEDURE IDENT error SEMICOLON                                   {;}
        | PROCEDURE IDENT parametros SEMICOLON error PROCEDURE              {;}
        | PROCEDURE IDENT parametros SEMICOLON error BEG                    {;}
        | PROCEDURE IDENT parametros SEMICOLON corpo_p error BEG            {;}
        | /*vazio*/                                                         {;}
        ;
parametros : OPEN_PAR lista_par CLOSE_PAR                                   {;}
        | OPEN_PAR error CLOSE_PAR                                          {;}
        | /*vazio*/                                                         {;}
        ;
lista_par : variaveis COLON tipo_var mais_par                               {;}
        | error COLON tipo_var mais_par                                     {;}
        | error CLOSE_PAR                                                   {;}
        | variaveis COLON error SEMICOLON                                   {;}
        | variaveis COLON tipo_var error CLOSE_PAR                          {;}
        ;
mais_par : SEMICOLON lista_par                                              {;}
        | /*vazio*/                                                         {;}
        ;
corpo_p : dc_loc BEG comandos END SEMICOLON                                 {;}
        | dc_loc BEG error END                                              {;}
        ;
dc_loc : dc_v                                                               {;}
        ;
lista_arg : OPEN_PAR argumentos CLOSE_PAR                                   {;}
        |  OPEN_PAR error CLOSE_PAR                                         {;}
        | /*vazio*/                                                         {;}
        ;
argumentos : IDENT mais_ident                                               {;}
        ;
mais_ident : SEMICOLON argumentos                                           {;}
        | /*vazio*/                                                         {;}
        ;
pfalsa : ELSE cmd                                                           {;}
        | /*vazio*/                                                         {;}
        ;
comandos : cmd SEMICOLON comandos                                           {;}
        |  error SEMICOLON comandos                                         {;}
        |  error ELSE                                                       {;}
        |  cmd SEMICOLON error END                                          {;}
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

    m["IDENT"] = "identificador";
    m["SEMICOLON"] = ";";
    m["ENDPOINT"] = ".";
    m["ATTRIBUTION"] = ":=";
    m["CONST"] = "const";
    m["COLON"] = ":";
    m["COMMA"] = ",";
    m["OPEN_PAR"] = "(";
    m["CLOSE_PAR"] = ")";
    m["EQUAL"] = "=";
    m["DIF"] = "<>";
    m["GREATER_EQUAL"] = ">=";
    m["LESSER_EQUAL"] = "<=";
    m["GREATER"] = ">";
    m["LESSER"] = "<";
    m["PLUS"] = "+";
    m["MINUS"] = "-";
    m["MULT"] = "*";
    m["DIV"] = "/";
    m["INTEGER_NUMBER"] = "integer";
    m["REAL_NUMBER"] = "real";
    m["PROGRAM"] = "program";
    m["BEG"] = "begin";
    m["END"] = "end";
    m["IF"] = "if";
    m["ELSE"] = "else";
    m["CONST"] = "const";
    m["VAR"] = "var";
    m["PROCEDURE"] = "procedure";
    m["READ"] = "read";
    m["WRITE"] = "write";
    m["WHILE"] = "while";
    m["DO"] = "do";
    m["THEN"] = "then";
    m["FOR"] = "for";
    m["TO"] = "to";
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
    string tmp = str;
    if (tmp.find("syntax error") != string::npos)
    {
        string strS = str;
        int pos = strS.find("expecting");
        pos += 10;
        string expected;
        bool test = false;
        string word;
        while (pos < strS.size())
        {

            if (expected.size() && !test)
            {
                test = true;
                expected += " (Note que ";
            }
            else if (expected.size())
            {
                expected += ", ";
            }
            while (pos < strS.size() && strS[pos] != ' ')
            {
                word += strS[pos];
                pos++;
            }
            expected += "\"";
            expected += m[word];
            expected += "\"";
            word.clear();
            pos += 4;
        }

        if (test)
        {
            expected += " também são opções validas )";
        }

        printf("Linha %d: Experava-se encontrar %s porém encontrou-se %s\n", line_num, expected.c_str(), yytext);
    }
    else
    {
        printf("%s\n",str);
    }
}
