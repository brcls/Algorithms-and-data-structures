#include "skipList.h"

int main(int argc, char* argv[]){
    
    Skip *l = criarSkip();
    char op[15];
    
    srand(1247);
    
    while(!feof(stdin)){
        scanf("%s", op);
        getchar();
        operacao(op, l);
    }

    return 0;
}