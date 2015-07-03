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
// unordered_map<string, Element> symbolTable;

void insert(string cadeia, int token, string type, string cat, string val, int line, int scope, int numParams);
bool find(int scope, string cadeia);
bool updateType(vector<string> cadeia, string type, int scope);
void printSymbolTable();
int getNumberOfParams(string procName);
void printProcParameters(string procName);
Element getElement(string cadeia);
bool find(string cadeia, string category);
string getType(string cadeia, string category);


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
vector<string> t_cadeias;

/****************************************
|       Parameters of the Procedures    |
****************************************/
unordered_map<string, vector<Element> > procParams;
string curr_proc_name;
bool is_proc_parameter = false;
bool is_valid_procedure = false;
bool is_procedure = false;


string MSG_BEGIN_ERROR = "[Erro] Linha ";
/*****************************************************************************************/

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

/* REGRA 1: <programa> ::= program ident ; <corpo> . */
programa: PROGRAM IDENT SEMICOLON corpo ENDPOINT                           {   
                                                                                // CURR_SCOPE = 0;
                                                                                printf("IDENT: %d\n", IDENT);
                                                                                cout << "find(): "<< find(CURR_SCOPE, $2) << "\n";
                                                                                insert($2, IDENT, NONE, CAT_PROGRAM_NAME, NONE, line_num, CURR_SCOPE, 0);
                                                                                cout << "find(): "<< find(CURR_SCOPE, $2) << "\n";
                                                                                
                                                                                printSymbolTable();
                                                                            }

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
                                                                               // printf("numero: %s\n", $4);
                                                                                insert($2, IDENT, t_type, CAT_CONSTANT, t_num, line_num, CURR_SCOPE, 0);
                                                                                printSymbolTable();
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
                                                                                        // insert procedure parameter intro procParams
                                                                                        // TODO copiar isso pro INTEGER tbm !!!
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";
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
                                                                                        if (is_proc_parameter && is_valid_procedure){
                                                                                            // pair<string, vector<Element> > item ();
                                                                                            Element elem;
                                                                                            elem.cadeia = t_cadeias[i];
                                                                                            elem.type   = t_type;
                                                                                            unordered_map<string, vector<Element> >::iterator it;
                                                                                            it = procParams.find(curr_proc_name);
                                                                                            it->second.push_back(elem);
                                                                                            cout << " >> Inseriu " << t_cadeias[i] << " SCOPE: " << CURR_SCOPE << "\n";

                                                                                        }
                                                                                    }
                                                                                }
                                                                                t_cadeias.clear();
                                                                            }
        ;

/* REGRA 7: <variaveis> ::= ident <mais_var> */
variaveis: IDENT mais_var                                                   {
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
                                                                                printProcParameters(curr_proc_name);
                                                                            }

         SEMICOLON corpo_p                                                  {
                                                                                // TODO delete the symbolTable from the CURR_SCOPE
                                                                                CURR_SCOPE--;
                                                                                is_procedure = false;
                                                                            }

         dc_p                                                               {
                                                                                printf(" +++++ REGRA 9\n");
                                                                                // TODO atualizar numParams do procedimento na symbolTable!!
                                                                                int numParams = getNumberOfParams($2);
                                                                                
                                                                            }
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
lista_par : variaveis COLON tipo_var mais_par                               {; }
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
                                                                                t_type.clear();
                                                                            } 
          argumentos CLOSE_PAR                                              {;}
        | OPEN_PAR error CLOSE_PAR                                          {;}
        | /*vazio*/                                                         {;}
        ;

/* REGRA 16: <argumentos> ::= ident <mais_ident> */
argumentos : IDENT                                                          {
                                                                                if(find($1, CAT_VARIABLE)){
                                                                                    // t_type.push_back(getType($1, CAT_VARIABLE));// TODO
                                                                                } else {
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": " << $1 << " não foi declarado.\n";
                                                                                }
                                                                            }
            mais_ident                                               {;}
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
cmd     : READ OPEN_PAR variaveis CLOSE_PAR                                 {;}
        | WRITE OPEN_PAR variaveis CLOSE_PAR                                {;}
        | WHILE OPEN_PAR condicao CLOSE_PAR DO cmd                          {;}
        | IF condicao THEN cmd pfalsa                                       {;}
        | IDENT ATTRIBUTION                                                 {
                                                                                if (!find($1, CAT_VARIABLE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << ": variável não declarada.\n";
                                                                                }
                                                                            } 
          expressao                                                         {;}
        | IDENT                                                             {
                                                                                if (!find($1, CAT_PROCEDURE)){
                                                                                    cout << MSG_BEGIN_ERROR << line_num << " procedimento não declarado.\n";
                                                                                }
                                                                            }
          lista_arg                                                         {;}
        | BEG comandos END                                                  {;}
        | FOR IDENT ATTRIBUTION numero TO numero DO BEG comandos END        {;}
        ;

/* REGRA 21: <condicao> ::= <expressao> <relacao> <expressao> */
condicao: expressao relacao expressao                                      {;}
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
expressao   : termo outros_termos                                               {;}
            ;

/* REGRA 24: <op_un> ::= + | - | λ */
op_un   : PLUS                                                                  {;}
        | MINUS                                                                 {;}
        | /*vazio*/                                                             {;}
        ;

/* REGRA 25: <outros_termos> ::= <op_ad> <termo> <outros_termos> | λ */
outros_termos: op_ad termo outros_termos                                        {;}
            | /*vazio*/                                                         {;}
            ;

/* REGRA 26: <op_ad> ::= + | - */
op_ad       : PLUS                                                              {;}
            | MINUS                                                             {;}
            ;

/* REGRA 27: <termo> ::= <op_un> <fator> <mais_fatores> */
termo       : op_un fator mais_fatores                                          {;}
            ;

/* REGRA 28: <mais_fatores> ::= <op_mul> <fator> <mais_fatores> | λ */
mais_fatores: op_mul fator mais_fatores                                         {;}
            | /*vazio*/                                                         {;}
            ;

/* REGRA 29: <op_mul> ::= * | / */
op_mul      : MULT                                                              {;}
            | DIV                                                               {;}
            ;

/* REGRA 30: <fator> ::= ident | <numero> | ( <expressao> ) */
fator       : IDENT                                                             {;}
            | numero                                                            {;}
            | OPEN_PAR expressao CLOSE_PAR                                      {;}
            ;

/* REGRA 31: <numero> ::= numero_int | numero_real */
numero      : INTEGER_NUMBER                                                {
                                                                                // printf("val: %s, text: %s\n", yylval, yytext);
                                                                                t_num = yylval.str;
                                                                                t_type = INT_TYPE;

                                                                            }
            | REAL_NUMBER                                                       {
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

        printf("Linha %d: Esperava-se encontrar %s porém encontrou-se '%s'\n", line_num, expected.c_str(), yylval.str); // qq coisa mudar yylval para yytext
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

int getNumberOfParams(string procName) {
    unordered_map<string, vector<Element> >::iterator it;
    it = procParams.find(procName);
    if (it != procParams.end())
        return it->second.size();
    return 0;
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
    return NULL;
}

// Search into the current scope and in the global scope (0)
Element getElement(string cadeia){
    unordered_map<int, unordered_map<string, Element> >::iterator it1;
    unordered_map<string, Element>::iterator it2;

    it1 = symbolTableVector.find(CURR_SCOPE);
    if (it1 != symbolTableVector.end()){
        it2 = it1->second.find(cadeia);
        if(it2 != it1->second.end()){
            return it2->second;
        } else {
            // seach in the global scope:
            it1 = symbolTableVector.find(0);
            if (it1 != symbolTableVector.end()){
                it2 = it1->second.find(cadeia);
                if (it2 != it1->second.end()){
                    return it2->second;
                }
            }
        }

    }
    // return NULL;
}


// Check if the number of parameters is right and the type of the parameters
// void checkProcedureParameters(string procName, ) {

// }
/*****************************************************************************************/
