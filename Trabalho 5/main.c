#include "backward.h"

int main(void){
    Backward *list = cria();

    operacao(list);
    imprime(list);
    libera(list);

    return 0;
}