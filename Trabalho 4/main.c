#include "lista.h"
#include <stdio.h>

int main(void){
    int t, n, m;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){  
        scanf("%d %d", &n, &m);
        printf("Caso %d: ", i+1);
        CriarLista(n, m);
    }
    
    return 0; // sucesso
}