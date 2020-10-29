#include "backward.h"
//Função que cria
Backward *cria(){
    Backward *aux = (Backward*) malloc(sizeof(Backward));
    aux->ini = NULL;
    aux->fim = NULL;
    return aux;
}
// Função que libera a lista
void libera(Backward *list){
    if(list != NULL){
        No *aux = list->ini;
        while (aux != NULL){
            list->ini = list->ini->prox;
            free(aux);
            aux = list->ini;
        }
        free(list);
    }
}
// Função que insere na lista
int insere(Backward *list, int n, int j, int tempo){
    if(list == NULL)
        return 0;

    No *aux = (No*)malloc(sizeof(No));
    aux->chave = n;
    aux->tempo = tempo;
    aux->prox = NULL;
    
    if(list->ini == NULL){// Insere no início da lista
        aux->ant = NULL;
        list->ini = aux;
    }else{ // Insere no fim
        aux->ant = list->fim;
        list->fim->prox = aux;
    }
    list->fim = aux;

    if(j > 0){//Se o back aponta pra algum nó
        aux->back = list->fim;
        for(int i = 1; i <= j; i++)
            aux->back = aux->back->ant;
    }else
        aux->back = NULL;

    return 1;
}
// Função que extrai na lista
int extrai(Backward *list, int n){
    if(list == NULL)
        return 0;
    
    No *p = list->ini;
    No *ant = NULL;
    // Pecorre até achar o nó para ser extraido
    while (p != NULL && n != p->chave){
        ant = p;
        p = p->prox;
    }
    // Retira todos os ponteiros back referentes a esse nó
    No* aux = list->ini;
    while (aux != NULL){
        if(aux->back == p){
            aux->back = NULL;
        }
        aux = aux->prox;
    }

    if(p == NULL){
        return 0;
    }

    if(ant == NULL){ // Remoção do primeiro elemento
        list->ini = list->ini->prox;
        if(list->ini != NULL) list->ini->ant = NULL;
        else list->fim = NULL;
    }else{ // Remoção de elemento no meio ou no fim
        if(p->prox == NULL){ // remover do fim da lista
            list->fim = p->ant;
            ant->prox = NULL; 
        }else{ // Remover do meio da lista
            ant->prox = p->prox;
            p->prox->ant = ant;
        }
    }
    free(p);
    return 1;
}
// Função que acha a posição dos ponteiros back
int acha(No* ini, No* back){
    int count = 0;
    No *aux = ini;
    while(back != aux)
    {
        aux = aux->prox;
        count ++;
    }

    return count;
}
// Função que imprime a lista
void imprime(Backward *list){
    No *aux = list->ini;
    // Se estiver vazio
    if(aux == NULL){
        printf("-1\n");
        return;
    }

    while (aux != NULL){
        if(aux->back == NULL)
            printf("[%d,%d] ", aux->chave, aux->tempo);
        else
            printf("[%d,%d,%d] ", aux->chave, aux->tempo, acha(list->ini, aux->back));
        aux = aux->prox;
    }
    printf("\n");
    
}
// Função que faz todas as operações 
void operacao(Backward *list){
    int n = 0, j = 0, tempo = 0;
    char sel;

    while (TRUE){
        scanf("%c", &sel);
        if(sel == 'i'){
            scanf("%d %d", &n, &j);
            insere(list, n, j, tempo);
            tempo++;
        }else if(sel == 'r'){
            scanf("%d", &n);
            extrai(list, n);
            tempo++;
        }else if(sel == 'f'){
            break;
        }
    }
}