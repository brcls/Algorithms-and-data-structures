#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

typedef struct no{
    int chave, tempo;
    struct no *ant, *prox, *back;
}No;

typedef struct backward{
    No *ini, *fim;
}Backward;

Backward *cria();//Função que cria
void libera(Backward *list);// Função que libera a lista
void operacao(Backward *list);// Função que faz todas as operações 
int insere(Backward *list, int n, int j, int tempo); // Função que insere na lista
int extrai(Backward *list, int n);// Função que extrai na lista
void imprime(Backward *list); // Função que imprime a lista
int acha(No* ini, No* back);// Função que acha a posição dos ponteiros back