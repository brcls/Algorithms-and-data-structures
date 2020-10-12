#include <stdio.h>
#include <string.h>
#include "fila.h"

int main(void) {
    // Uma fila para cada tipo de pessoa a ser atendida
    ponteiro filaPrio1;
    ponteiro filaPrio2;
    ponteiro filaPrio3;
    ponteiro filaPrio4;
    
    // Criando as filas
    filaPrio1 = cria();
    filaPrio2 = cria();
    filaPrio3 = cria();
    filaPrio4 = cria();

    // Execução
    acao(filaPrio1, filaPrio2, filaPrio3, filaPrio4);

    return 0; // sucesso
}