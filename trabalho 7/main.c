#include "arvoreBinaria.h"

int main(void){
    Av *a = criarAv(); // Cria árvore binária
    
    int id = 0, x = 0, esq = 0, dir = 0;

    scanf("%d", &x);

    for(int i = 0; i < x; i++){
        scanf("%d %d %d", &id, &esq, &dir);
        
        if(i == 0) // Primeiro a ser inserido é a raiz
            insertRaiz(a, id);
    
        insertEsq(a, esq, id);
        insertDir(a, dir, id);
    }

    imprimir(a->raiz, a);

    return 0;
}