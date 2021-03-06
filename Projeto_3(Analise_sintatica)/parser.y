/***************************************************************************************************
 *                                  Trabalho 3 - Analisador Semântico
 *                      SCC0217 Linguagens de programação e compiladores       
 *                                 Prof. Dr. Diego Raphael Amancio
 ***************************************************************************************************
 *      Grupo:
 *          Bruno Daniel Sanches Silva              
 *          Carlos Humberto S Baqueta       
 *          Cláudio Domene                  
 ***************************************************************************************************/
%{
#include <stdio.h>     
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include "myscanner.h"

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" int YYRECOVERING();
extern "C" FILE *yyin;
extern "C" FILE *yytext;
extern int line_num;

// Enable/disable the debugging mode
#define DEBUG false

char found[10000];
char needed[10000];
string tmp;
string tmp2;


/****************************************************************************************
                                'SYMBOL TABLE'
                            TODO: por em outro .h 
*****************************************************************************************/
// Struct to the symbolTable: str.
struct Element
{
    string cadeia;
    string type;
    string cat;
    string val;
    int token;
    int line;
    int scope;
    int numParams;
};

int CURR_SCOPE = 0;
unordered_map<int, unordered_map<string, Element> > symbolTableVector;

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope, int numParams);
bool find(int scope, string cadeia);
bool updateType(vector<string> cadeia, string type, int scope);
void printSymbolTable();
void printProcParameters(string procName);
bool find(string cadeia, string category);
string getType(string cadeia, string category);
void checkProcedureParameters(string procName, vector<string> types);

/****************************************
|   Definitions of some attributes      |
****************************************/
// Categories:
string CAT_PROGRAM_NAME = "main_prog_name";
string CAT_PROCEDURE    = "procedure";
string CAT_CONSTANT     = "constant";
string CAT_VARIABLE     = "variable";
string NONE             = "";

// Types
string INT_TYPE         = "integer";
string REAL_TYPE        = "real";


/****************************************
|   Temp variables to hold data         |
|  during the handle recognition        |
****************************************/
string t_num;
string t_type;
vector<string> t_type_params;
vector<string> t_cadeias;
string t_var_type;

/****************************************
|       Parameters of the Procedures    |
****************************************/
unordered_map<string, vector<Element> > procParams;
string curr_proc_name;

/****************************************
|           Control Flags               |
****************************************/
bool is_proc_parameter  = false;
bool is_valid_procedure = false;
bool is_procedure       = false;
bool is_division        = false;
bool check_var_type     = false;
bool has_diff_type      = false;

string MSG_BEGIN_ERROR = "[Erro] Linha ";
/*****************************************************************************************/

map<string, string> m;

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

/* REGRA 1: <programa> ::= program ident ; <corpo> . */
programa: PROGRAM IDENT                                                     {
                                                                                insert($2, IDENT, NONE, CAT_PROGRAM_NAME, NONE, line_num, CURR_SCOPE, 0);                                                                                
                                                                                if (DEBUG) printSymbolTable();
                                                                            }
          SEMICOLON corpo ENDPOINT                                          {;}

        | error SEMICOLON corpo ENDPOINT                                    {;}
        ;

/* REGRA 2: <corpo> ::= <dc> begin <comandos> end */
corpo   : dc BEG comandos END                                               {;}
        | dc error comandos END                                             {;}
        ;

/* REGRA 3: <dc> ::= <dc_c> <dc_v> <dc_p> */
dc      : dc_c dc_v dc_p                                                    {;}
        | error dc_v                                                        {;}
        | error dc_c                                                        {;}
        | error dc_p                                                        {;}
        ;

/* REGRA 4: <dc_c> ::= const ident = <numero> ; <dc_c> | λ */
dc_c    : CONST IDENT EQUAL numero SEMICOLON dc_c                           {
                                                                                insert($2, IDENT, t_type, CAT_CONSTANT, t_num, line_num, CURR_SCOPE, 0);
                                                                                if (DEBUG) printSymbolTable();
                                                                            }
        | error numero SEMICOLON dc_c                                       {;}
        | error SEMICOLON dc_c                                              {;}
        | error dc_c                                                        {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 5: <dc_v> ::= var <variaveis> : <tipo_var> ; <dc_v> | λ */
dc_v    : VAR variaveis COLON tipo_var SEMICOLON dc_v                       {;}
        | error variaveis COLON tipo_var SEMICOLON dc_v                     {;}
        | error SEMICOLON dc_v                                              {;}
        | error dc_v                                                        {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 6: <tipo_var> ::= real | integer */
tipo_var : REAL                                                             {
                                                                                t_type = REAL_TYPE;
                                                                                for (int i=0; i < t_cadeias.size(); i++) { // for each variable in the list
                                                                                    if (find(CURR_SCOPE, t_cadeias[i])){
                                                                                        cout << "[Erro] Linha "<< line_num <<": a variável '"<< t_cadeias[i] <<"' foi declarada mais de uma vez.\n";
                                                                                    } else {
                                                                                        if (is_procedure) {
                                                                                            if (is_valid_procedure) {
                                                                                                insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                            }
                                                                                        } else {
                                                                                            insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                        }
                                                                                        // insert procedure parameter into the procParams
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            if(DEBUG) cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";
                                                                                        }
                                                                                    }
                                                                                }
                                                                                t_cadeias.clear();
                                                                            
                                                                            }
        | INTEGER                                                           {
                                                                                t_type = INT_TYPE;
                                                                                for (int i=0; i < t_cadeias.size(); i++) {
                                                                                    if (find(CURR_SCOPE, t_cadeias[i])){
                                                                                        cout << "[Erro] Linha "<< line_num <<": a variável '"<< t_cadeias[i] <<"' foi declarada mais de uma vez.\n";
                                                                                    } else {
                                                                                        if (is_procedure) {
                                                                                            if (is_valid_procedure) {
                                                                                                insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                            }
                                                                                        } else {
                                                                                            insert(t_cadeias[i], IDENT, t_type, CAT_VARIABLE, NONE, line_num, CURR_SCOPE, 0);
                                                                                        }
                                                                                        // insert procedure parameter into the procParams
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            if (DEBUG) cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";

                                                                                        }
                                                                                    }
                                                                                }
                                                                                t_cadeias.clear();
                                                                            }
        ;

/* REGRA 7: <variaveis> ::= ident <mais_var> */
variaveis: IDENT                                                            {
                                                                                if(check_var_type){ /* The variable is already declared */
                                                                                    if(find($1, CAT_VARIABLE)){
                                                                                        if (t_var_type == NONE){
                                                                                            t_var_type = getType($1, CAT_VARIABLE);
                                                                                        } else {
                                                                                            if (t_var_type != getType($1, CAT_VARIABLE)){
                                                                                                has_diff_type = true;
                                                                                            }
                                                                                        }
                                                                                    } else {
                                                                                        cout << MSG_BEGIN_ERROR << line_num << ": variável '"<< $1 <<"' não declarada ou '"<< $1 <<"' não é do tipo variável.\n";                                 
                                                                                    }
                                                                                }
                                                                            }
            mais_var                                                        {
                                                                                if(DEBUG) cout << "inseriu " << $1 << " em t_cadeias\n";
                                                                                t_cadeias.push_back($1);
                                                                            }
        ;

/* REGRA 8: <mais_var> ::= , <variaveis> | λ */
mais_var: COMMA variaveis                                                   {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 9: <dc_p> ::= procedure ident <parametros> ; <corpo_p> <dc_p> | λ */
dc_p    : PROCEDURE IDENT                                                   { 
                                                                                t_cadeias.clear();
                                                                                if (!find(CURR_SCOPE, $2)) {
                                                                                    insert($2, IDENT, NONE, CAT_PROCEDURE, NONE, line_num, CURR_SCOPE, 0);
                                                                                    
                                                                                    curr_proc_name = $2; //For control purpose: current procedure name
                                                                                    
                                                                                    vector<Element> v;
                                                                                    pair<string, vector<Element> > item ($2, v);
                                                                                    procParams.insert(item);
                                                                                    
                                                                                    is_valid_procedure = true;
                                                                                } else {
                                                                                    cout << MSG_BEGIN_ERROR << line_num <<": procedimento declarado mais de uma vez.\n";
                                                                                    is_valid_procedure = false;
                                                                                }
                                                                                CURR_SCOPE++;
                                                                                is_proc_parameter = true;
                                                                                is_procedure = true;
                                                                            } 
         parametros                                                         {
                                                                                is_proc_parameter = false;
                                                                                if (DEBUG) printProcParameters(curr_proc_name);
                                                                            }

         SEMICOLON corpo_p                                                  {
                                                                                if (DEBUG) printSymbolTable();
                                                                                if (DEBUG) cout << " ! REMOVING SCOPE " << CURR_SCOPE << "\n";
                                                                                
                                                                                // Delete the symbol Table from the CURR_SCOPE
                                                                                symbolTableVector.erase(CURR_SCOPE);

                                                                                if (DEBUG) printSymbolTable();
                                                                                CURR_SCOPE--;
                                                                                is_procedure = false;
                                                                            }

         dc_p                                                               {;}
        | error parametros SEMICOLON corpo_p dc_p                           {;}
        | error SEMICOLON corpo_p dc_p                                      {;}
        | error dc_p                                                        {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 10: <parametros> ::= ( <lista_par> ) | λ */
parametros : OPEN_PAR                                                       { t_cadeias.clear(); }
         lista_par CLOSE_PAR                                                {; }
        | OPEN_PAR error CLOSE_PAR                                          {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 11: <lista_par> ::= <variaveis> : <tipo_var> <mais_par> */
lista_par : variaveis COLON tipo_var mais_par                               {;}
        |   error tipo_var mais_par                                         {;}
        |   error mais_par                                                  {;}
        ;

/* REGRA 12: <mais_par> ::= ; <lista_par> | λ */        
mais_par : SEMICOLON lista_par                                              {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 13: <corpo_p> ::= <dc_loc> begin <comandos> end ; */        
corpo_p : dc_loc BEG comandos END SEMICOLON                                 {;}
        | error BEG comandos END SEMICOLON                                  {;}
        | error SEMICOLON                                                   {;}
        ;

/* REGRA 14: <dc_loc> ::= <dc_v> */        
dc_loc : dc_v                                                               {;}
        ;

/* REGRA 15: <lista_arg> ::= ( <argumentos> ) | λ */        
lista_arg : OPEN_PAR                                                        {
                                                                                t_type_params.clear();
                                                                            } 
          argumentos CLOSE_PAR                                              {;}
        | OPEN_PAR error CLOSE_PAR                                          {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 16: <argumentos> ::= ident <mais_ident> */
argumentos : IDENT                                                          {
                                                                                if (DEBUG) printSymbolTable();
                                                                                if(find($1, CAT_VARIABLE)){
                                                                                    t_type_params.push_back(getType($1, CAT_VARIABLE)); // TODO
                                                                                } else {
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": '" << $1 << "' não foi declarado.\n";
                                                                                }
                                                                            }
            mais_ident                                                      {;}
        ;

/* REGRA 17: <mais_ident> ::= ; <argumentos> | λ */
mais_ident : SEMICOLON argumentos                                           {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 18: <pfalsa> ::= else <cmd> | λ */
pfalsa : ELSE cmd                                                           {;}
        | error cmd                                                         {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 19: <comandos> ::= <cmd> ; <comandos> | λ */
comandos : cmd SEMICOLON comandos                                           {;}
        | error comandos                                                    {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 20: <cmd> ::= read ( <variaveis> ) 
    | write ( <variaveis> ) 
    | while ( <condicao> ) do <cmd> 
    | if <condicao> then <cmd> <pfalsa> 
    | ident := <expressão> 
    | ident <lista_arg> 
    | begin <comandos> end        */
cmd     : READ OPEN_PAR                                                     { 
                                                                                t_var_type = NONE;
                                                                                check_var_type = true;
                                                                                has_diff_type  = false; 
                                                                            } 
          variaveis CLOSE_PAR                                               {
                                                                                if (has_diff_type){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": comando 'read' apresenta variáveis de tipos diferentes.\n";
                                                                                }
                                                                                check_var_type = false;
                                                                                has_diff_type  = false; 
                                                                                t_var_type = NONE;
                                                                            }
        | WRITE OPEN_PAR                                                    {
                                                                                t_var_type = NONE;
                                                                                check_var_type = true;
                                                                                has_diff_type  = false; 
                                                                            }
          variaveis CLOSE_PAR                                               {
                                                                                if (has_diff_type){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": comando 'write' apresenta variáveis de tipos diferentes.\n";
                                                                                }
                                                                                check_var_type = false;
                                                                                has_diff_type  = false; 
                                                                                t_var_type = NONE;
                                                                            }
        | WHILE OPEN_PAR condicao CLOSE_PAR DO cmd                          {;}
        | IF condicao THEN cmd pfalsa                                       {;}
        | IDENT ATTRIBUTION                                                 {
                                                                                if (!find($1, CAT_VARIABLE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": variável '"<< $1 <<"' não declarada ou fora do escopo.\n";
                                                                                }
                                                                            } 
          expressao                                                         {
                                                                                if (find($1, CAT_VARIABLE))
                                                                                {
                                                                                    string type = getType($1, CAT_VARIABLE);
                                                                                    if (type == INT_TYPE && tmp == REAL_TYPE)
                                                                                    {
                                                                                        cout << MSG_BEGIN_ERROR << line_num << ": Possivel perda de precisão devido a atribuição de um real para um inteiro.\n";
                                                                                    }
                                                                                }
                                                                                tmp.clear();
                                                                            }
        | IDENT lista_arg                                                   {
                                                                                /* Procedure */
                                                                                if (!find($1, CAT_PROCEDURE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": procedimento '"<< $1 <<"' não declarado.\n";
                                                                                } else {
                                                                                    checkProcedureParameters($1, t_type_params);
                                                                                }   
                                                                            }
        | BEG comandos END                                                  {;}
        | FOR IDENT ATTRIBUTION numero TO numero DO BEG comandos END        {;}
        ;

/* REGRA 21: <condicao> ::= <expressao> <relacao> <expressao> */
condicao: expressao relacao expressao                                       {;}
        ;

/* REGRA 22: <relacao> ::= = | <> | >= | <= | > | < */
relacao : EQUAL                                                             {;}
        | DIF                                                               {;}
        | GREATER_EQUAL                                                     {;}
        | LESSER_EQUAL                                                      {;}
        | GREATER                                                           {;}
        | LESSER                                                            {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 23: <expressao> ::= <termo> <outros_termos> */
expressao   : termo outros_termos                                           {;}
            ;

/* REGRA 24: <op_un> ::= + | - | λ */
op_un   : PLUS                                                              {;}
        | MINUS                                                             {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 25: <outros_termos> ::= <op_ad> <termo> <outros_termos> | λ */
outros_termos: op_ad termo outros_termos                                    {;}
            | /*vazio*/                                                     {;}
            ;

/* REGRA 26: <op_ad> ::= + | - */
op_ad       : PLUS                                                          {;}
            | MINUS                                                         {;}
            ;

/* REGRA 27: <termo> ::= <op_un> <fator> <mais_fatores> */
termo       : op_un fator mais_fatores                                      {;}
            ;

/* REGRA 28: <mais_fatores> ::= <op_mul> <fator> <mais_fatores> | λ */
mais_fatores: op_mul fator mais_fatores                                     {
                                                                                 if (is_division)
                                                                                {
                                                                                    if (tmp2 == REAL_TYPE)
                                                                                    {
                                                                                        cout << MSG_BEGIN_ERROR << line_num << ": Divisão não é entre números inteiros, só é permitida a divisão entre números inteiros.\n";
                                                                                    }
                                                                                    tmp2.clear();
                                                                                    is_division = false;
                                                                                }
                                                                            }
            | /*vazio*/                                                     {;}
            ;

/* REGRA 29: <op_mul> ::= * | / */
op_mul      : MULT                                                          {;}
            | DIV                                                           {is_division = true;}
            ;

/* REGRA 30: <fator> ::= ident | <numero> | ( <expressao> ) */
fator       : IDENT                                                         {
                                                                                if (!find($1, CAT_VARIABLE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": variável '"<< $1 <<"' não declarada.\n";
                                                                                }

                                                                                if (find($1, CAT_VARIABLE))
                                                                                {
                                                                                    string tmp2 = getType($1, CAT_VARIABLE);
                                                                                    if (tmp != REAL_TYPE)
                                                                                        tmp = tmp2;
                                                                                }
                                                                                if (find($1, CAT_CONSTANT))
                                                                                {
                                                                                    string tmp2 = getType($1, CAT_CONSTANT);
                                                                                      if (tmp != REAL_TYPE)
                                                                                        tmp = tmp2;
                                                                                }
                                                                                tmp2 = tmp;
                                                                            }
            | numero                                                        {;}
            | OPEN_PAR expressao CLOSE_PAR                                  {;}
            ;

/* REGRA 31: <numero> ::= numero_int | numero_real */
numero      : INTEGER_NUMBER                                                {
                                                                                // printf("val: %s, text: %s\n", yylval, yytext);
                                                                                t_num = yylval.str;
                                                                                t_type = INT_TYPE;
                                                                                if (tmp.size() == 0)
                                                                                {
                                                                                    tmp = INT_TYPE;
                                                                                    tmp2 = tmp;
                                                                                }

                                                                            }
            | REAL_NUMBER                                                   {
                                                                                tmp = INT_TYPE;
                                                                                tmp2 = tmp;
                                                                                t_num = yylval.str;
                                                                                t_type = REAL_TYPE;
                                                                            }
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
    m["INTEGER_NUMBER"] = "numero inteiro";
    m["REAL_NUMBER"] = "numero real";
    m["INTEGER"] = "integer";
    m["REAL"] = "real";
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
    string strS = str;
    bool hasExpecting = true;
    if (strS.find("syntax error") != string::npos)
    {
        int pos = strS.find("expecting");
        if (pos == string::npos)
        {
            hasExpecting = false;
            pos = strS.find("unexpected");
            pos += 11;
        }
        else
        {
            pos += 10;
        }
        string expected;
        bool moreThanOneWord = false;
        string word;
        while (pos < strS.size())
        {

            if (expected.size() && !moreThanOneWord)
            {
                moreThanOneWord = true;
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

        if (moreThanOneWord)
        {
            expected += " também são opções validas )";
        }
        if (hasExpecting)
            printf("[Erro] Linha %d: Esperava-se encontrar %s porém encontrou-se '%s'\n", line_num, expected.c_str(), yylval.str); // qq coisa mudar yylval para yytext
        else
            printf("[Erro] Linha %d: %s inesperado\n", line_num, expected.c_str());
    }
    else
    {
        printf("%s\n",str);
    }
}


/*****************************************************************************************
                
                            Symbol Table functions 

*****************************************************************************************/

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope, int numParams) {
    if(DEBUG) cout << " >> Inserindo cadeia: " << cadeia << " | token: " << token << " | type: " << type << " | cat: " << cat << " | val: " << val << " | line: " << line << " | scope: " << scope << "\n";
    unordered_map<int, unordered_map<string, Element> >::iterator it;
    it = symbolTableVector.find(scope);
    
    if (it == symbolTableVector.end()) { // Is there a symbolTable to this scope?
        // Create a new symbolTable for this scope
        unordered_map<string, Element> symbolTable;
        pair<int, unordered_map<string, Element> > symbolTableVectorItem (scope, symbolTable);
        symbolTableVector.insert(symbolTableVectorItem);
    }
    
    /**
        it->first   : scope
        it->second  : symbolTable of the scope
    */
    it = symbolTableVector.find(scope);
    Element elem;
    elem.cadeia     = cadeia;
    elem.token      = token;
    elem.type       = type;
    elem.cat        = cat;
    elem.val        = val;
    elem.line       = line;
    elem.scope      = scope;
    elem.numParams  = numParams;
    pair<string, Element> tableItem (cadeia, elem);
    it->second.insert(tableItem);

}

bool find(int scope, string cadeia) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;

    it1 = symbolTableVector.find(scope);
    
    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            return true;
        }
    }
    return false;
}

void printSymbolTable() {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;

    cout << "\n>> Printing Symbol Tables from all scopes:" << "\n\n";

    for(it1 = symbolTableVector.begin(); it1 != symbolTableVector.end(); it1++){ // For each scope
        cout << "|SCOPE : " << it1->first << "\n";
        cout << " ________________________________________________________________________________ \n";
        cout << "|   CADEIA   |  TOKEN |   TYPE   |      CATEGORY      |   VAL  |  LINE  |  SCOPE |" << endl;
        cout << "|____________|________|__________|____________________|________|________|________|\n";
        for(it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {  
            printf("|%12s|%8d|%10s|%20s|%8s|%8d|%8d|\n", it2->second.cadeia.c_str(), it2->second.token, it2->second.type.c_str(), it2->second.cat.c_str(), it2->second.val.c_str(), it2->second.line, it2->second.scope);
        }
        cout << "|____________|________|__________|____________________|________|________|________|\n\n";
    }

    cout << "\n";
} 

// Search into the current scope and in the global scope (0)
bool find(string cadeia, string category) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;
    it1 = symbolTableVector.find(CURR_SCOPE);

    // current scope
    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            if (it2->second.cat == category) {
                return true;
            }
        }
    }

    // global scope
    it1 = symbolTableVector.find(0);

    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            if (it2->second.cat == category) {
                return true;
            }
        }
    }

    return false;
}


bool updateType(vector<string> cadeia, string type, int scope) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;
    it1 = symbolTableVector.find(scope);

    if (it1 != symbolTableVector.end()) {
        for (int i = 0; i < cadeia.size(); i++) {
            cout << " >> CADEIA: " << cadeia[i] << "\n";
            it2 = it1->second.find(cadeia[i]);
            if (it2 != it1->second.end()){
                printf("ATUALIZOU TIPO DE : %s   PARA : %s\n", cadeia[i].c_str(), type.c_str());
                it2->second.type = type;
            }
        }
        return true;
    }
    return false;
}

void printProcParameters(string procName) {
    unordered_map<string, vector<Element> >::iterator it;
    it = procParams.find(procName);
    if (it != procParams.end()){
        cout << " >> Parameters of the procedure " << procName << "\n";
        for (int i = 0; i < it->second.size(); i++) {
            cout << "\tcadeia: " << it->second[i].cadeia << " , type: " << it->second[i].type << "\n";
        }
    }
}

// Search into the current scope and in the global scope (0)
string getType(string cadeia, string category) {
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;
    it1 = symbolTableVector.find(CURR_SCOPE);

    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            if (it2->second.cat == category) {
                return it2->second.type;
            }
        }
    }

    // global scope
    it1 = symbolTableVector.find(0);

    if (it1 != symbolTableVector.end()) {
        it2 = it1->second.find(cadeia);
        if (it2 != it1->second.end()){
            if (it2->second.cat == category) {
                return it2->second.type;
            }
        }
    }
    return NULL;
}


// Check if the number of parameters is right and the type of the parameters
void checkProcedureParameters(string procName, vector<string> types) {
    if(DEBUG) printProcParameters(procName);


    unordered_map<string, vector<Element> >::iterator it;
    it = procParams.find(procName);
    if (it != procParams.end()){

        // Check the number of parameters:
        if (it->second.size() > types.size() || it->second.size() < types.size()) {
            cout << MSG_BEGIN_ERROR << line_num << ": Esperava-se " << it->second.size() << " argumento(s), mas encontrou-se " << types.size() << " argumento(s)\n";
            return;
        }

        // Check the type of the parameters:
        for (int i = 0; i < it->second.size(); i++) { // For each param
            if (it->second[i].type != types[i]){
                cout << MSG_BEGIN_ERROR << line_num << ": Tipo incompatível de argumento. Esperava-se tipo '" << it->second[i].type << "', mas o argumento " << i+1 << " é do tipo '" << types[i] << "'\n";
            }
            if (DEBUG) cout << "\tcadeia: " << it->second[i].cadeia << " , type: " << it->second[i].type << "\n";
        }
    }
}
/*****************************************************************************************/
