#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
// Cria uma fila
ponteiro cria() {
    ponteiro fp = (ponteiro) malloc(sizeof(Fila));
    fp->vet = malloc(TAM * sizeof (Dados));
    fp->total = 0;
    fp->ini = 0;
    fp->fim = 0;
    return fp;
}
//Escreve dados da pessoa
void escreve(Dados *x){
    scanf("%s %d %d", x->nome, &x->idade, &x->saude);
}
//Imprime dados da pessoa
void print(Dados x){
    printf("%s %d %d\n", x.nome, x.idade, x.saude);
}
//Checa se esta vazia
int estaVazia(ponteiro f) {
    return (f->total == 0);
}
// Checa se esta cheia
int estaCheia(ponteiro f) {
    return (f->total == TAM);
}
//Avança início ou fim
void avanca(int *valor) {
    if (*valor == TAM - 1)
        *valor = 0; // reinicia
    else
        (*valor)++;
    return;
}
//Insere na fila desejada
int insere(ponteiro f, Dados x) {
    if (estaCheia(f)){
        printf("FILA CHEIA\n");
        return 1; // Erro
    }
     
    // Copia dados
    strcpy(f->vet[f->fim].nome, x.nome);
    f->vet[f->fim].idade = x.idade;
    f->vet[f->fim].saude = x.saude;
    
    f->total++; // Incrementa total
    avanca(&(f->fim)); // Avança fim
    return 0; // Sucesso
}
//Extrai da fila desejada
int extrai(ponteiro f, Dados *x) {
    // Copia dados
    strcpy(x->nome, f->vet[f->ini].nome);
    x->idade = f->vet[f->ini].idade;
    x->saude = f->vet[f->ini].saude;

    f->total--; // Decrementa total
    avanca(&(f->ini)); // Avança início
    return 0; // Sucesso
}
//Verifica em qual fila deve se entrar os dados
void entraPrioriadade(ponteiro filaPrio1, ponteiro filaPrio2, ponteiro filaPrio3, ponteiro filaPrio4, Dados x){
    if(x.idade >= 60 && x.saude == 1){//       Maior prioridade
        insere(filaPrio1, x);//                      .
    }else if (x.idade < 60 && x.saude == 1){
        insere(filaPrio2, x);//                      . 
    }else if (x.idade >= 60 && x.saude == 0){
       insere(filaPrio3, x);//                       .
    }else if (x.idade < 60 && x.saude == 0){// Menor prioriade
        insere(filaPrio4, x);
    }
}
//Verifica em qual fila deve se sair os dados
void saiPrioridade(ponteiro filaPrio1, ponteiro filaPrio2, ponteiro filaPrio3, ponteiro filaPrio4, Dados x){
    if(!estaVazia(filaPrio1)){ 
        extrai(filaPrio1, &x);
        print(x);
    }else if(!estaVazia(filaPrio2)){
        extrai(filaPrio2, &x);
        print(x);
    }else if(!estaVazia(filaPrio3)){
        extrai(filaPrio3, &x);
        print(x);
    }else if(!estaVazia(filaPrio4)){
        extrai(filaPrio4, &x);
        print(x);
    }else{ // Se todas as filas estiverem vazias, imprime
        printf("FILA VAZIA\n");
    }
    
}
// Executa as n ações 
void acao(ponteiro filaPrio1, ponteiro filaPrio2, ponteiro filaPrio3, ponteiro filaPrio4){
    char operacao[TAMSTR]; 
    int roda = -1;
    Dados x;
    scanf("%d", &roda);

    while(1){
        if(roda == 0){//Quando acabar as n ações, sai do while
            break;
        }
        
        scanf("%s", operacao);
        setbuf(stdin, NULL);
        
        if(strcmp (operacao, "ENTRA") == 0){
            escreve(&x);
            entraPrioriadade(filaPrio1, filaPrio2, filaPrio3, filaPrio4, x);
            roda--;
        }else if(strcmp (operacao, "SAI") == 0){
            saiPrioridade(filaPrio1, filaPrio2, filaPrio3, filaPrio4, x);
            roda--;
            
        }
        strcpy(operacao, " ");
    }
}