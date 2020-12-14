#include "rubronegra.h"
// verifica a cor do nó
int cor(No *p){
    return (p == NULL) ? BLACK : (p->cor == RED); 
}
// troca cor dos nós
void trocarCor(No *p){
    p->cor = !p->cor;// inverso da cor anterior
    if(p->esq != NULL)
        p->esq->cor = !p->esq->cor;
    if(p->dir != NULL)
        p->dir->cor = !p->dir->cor;
}
// cria árvore
RB *criar() {
    RB *a = malloc(sizeof(RB));
    a->raiz = NULL;
    return a;
}
// destrói nós
void destruirNo(No *p) {
    if (p != NULL){
        destruirNo(p->esq); // apaga lado esquerdo
        destruirNo(p->dir); // apaga lado direito
        free(p);
    }
}
// destrói árvore
void destruir(RB *a) {
    destruirNo((a)->raiz); // apaga nós
    free(a);
    a = NULL; 
}
// imprime recursivamente
void preOrdemRecursivo(No *p) {
    if (p == NULL)
        return; // sub-árvore vazia
    printf("%d ", p->info); 
    preOrdemRecursivo(p->esq); // processa lado esquerdo
    preOrdemRecursivo(p->dir); // processa lado direito
}

void preOrdem(RB *a) {
    preOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
}
// imprime recursivamente
void emOrdemRecursivo(No *p) {
    if (p == NULL)
        return; // sub-árvore vazia
    emOrdemRecursivo(p->esq); // processa lado esquerdo
    printf("%d ", p->info); 
    emOrdemRecursivo(p->dir); // processa lado direito
}

void emOrdem(RB *a) {
    emOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
}
// imprime recursivamente
void posOrdemRecursivo(No *p) {
    if (p == NULL)
        return; // sub-árvore vazia
    posOrdemRecursivo(p->esq); // processa lado esquerdo
    posOrdemRecursivo(p->dir); // processa lado direito
    printf("%d ", p->info); 
}

void posOrdem(RB *a) {
    posOrdemRecursivo(a->raiz); // inicia recursividade
    printf("\n");
}
// procura o mínimo
No *min(No* p){  

    while (p->esq != NULL) // vai para o extremo esquerdo da árvore
        p = p->esq; // retorna o nó

    return p;
}  
//procura o máximo
No *max(No* p){

    while (p->dir != NULL) // vai para o extremo direito da árvore
        p = p->dir;  
    
    return p; // retorna o nó
}  
// inicia recursão
void acharMax(RB *a){
    No* aux = max(a->raiz);
    printf("%d\n", aux->info);
}
// inicia recursão
void acharMin(RB *a){
    No* aux = min(a->raiz);
    printf("%d\n", aux->info);
}
// procura sucessor
No *sucessor(No *p, int chave){
    if (p == NULL) // se estiver vazio retorna nulo
        return NULL;
 
    No *aux = NULL; 

    while(p != NULL){// até o fim da árvore
        if(p->info == chave){ // se a chave existir na árvore
            
            if(p->dir) //se existir direito
                aux = min(p->dir); //ele está no menor valor da sub-árvore da direita
            
            return aux;
        }else if (chave < p->info){ // se a chave for menor que o info atual, vai para a sub-árvore da esquerda
            aux = p; // atualiza
            p = p->esq;
        } else{ // se for maior, para a direita
            p = p->dir;
        }
    }

    return aux;
}

No *predecessor(No *p, int chave){
    if (p == NULL)// se estiver vazio retorna nulo
        return NULL;
 
    No *aux = NULL;

    while (p != NULL){// até o fim da árvore
        if (p->info == chave){// se a chave existir na árvore
            
            if (p->esq)//se existir esquerdo
                aux = max(p->esq);//ele está no maior valor da sub-árvore da esquerda

            return aux;
        }else if(chave > p->info){// se a chave for maior que o info atual, vai para a sub-árvore da direita
            aux = p;// atualiza
            p = p->dir;
        }else{// se for menor, para a esquerda
            p = p->esq;
        }
            
    }

    return aux;
}
// inicia recursão
void acharSucessor(RB *a, int chave){
    No *suc = sucessor(a->raiz, chave);
    if(suc != NULL) // se corresponde, imprime
        printf("%d\n", suc->info);
    else
        printf("erro\n");
}
// inicia recursão
void acharPredecessor(RB *a, int chave){
    No *pre = predecessor(a->raiz, chave);
    if(pre != NULL)// se corresponde, imprime
        printf("%d\n", pre->info);
    else
        printf("erro\n");
}

// cria nova caixa com dados recebidos por parametro
No *criarNo(int x) {
    No *nova = malloc(sizeof(No));
    nova->info = x;
    nova->esq = NULL;
    nova->dir = NULL;
    nova->cor = RED;
    return nova;
}
// rotaciona para a esquerda
No *rotacionarE(No *p) {
    No *aux = p->dir;
    p->dir = aux->esq;
    aux->esq = p;
    aux->cor = p->cor;
    p->cor = RED;
    return aux;
}
// rotaciona para a direita
No *rotacionarD(No *p) {
    No *aux = p->esq;
    p->esq = aux->dir;
    aux->dir = p;
    aux->cor = p->cor;
    p->cor = RED;
    return aux;
}

No *inserirSubarvore(No *p, int x) {
    if (p == NULL)
        return criarNo(x); // cria e atualiza ponteiros
    
    if(x < p->info)// se for menor, anda para a esquerda
        p->esq = inserirSubarvore(p->esq, x);
    else if(x > p->info)// se for maior, anda para a direita
        p->dir = inserirSubarvore(p->dir, x);
    else
        return p;
    // caso o filho direito seja vermelho e o esquerdo preto, rotaciona para a esquerda
    if(cor(p->dir) == RED && cor(p->esq) == BLACK){
        p = rotacionarE(p);
    }
     // caso o filho esquerdo e o neto esquerdo sejam vermelho, rotaciona para a direita
    if(cor(p->esq) == RED && cor(p->esq->esq) == RED){
        p = rotacionarD(p);
    }
    // caso os dois filhos sejam vermelho
    if(cor(p->esq) == RED && cor(p->dir) == RED)
        trocarCor(p);

    return p;
}

void inserir(RB *a, int x) {
    a->raiz = inserirSubarvore(a->raiz, x); // inicia recursividade
    if(a->raiz != NULL) // raiz sempre preta
        a->raiz->cor = BLACK;
}

void operacao(int op, RB *a){
    int x = 0;
    switch (op){
        case 1:
            scanf("%d", &x);
            inserir(a, x);
            break;
        case 2:
            scanf("%d", &x);
            acharSucessor(a, x);
            break;
        case 3:
            scanf("%d", &x); 
            acharPredecessor(a, x);
            break;
        case 4:
            acharMax(a);
            break;
        case 5:
            acharMin(a);
            break;
        case 6:
            preOrdem(a);
            break;
        case 7:
            emOrdem(a);
            break;
        case 8:
            posOrdem(a);
            break;
    }
}
