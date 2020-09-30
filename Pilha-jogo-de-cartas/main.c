#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha p;
    Pilha descarte;
    Pilha morto;

    Create(&p);
    Create(&descarte);
    Create(&morto);
    
    int aux = Escreve(&p);//Retorna o tamanho da pilha
    
    Jogo(&p, &descarte, &morto, aux);

    return 0; // sucesso
}
