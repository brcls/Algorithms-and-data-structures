#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int id;
    struct node* esq;
    struct node* dir;
}No;

typedef struct arvore{
    No *raiz;
}Av;

Av *criarAv();
int vazia(Av *a);
void finalizar(No *raiz);
No* criarNo(int id);
No *buscaPai(No *n, int id);
No *buscaNo(No *raiz, int id);
void insertRaiz(Av *a, int id);
void insertEsq(Av *a, int id, int pai);
void insertDir(Av *a, int id, int pai);
int acharAltura(No *p);
int acharGrau(No *p);
char *acharTipo(No *raiz, int id, int grau);
int acharPai(No *raiz, int id);
int checarEsq(No *p);
int checarDir(No *p);
void imprimir(No *p, Av *a);