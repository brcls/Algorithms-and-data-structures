#include <stdlib.h>
#include <stdio.h>

#define RED 1 // define vermelho como 1
#define BLACK 0 // define preto como 0

typedef struct no {
    int info;
    struct no *esq, *dir;
    int cor;
}No;

typedef struct rubroNegra{
    No *raiz;
}RB;

int cor(No *p);
void trocarCor(No *p);
RB *criar();
void destruirNo(No *p);
void destruir(RB *a);
void preOrdemRecursivo(No *p);
void preOrdem(RB *a);
void emOrdemRecursivo(No *p);
void emOrdem(RB *a);
void posOrdemRecursivo(No *p);
void posOrdem(RB *a);
No *min(No* p);
No *max(No* p);
void acharMax(RB *a);
void acharMin(RB *a);
No *sucessor(No *p, int chave);
No *predecessor(No *p, int chave);
void acharSucessor(RB *a, int chave);
void acharPredecessor(RB *a, int chave);
No *criarNo(int x);
No *rotacionarE(No *p);
No *rotacionarD(No *p);
No *inserirSubarvore(No *p, int x);
void inserir(RB *a, int x);
void operacao(int op, RB *a);