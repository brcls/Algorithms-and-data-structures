#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no{
    int info;//dado
    int priori;//prioridade
    struct no *esq, *dir;
}No;

typedef struct noFila{
    No *arv;// ponteiro para o nó da árvore
    struct noFila *prox;
} NoF;

typedef struct fila{
    NoF *ini, *fim;
} Fila;

typedef struct treaps{
    No *raiz;
} Treap;

Treap *criarArvore();
Fila *criaFila();
int estaVazia(Fila *f);
void entra(Fila *f, No *p);
void sai(Fila *f);
void esvazia(Fila *f);
void destruirNo(No *p);
void destruir(Treap *a);
No *criarArvoreNo(int x, int priori);
No *rotacionarE(No *p);
No *rotacionarD(No *p);
int buscarSubarvore(No *p, int x);
void buscar(Treap *a, int x);
No *inserirSubarvore(No *p, int x, int priori);
void inserir(Treap *a, int x, int priori);
No *removerSubarvore(No *p, int x);
void remover(Treap *a, int x);
void preOrdemRecursivo(No *p);
void preOrdem(Treap *a);
void emOrdemRecursivo(No *p);
void emOrdem(Treap *a);
void posOrdemRecursivo(No *p);
void posOrdem(Treap *a);
void larguraRec(No *p, Fila *f);
void largura(Treap *a);
void operacao(Treap *a, char *string);