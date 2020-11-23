#include "arvoreBinaria.h"
// Criar árvore binária
Av *criarAv(){
    Av *a = (Av*)malloc(sizeof(Av));
    a->raiz = NULL;
    return a;
}
// Finaliza árvore 
void finalizar(No *raiz){
    if(raiz){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}
// Cria nó da árvore 
No* criarNo(int id) {
    No* novo = malloc(sizeof(No));
    novo->id = id;
    // Filhos apontando pra null
    novo->esq = NULL; 
    novo->dir = NULL;

    return novo;
}
//Busca pai de um nó
No *buscaPai(No *raiz, int id){

    if(raiz == NULL || (raiz->esq && raiz->esq->id == id) || (raiz->dir && raiz->dir->id == id))
        return raiz; // Achou o elemento ou sub-árvore vazia

    //Busca recursivamente
    No *p = buscaPai(raiz->esq, id);
    return(p != NULL) ? p : buscaPai(raiz->dir, id); 
}
// Busca nó
No *buscaNo(No *raiz, int id){

    if(raiz == NULL || raiz->id == id)
        return raiz; // Achou o elemento ou sub-árvore vazia

    //Busca recursivamente
    No *p = buscaNo(raiz->esq, id);
    return(p != NULL) ? p : buscaNo(raiz->dir, id);
}
//Insere raiz
void insertRaiz(Av *a, int id) {
    if (a->raiz == NULL) // Se a raiz não existir
        a->raiz = criarNo(id); // Cria nó da raiz
}
//Insere filho esquerdo
void insertEsq(Av *a, int id, int pai) {
    No *novo = buscaNo(a->raiz, pai); //Busca pai
    
    if(id == -1) //Caso não vá ter filho esquerdo
        return;
    
    //Pai não existe ou ele já tem um filho esquerdo
    if (novo == NULL || novo->esq != NULL)
        return; 
    
    novo->esq = criarNo(id); // Cria filho esquerdo

}
//Insere filho direito
void insertDir(Av *a, int id, int pai) {
    No *novo = buscaNo(a->raiz, pai); //Busca pai

    if(id == -1) //Caso não vá ter filho direito
        return;

    //Pai não existe ou ele já tem um filho direito
    if (novo == NULL || novo->dir != NULL)
        return; 

    novo->dir = criarNo(id); // Cria filho direito

}
//Acha altura do nó
int acharAltura(No *p) {
    int altEsq, altDir;
    
    if (p == NULL) //Sub-árvore nula
        return 0;
    
    altEsq = acharAltura(p->esq); 
    altDir = acharAltura(p->dir);
    
    return (altEsq > altDir) ? altEsq + 1 : altDir + 1;
}

//Acha grau do nó
int acharGrau(No *p){
    if(p->esq == NULL && p->dir == NULL){
        return 0;
    }else if(p->esq == NULL && p->dir != NULL){
        return 1;
    }else if(p->esq != NULL && p->dir == NULL){
        return 1;
    }else if(p->esq != NULL && p->dir != NULL){
        return 2;
    }
}
// Acha o tipo do nó
char *acharTipo(No *raiz, int id, int grau){
    char *aux = malloc(sizeof(char)*20);
    if(raiz->id == id)
        strcpy(aux, "raiz");
    else if(!grau)
        strcpy(aux, "folha");
    else
        strcpy(aux, "interno");
    
    return aux;
}
// Acha o pai do nó e checa se é a raiz
int acharPai(No *raiz, int id){
    
    No *pai = buscaPai(raiz, id);

    return(raiz->id == id) ? -1 : pai->id; // se for a raiz retorna -1
}
// Verifica se o filho esquerdo está vazio
int checarEsq(No *p){
    return(p->esq == NULL) ? -1 : p->esq->id;
}
// Verifica se o filho direito está vazio
int checarDir(No *p){
    return(p->dir == NULL) ? -1 : p->dir->id;
}
//Função que imprime a árvore binária
void imprimir(No *p, Av *a) {
     
    if (p != NULL) {
        //Atribui os dados
        int pai = acharPai(a->raiz, p->id);
        int altura = acharAltura(p);
        int grau = acharGrau(p);
        int esq = checarEsq(p);
        int dir = checarDir(p);
        char *tipo = acharTipo(a->raiz, p->id, grau);

        printf("no %d: pai = %d, altura = %d, grau = %d, filhos = (%d,%d), tipo = %s\n", p->id, pai, altura, grau, esq, dir, tipo);

        //Percorre pelas sub-árvores recursivamente    
        imprimir(p->esq, a);
        imprimir(p->dir, a);
    }
    
}