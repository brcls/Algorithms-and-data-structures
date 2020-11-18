#include "grandesNum.h"
//main
int main(){
    Lista *num1 = cria();
    Lista *num2 = cria();
    int op;
    
    scanf("%d", &op); // Número de operações
    
    operacao(num1, num2, op); 
    
    return 0;
}