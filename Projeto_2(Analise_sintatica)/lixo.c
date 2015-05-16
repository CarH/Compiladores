/***************************************************************************************************
 *                                  Trabalho 1 - Analisador léxico
 *                      SCC0217 Linguagens de programação e compiladores       
 *                                 Prof. Dr. Diego Raphael Amancio
 ***************************************************************************************************
 *      Grupo:
 *          Bruno Daniel Sanches Silva              
 *          Carlos Humberto S Baqueta       
 *          Cláudio Domene                  
 ***************************************************************************************************/


#include <stdio.h>      // Entrada e saída
#include <stdlib.h>     // Manipulação de memória dinâmica
#include <string.h>     // Manipulação de strings
#include "myscanner.h"  // Inclusão de constantes e dados

extern int yylex();     // Função que retorna o id da cadeia lida, ver myscanner.h e myscanner.l
extern int yylineno;    // Contagem de linhas (não utilizamos pois não se adequa ao formato de saída exigido)
extern char *yytext;    // Ponteiro para o valor da cadeia de entrada lida
extern int yyparse();
// extern trie * root;


/**
 * Definição da estrutura que conterá as palavras reservadas
 */
/**
 *  alloc
 *  Alocação dinâmica de memória para os nós da TRIE
 *  @param **node : endereço do ponteiro que receberá o endereço do nó alocado
 */

/**
 *  insert
 *  Insere uma palavra na TRIE
 *  @param node : nó atual
 *  @param word : palavra a ser inserida
 */




/**
 *  initializeTrie
 *  Esta função é responsável por carregar as palavras reservadas do arquivo 
 *  palavras_reservadas.txt e popular a TRIE a partir delas.
 *  @return : 0 para sucesso e 1 para fallha
*/