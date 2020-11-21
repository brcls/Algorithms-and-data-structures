#include "skipList.h"

int main(int argc, char* argv[]){
    
    Skip *l = criarSkip();
    char *op = calloc(15, sizeof(char));
    
    srand(time(0));
    
    while(!feof(stdin)){
        op = calloc(15, sizeof(char));
        scanf("%s", op);
        getchar();
        operacao(op, l);
        free(op);
    }

    return 0;
}