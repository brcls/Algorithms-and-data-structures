#include "substring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Funçao de substituição
char* Substitui(char* frase, char* acha, char* troca){
    char* result; 
    int i, cnt = 0; 
    int tamTroca = strlen(troca); 
    int tamAcha = strlen(acha); 

    // Conta quantas vezes a palavra a ser trocada aparece na frase
    for (i = 0; frase[i] != '\0'; i++){ 
        if (strstr(&frase[i], acha) == &frase[i]){ 
            cnt++; 
            i += tamAcha - 1;
        } 
    } 
    // Nova string com tamanho adequado 
    result = (char*)malloc(i + cnt * (tamTroca - tamAcha) + 1); 
    i = 0;
    // Troca das palavras 
    while (*frase){ 
        if (strstr(frase, acha) == frase){ 
            strcpy(&result[i], troca); 
            i += tamTroca; 
            frase += tamAcha; 
        } 
        else
            result[i++] = *frase++; 
    } 
  
    result[i] = '\0'; 
    return result; 
}
// Função que lê as strings e chama a função de substituição, de impressão e de free
void Escreve(){ 
    char *acha = NULL;
    char *troca = NULL;
    char *frase = NULL;
    char *stringFinal = NULL;
    int c;
    // Alocando as strings
    acha = Aloca(acha, 20);
    troca = Aloca(troca, 20);
    frase = Aloca(frase, 100);
    stringFinal = Aloca(stringFinal, 100);

    scanf("%[^\n]", frase);
    scanf("%*[^\n]"); scanf("%*c");
    scanf("%[^\n]", acha);
    scanf("%*[^\n]"); scanf("%*c");
    scanf("%[^\n]", troca);
    scanf("%*[^\n]"); scanf("%*c");

    stringFinal = Substitui(frase, acha, troca);
    Imprimir(stringFinal);
    // se EOF, não faz a recursão para as próximas strings
    if(scanf("%d",&c) != EOF){
        Escreve();
    }
}
// Função de alocação 
char* Aloca(char* palavra, int n){
    palavra = malloc(sizeof(char)*n);
    return palavra;        
}
// Função de impressão
void Imprimir(char *frase){
    printf("%s\n", frase);
}
