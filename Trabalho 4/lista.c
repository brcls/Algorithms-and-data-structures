#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
//Cria novo nó
Node *novoNo(int posicao){ 
   Node *temp = (Node*)malloc(sizeof(Node)); 
   temp->next = temp; 
   temp->posicao = posicao; 
}
// Se o pulo for maior que um, vê o sobrevivente
void Sobrevivente(Node *head, int m){
   Node *ponteiro = head, *aux = head; 
   
   while (ponteiro->next != ponteiro){ 
      //Anda na lista a quantidade do pulo (m)
      for(int i = 0; i < m-1; i++){ 
         aux = ponteiro; 
         ponteiro = ponteiro->next;
      }

      //Remove o nó dessa posição
      aux->next = ponteiro->next; 
      free(ponteiro); 
      ponteiro = aux->next;
   }

   printf ("%d\n", ponteiro->posicao);
}
// Elimina a cabeça da lista
Node *Suicidio(Node **head){
   Node *temp = *head;
	
   if((*head)->next == *head) {  
      *head = NULL;
      return temp;
   }     

   *head = (*head)->next;
	
   return temp;
}
// Cria lista e faz o problema
void CriarLista(int n, int m){
   Node *temp = NULL;
   Node *head = NULL; 
   Node *prev = NULL;
   //Cria uma lista com n posições
   for (int i = 1; i <= n; i++){ 
      if(head == NULL){//Se for o primeiro da lista
         head = novoNo(i);
         prev = head;
      }else{
         prev->next = novoNo(i);
      }
      prev = prev->next; 
   } 
   prev->next = head; // Conecta o último com o primeiro
   
   if(m == 1){// Checa se o pulo é um
      for(int i = 0; i < n; i++){ // Elimina um por um até n
         temp = Suicidio(&head);
      }
      printf ("%d\n", temp->posicao);
   }else{
      Sobrevivente(head, m); 
   }
} 
