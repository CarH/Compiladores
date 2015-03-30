/***************************************************************************************************
 *                                  Trabalho 1 - Analisador léxico
 *                      SCC0217 Linguagens de programação e compiladores       
 *                                 Prof. Dr. Diego Raphael Amancio
 ***************************************************************************************************
 *      Grupo:
 *          Bruno Sanches                   7
 *          Carlos Humberto S Baqueta       
 *          Cláudio Domene                  
 ***************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myscanner.h"

#define M 16381 

extern int yylex(); 
extern int yylineno;
extern char *yytext;

int hashTable[M];
/*
    OBS.: como o token da palavra reservada é a propria palavra, temos: 
        - hashTable[hashCode] = 1, se for palavra reservada
        - hashTable[hashCode] = 0, c.c.
*/

int hash (char *str);

int initializeHashTable ();

int main(int argc, char const *argv[]){
    int ntoken, vtoken;
    int hashCode;

    /// Inicializa hashTable apropriadamente
    if ( initializeHashTable() ) { return 1; }
    ///

    ntoken = yylex();
    while (ntoken){
        hashCode = hash(yytext);

        if ( hashCode > 0 && hashCode < M && hashTable [ hashCode ] ){ // Checa se é palavra reservada
            switch(hashCode){ // Eu sei, essa parte é mais pro t2, me empolguei...
                case PROGRAM:
                break;

                case BEGIN_:
                break;

                case END:
                break;
            }
            printf("PALAVRA RESERVADA: ");
            printf("%s - %s\n", yytext, yytext);
        } else {
            switch(ntoken){
                // TODO: INSERIR A REGRA EM myscanner.l, retornando os valores definidos em myscanner.h
                // e tratar a impressao dos tokens e msgs de erro aqui:
                case IDENT:
                    printf("%s - ident\n", yytext);
                    break;
                case ERRO:
                    printf("%s - erro\n", yytext);
                    break;
                case INTEGER_NUMBER:
                    printf("%s - numero_int\n", yytext);
                    break;
                case REAL_NUMBER:
                    printf("%s - numero_real\n", yytext);
                    break;
                case SEMICOLON:
                    printf("%s - ;\n", yytext);
                    break;  
                case ENDPOINT:
                    printf("%s - .\n", yytext);
                    break;  
                case ATTRIBUTION:
                    printf("%s - :=\n", yytext);
                    break;  
                case COLON:
                    printf("%s - :\n", yytext);
                    break;  
                case COMMA:
                    printf("%s - ,\n", yytext);
                    break; 
                case OPEN_PAR:
                    printf("%s - (\n", yytext);
                    break; 
                case CLOSE_PAR:
                    printf("%s - )\n", yytext);
                    break; 
                case PLUS:
                    printf("%s - +\n", yytext);
                    break; 
                case MINUS:
                    printf("%s - -\n", yytext);
                    break;
                case MULT:
                    printf("%s - *\n", yytext);
                    break; 
                case DIV:
                    printf("%s - /\n", yytext);
                    break; 
                case DIF:
                    printf("%s - <>\n", yytext);
                    break; 
                case GREATER_EQUAL:
                    printf("%s - >=\n", yytext);
                    break; 
                case LESSER_EQUAL:
                    printf("%s - <=\n", yytext);
                    break; 
                case GREATER:
                    printf("%s - >\n", yytext);
                    break; 
                case LESSER:
                    printf("%s - <\n", yytext);
                    break; 

            }
        }

        ntoken = yylex();
    }

    return 0;
}


/// Funcao hash:
int hash (char *str){
    char c;
    long long hashCode=0;

    while (c = *str++) {
        hashCode = ( ((hashCode<<5) + hashCode) + c )%M; /// hashCode = hashCode * 33 + c
    }

    return (int)hashCode;
}


/// Esta função é responsável por carregar as palavras reservadas do arquivo palavras_reservadas.txt 
/// e gerar a hashTable a partir delas.
int initializeHashTable (){
    FILE *fp;
    int i=0;
    char word[1000];

    if ( (fp = fopen("palavras_reservadas.txt", "r")) == NULL ){
        fprintf(stderr, "Nao foi possivel encontrar o arquivo de palavras reservadas. Verifique se o arquivo 'palavras_reservadas.txt' encontra-se no diretorio atual.\n");
        return 1;
    }

    /// Insere 0s em toda a hashTable
    for (i = 0; i < M; i++)
        hashTable[i] = 0;

    while ( fscanf (fp, "%s", word) != EOF ){
        hashTable[ hash (word) ] = 1;   /// Marca 1 no hashCode da palavra reservada
        // printf("palavra reservada: %10s  |  hashCode: %d\n", word, hash(word) );
    }

    fclose(fp);
    return 0;
}