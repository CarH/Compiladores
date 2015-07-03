#ifndef _MYSCANNER_
#define _MYSCANNER_
#define MAIORTAMANHO 30

typedef struct trie trie;
struct trie
{
    trie * filhos[256]; // 256: uma saída(aresta) para cada caracter
    int hasWord;        // informa se é uma palavra reservada (1-sim, 0-não)
};

typedef struct token token;

void yyerror (const char *s);


#endif