/***
 *      TODOs:
 *  - Tratamento de comentários;
 *
 */


#include <stdio.h>
#include <string.h>
#include "myscanner.h"

#define M 1337

extern int yylex(); 
extern int yylineno;
extern char *yytext;

int hashTable[M];
/*
 HASHCODE DAS PALAVRAS RESERVADAS USANDO A FC HASH ABAIXO C/ M = 1337
 program            760
 begin              517
 end                311
 var                329
 real               420
 integer            750
 procedure          969
 if                 207
 else               425
 read               412
 write              555
 while              537
 do                 211
 then               431
    OBS.: o token da palavra reservada é a propria palavra
*/

/// Hash para as palavras reservadas.
int hash (char *str){
    int i=0, hashCode=0;
    int size = strlen(str);
    // printf("size : %d\n", size);
    for (i = 0; i < size; i++) {
        hashCode = (hashCode + str[i])%M;
    }
    return hashCode;
}

void initializeHashTable (){
    int i=0;
    for (i = 0; i < M; i++){
        hashTable[i] = 0;
    }
    hashTable[760] = 1;
    hashTable[517] = 1;
    hashTable[311] = 1;
    hashTable[329] = 1;
    hashTable[420] = 1;
    hashTable[750] = 1;
    hashTable[969] = 1;
    hashTable[207] = 1;
    hashTable[425] = 1;
    hashTable[412] = 1;
    hashTable[555] = 1;
    hashTable[537] = 1;
    hashTable[211] = 1;
    hashTable[431] = 1;
}




int main(void){
    int ntoken, vtoken;
    int hc;

    ///
    initializeHashTable();
    ///

    ntoken = yylex();
    printf("PALAVRA RESERVADA\tHASHCODE\n");
    while (ntoken){
        // printf("token: %d linha:%d conteudo: %s\n",ntoken, yylineno, yytext);
        hc = hash(yytext);
        if ( hc < M ) {
            if ( hashTable[hc] ){
                printf("%s : %s\n", yytext, yytext);
            }
        }

        // printf(" %s\t\t    \t%d\n", yytext, hash(yytext));

        // if(ntoken == INTEGER_NUMBER){
        // 	printf("Encontrou INTEGER_NUMBER na linha %d, conteudo: %s\n", yylineno, yytext);
        //     // printf("Erro de sintaxe na linha %d, Se esperava um :, e encontrou-se %s", yylineno, yytext);
        // }
        
        // if(ntoken == REAL_NUMBER){
        //     printf("Encontrou REAL_NUMBER na linha %d, conteudo: %s\n", yylineno, yytext);
        //     // printf("Erro de sintaxe na linha %d, Se esperava um :, e encontrou-se %s", yylineno, yytext);
        // }
  


        ntoken = yylex();
    }

    return 0;
}

