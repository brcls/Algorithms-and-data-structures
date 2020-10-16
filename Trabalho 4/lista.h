//Estrutura
typedef struct no {
    int posicao;
    struct no *next;
}Node;
//Cria novo no
Node *novoNo(int posicao);
//Cria lista
void CriarLista(int n, int m);
//Se o pulo for 1
Node *Suicidio(Node **head);
//Se o pulo for maior que 1
void Sobrevivente(Node *head, int m);
