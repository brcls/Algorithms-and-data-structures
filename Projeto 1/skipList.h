// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define P 0.5 // Porcentagem de chance da execução do laço -> 50%
#define MAXLVL 24 // Número máximo de níveis

// Nó
typedef struct node {
    char verbe[50]; // Verbete
    char defin[140]; // Definição
    int level; // Nível do nó
    struct node** forward; //Arranjo de ponteiros para o próximo nó
}No;

// Skip list
typedef struct skiplist{
    No* header; // Cabeçalho da skip list
    int level; // Nível do cabeçalho
}Skip;

float randomize();
int randomLvl();
No* criarNo(int level, char verbe[50], char defin[140]);
Skip* criarSkip();
No* procurar(Skip* sl, char busca[50]);
void existe(Skip* sl, char busca[50]);
void alterar(Skip *sl, char busca[50], char alterar[140]);
void inserir(Skip* sl, char verbe[50], char defin[140]);
void apagarNo(No *x);
void remover(Skip *sl, char verbe[50]);
void print(Skip *l);
void impressao(Skip *sl, char ch);
void operacao(char op[15], Skip *sl);