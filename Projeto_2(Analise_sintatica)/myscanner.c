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


/**
 * Definição da estrutura que conterá as palavras reservadas
 */
typedef struct trie trie;
struct trie
{
    trie * filhos[256]; // 256: uma saída(aresta) para cada caracter
    int hasWord;        // informa se é uma palavra reservada (1-sim, 0-não)
};

/**
 *  alloc
 *  Alocação dinâmica de memória para os nós da TRIE
 *  @param **node : endereço do ponteiro que receberá o endereço do nó alocado
 */
void alloc(trie ** node)
{
    (*node) = (trie *)malloc(sizeof(trie));

    int i;
    for (i = 0; i < 256; ++i)
        (*node)->filhos[i] = NULL;
    (*node)->hasWord = 0;
}

/**
 *  insert
 *  Insere uma palavra na TRIE
 *  @param node : nó atual
 *  @param word : palavra a ser inserida
 */
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

/**
 *  query
 *  Pesquisa se uma palavra está contida na TRIE ou não
 *  @param node : nó atual
 *  @param word : palavra a ser pesquisada
 *  @return : 1 caso esteja contida ou 0 caso contrário 
 */
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

trie* root; // Raiz da árvore TRIE


int main(int argc, char const *argv[]){
    int ntoken;
    int tam;

    /// Inicializa a TRIE apropriadamente
    if ( initializeTrie() ) { return 1; }
    ///

    return yyparse ( );
    ntoken = yylex();
    while (ntoken){

        if ( query(root, yytext) ){ // Checa se é palavra reservada
            printf("%s - %s\n", yytext, yytext);
        } else {
            
            switch(ntoken){
                case IDENT:
                    tam = strlen(yytext);
                    if (tam > MAIORTAMANHO)
                    {
                        printf("%s excede tamanho maximo de %d caracteres (Possui %d caracteres)\n",yytext,MAIORTAMANHO,tam);
                    }
                    else
                    {
                        printf("%s - ident\n", yytext);
                    }
                    break;
                case ERRODESC:
                    printf("%s - Caracter desconhecido\n", yytext);
                    break;
                case ERROINT:
                    printf("%s - Inteiro mal formado\n", yytext);
                    break;
                case ERROFLOAT:
                    printf("%s - Float mal formado\n", yytext);
                    break;
                case ERROIDENT:
                    printf("%s - Identificador mal formado\n", yytext);
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



/**
 *  initializeTrie
 *  Esta função é responsável por carregar as palavras reservadas do arquivo 
 *  palavras_reservadas.txt e popular a TRIE a partir delas.
 *  @return : 0 para sucesso e 1 para fallha
*/
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