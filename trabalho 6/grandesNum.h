#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

typedef struct no{
    int numero;
    struct no *prox, *ant;
}No;

typedef struct lista{
    No *ini, *fim;
    int sinal, tam;
}Lista;

void negativo(Lista *l);
Lista *cria();
void destroi(Lista *l);
Lista* limpa(Lista *l);
void insereInicio(Lista *l, int x);
void insereFim(Lista *l, int x);
void imprime(Lista *l);
Lista *somaNum(Lista *n1, Lista *n2);
int maiorMenor(Lista *n1, Lista *n2);
int igual(Lista *n1, Lista *n2);
void lerNumeros(Lista *n1, Lista *n2);
void operacao(Lista *n1, Lista *n2, int num);
    
   