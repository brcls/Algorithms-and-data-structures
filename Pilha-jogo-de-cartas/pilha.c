#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

// Cria pilha
void Create(Pilha *p) {
    p->topo = -1;
    return;
}
// Está vazia?
int IsEmpty(Pilha p) { // Parâmetro passado por valor
    return (p.topo == -1);
}
// Está cheia?
int IsFull(Pilha *p) { // Parâmetro passado por referência
    return (p->topo == TAM-1);
}
// Insere na pilha
int Push(Pilha *p, int x) {
    if (IsFull(p))
        return 1; // Erro, pilha cheia
    p->topo++; // Atualiza o topo
    p->vet[p->topo] = x; // Copia informação
    return 0; // Sucesso
}
// Remove da pilha
int Pop(Pilha *p, int *x) {
    if (IsEmpty(*p))
        return 1; // Erro, pilha vazia
    *x = p->vet[p->topo]; // Copia informação
    p->topo--; // Atualiza o topo
    return 0; // Sucesso
}
//Empilha a pilha ao contrário da entrada
int Escreve(Pilha *p){
    int n = 0;
    scanf("%d", &n);
    int aux[100];// Vetor auxiliar

    for(int i = 0; i < n; i++){
        scanf("%d", &aux[i]);// Escreve primeiro o vetor
    }
    for(int j = n-1; j >= 0; j--){
        Push(p, aux[j]);// Passa ele invertido para a pilha
    }
    return n;// Retorna o tamanho da pilha
}
// Execução do jogo
void Jogo(Pilha *p, Pilha *descarte, Pilha *morto, int aux){
    int count = 1, x, rodada = 0;
    int i;
    
    while (morto->vet[morto->topo] != aux){ // Laço por rodada
        while (!IsEmpty(*p)) { // Laço de desempilhar p pra pilha morto ou pra pilha descarte
            if(p->vet[p->topo] == count){ // Se achou 1...2...3
                Pop(p, &x);
                Push(morto, x);
                count++;// Incrementa o próximo número da sequência
            }else{
                Pop(p, &x);
                Push(descarte, x);
            }
        }   
        while (!IsEmpty(*descarte)) { //Empilha as cartas do descarte na pilha p de compra
            Pop(descarte, &x);
            Push(p, x);
        }
        rodada++; // Incrementa a rodada
    }
    printf("%d\n", rodada);
}