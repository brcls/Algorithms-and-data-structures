#include "treaps.h"

int main(void){
    
    Treap *a = criarArvore();

    int qnt = 0;

    scanf("%d", &qnt);

    for (int i = 0; i < qnt; i++){

        char *string = calloc(20, sizeof(char));
        
        scanf("%s", string);
        getchar();

        operacao(a, string);

        free(string);
    }

    destruir(a);

    return 0; // sucesso
}