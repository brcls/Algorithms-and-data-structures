#define TAM 100000

typedef struct {
    int vet[TAM];
    int topo;
} Pilha;

// cria pilha
void Create(Pilha *p);

// esta vazia?
int IsEmpty(Pilha p); // parametro passado por valor

// esta cheia?
int IsFull(Pilha *p); // parametro passado por referecia

// insere na pilha
int Push(Pilha *p, int x);

// remove da pilha
int Pop(Pilha *p, int *x);

//Execução do jogo
void Jogo(Pilha *p, Pilha *descarte, Pilha *morto, int aux);

//Empilha a pilha ao contrário da entrada
int Escreve(Pilha *p);
    