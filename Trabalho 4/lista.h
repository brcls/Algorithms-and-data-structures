typedef struct no {
    int posicao;
    struct no *next;
}Node;

Node *novoNo(int posicao);
void CriarLista(int n, int m);