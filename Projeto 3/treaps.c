#include "treaps.h"
// cria árvore
Treap *criarArvore(){
    Treap *a = malloc(sizeof(Treap));
    a->raiz = NULL;

    return a;
}
// cria fila
Fila *criaFila(){
    Fila *f = malloc(sizeof(Fila)); // instancia fila
    // define fila vazia
    f->ini = NULL;
    f->fim = NULL;

    return f;
}
// fila vazia?
int estaVazia(Fila *f){
    return (f->ini == NULL); // 1 = true, 0 = false
}
// entra na fila
void entra(Fila *f, No *p){
    // cria nó
    NoF *aux = malloc(sizeof(NoF));
    aux->arv = p; // aponta para o nó da árvore
    aux->prox = NULL;

    // atualiza ponteiros
    if (!estaVazia(f))
        f->fim->prox = aux;
    f->fim = aux;

    if (estaVazia(f))
        f->ini = aux;
}
// sai da fila
void sai(Fila *f){ 
    NoF *aux;

    if (estaVazia(f))
        return; // erro
        
    printf("(%d, %d) ", f->ini->arv->info, f->ini->arv->priori); // imprime nó que está no início
    
    aux = f->ini;          // guarda ponteiro a apagar
    f->ini = f->ini->prox; // atualiza encadeamento
    aux->arv = NULL; // aponta pra NULL
    free(aux); // apaga caixa
}
//esvazia fila
void esvazia(Fila *f){
    
    NoF *aux;

    while (f->ini != NULL) {
        aux = f->ini;
        f->ini = f->ini->prox;
        aux->arv = NULL; // aponta pra NULL
        free(aux);
    }

    // apaga fila
    free(f);
    f = NULL;
}

// destrói nós
void destruirNo(No *p){
    if (p != NULL){
        destruirNo(p->esq); // apaga lado esquerdo
        destruirNo(p->dir); // apaga lado direito
        free(p);
    }
}
// destrói árvore
void destruir(Treap *a){
    destruirNo((a)->raiz); // apaga nós
    free(a);
    a = NULL;
}

// cria nova caixa com dados recebidos por parametro
No *criarArvoreNo(int x, int priori){
    No *nova = malloc(sizeof(No));
    nova->info = x;
    nova->esq = NULL;
    nova->dir = NULL;
    nova->priori = priori;

    return nova;
}
// rotaciona para a esquerda
No *rotacionarE(No *p){
    No *aux = p->dir;
    p->dir = aux->esq;
    aux->esq = p;

    return aux;
}
// rotaciona para a direita
No *rotacionarD(No *p){
    No *aux = p->esq;
    p->esq = aux->dir;
    aux->dir = p;

    return aux;
}

int buscarSubarvore(No *p, int x){
    if (p == NULL)
        return 0; // nao achou
    
    if (p->info == x)
        return 1; // achou

    return (x < p->info) ? buscarSubarvore(p->esq, x) : buscarSubarvore(p->dir, x);
}

void buscar(Treap *a, int x){
    printf("%d\n", buscarSubarvore(a->raiz, x)); // inícia recursividade
}

No *inserirSubarvore(No *p, int x, int priori){
    // se for nó vazio
    if (p == NULL)
        return criarArvoreNo(x, priori); // cria e atualiza ponteiros

    if (x < p->info){ // se for menor, anda para a esquerda
        p->esq = inserirSubarvore(p->esq, x, priori);

        if (p->esq->priori > p->priori) // rotaciona em função da prioridade
            p = rotacionarD(p);
    }
    else if (x > p->info){ // se for maior, anda para a direita
        p->dir = inserirSubarvore(p->dir, x, priori);

        if (p->dir->priori > p->priori)// rotaciona em função da prioridade
            p = rotacionarE(p);
    }

    return p;
}

void inserir(Treap *a, int x, int priori){
    if (buscarSubarvore(a->raiz, x))
        printf("Elemento ja existente\n");
    else
        a->raiz = inserirSubarvore(a->raiz, x, priori); // inícia recursividade
}

No *removerSubarvore(No *p, int x){
    if (p == NULL)
        return p;

    if (x < p->info) // menor = anda para a esquerda
        p->esq = removerSubarvore(p->esq, x);
    else if (x > p->info) // maior = anda para a direita
        p->dir = removerSubarvore(p->dir, x);

    else if (p->esq == NULL){ // se filho esquerdo não existir, guarda direito e passa pro pai
        No *temp = p->dir;
        free(p);
        p = temp;
    }
    else if (p->dir == NULL){ // se filho direito não existir, guarda esquerdo e passa pro pai
        No *temp = p->esq;
        free(p);
        p = temp;
    }
    else if (p->esq != NULL && p->dir != NULL){ // caso tenha dois filhos, rotaciona para a esquerda e faz recursão
        p = rotacionarE(p);
        p->esq = removerSubarvore(p->esq, x);
    }
    else if (p->esq->priori < p->dir->priori){ // balanceia as prioridades
        p = rotacionarE(p);
        p->esq = removerSubarvore(p->esq, x);
    }

    return p;
}

void remover(Treap *a, int x){
    if (!buscarSubarvore(a->raiz, x))
        printf("Chave nao localizada\n");
    else
        a->raiz = removerSubarvore(a->raiz, x); // inícia recursividade
}

// imprime recursivamente
void preOrdemRecursivo(No *p){
    if (p == NULL)// sub-árvore vazia
        return; 

    printf("(%d, %d) ", p->info, p->priori);
    preOrdemRecursivo(p->esq); // processa lado esquerdo
    preOrdemRecursivo(p->dir); // processa lado direito
}

void preOrdem(Treap *a){
    preOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
}
// imprime recursivamente
void emOrdemRecursivo(No *p){
    if (p == NULL)// sub-árvore vazia
        return;         

    emOrdemRecursivo(p->esq); // processa lado esquerdo
    printf("(%d, %d) ", p->info, p->priori);
    emOrdemRecursivo(p->dir); // processa lado direito
}

void emOrdem(Treap *a){
    emOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
}
// imprime recursivamente
void posOrdemRecursivo(No *p){
    if (p == NULL)// sub-árvore vazia
        return;     
                   
    posOrdemRecursivo(p->esq); // processa lado esquerdo
    posOrdemRecursivo(p->dir); // processa lado direito
    printf("(%d, %d) ", p->info, p->priori);
}

void posOrdem(Treap *a){
    posOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
}

void larguraRec(No *p, Fila *f){
    
    if (p->esq != NULL) //se tiver filho esquerdo, aponta ele na fila
        entra(f, p->esq);
    if (p->dir != NULL)//se tiver filho direito, aponta ele na fila
        entra(f, p->dir);
     
    sai(f); // sai
    
    if (estaVazia(f)) // se a fila estiver vazia, volta a recursão
        return;
    
    if(f->ini->arv != NULL) // se o ponteiro do início da fila estiver apontando para algum nó da árvore
        larguraRec(f->ini->arv, f); // faz recursividade e passa o nó do início da lista
        
    return;
}

void largura(Treap *a){
    Fila *f = criaFila();// cria fila

    if (a->raiz != NULL){ // se existir uma árvore
        entra(f, a->raiz); // atribui a raiz
        larguraRec(a->raiz, f); // inícia recursão
        printf("\n");
    }
    esvazia(f);// esvazia fila
}
// operações
void operacao(Treap *a, char *string){

    int chave = 0, prioridade = 0;
    char *impressao = malloc(sizeof(char) * 50);

    if (strcmp(string, "insercao") == 0)
    {
        scanf("%d %d", &chave, &prioridade);
        inserir(a, chave, prioridade);

    }
    else if (strcmp(string, "remocao") == 0)
    {
        scanf("%d", &chave);
        remover(a, chave);
        
    }
    else if (strcmp(string, "buscar") == 0)
    {
        scanf("%d", &chave);
        buscar(a, chave);
    }
    else if (strcmp(string, "impressao") == 0)
    {
        scanf("%s", impressao);
        getchar();

        if (strcmp(impressao, "ordem") == 0)
            emOrdem(a);
        else if (strcmp(impressao, "posordem") == 0)
            posOrdem(a);
        else if (strcmp(impressao, "preordem") == 0)
            preOrdem(a);
        else if (strcmp(impressao, "largura") == 0)
            largura(a);
        
    }

    free(impressao);
}

