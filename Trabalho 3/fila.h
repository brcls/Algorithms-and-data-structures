#define TAM 100
#define TAMSTR 100
// Pessoa
typedef struct {
    int idade;
    int saude;
    char nome[TAMSTR];
} Dados;
// Fila
typedef struct {
    int total, ini, fim;
    Dados *vet;
} Fila;

// Ponteiro
typedef Fila * ponteiro;

//Funções
ponteiro cria();
void escreve(Dados *x);
void print(Dados x);
int estaVazia(ponteiro f);
int estaCheia(ponteiro f);
void avanca(int *valor);
void acao(ponteiro filaPrio1, ponteiro filaPrio2, ponteiro filaPrio3, ponteiro filaPrio4);
void entraPrioriadade(ponteiro filaPrio1, ponteiro filaPrio2, ponteiro filaPrio3, ponteiro filaPrio4, Dados x);
void saiPrioridade(ponteiro filaPrio1, ponteiro filaPrio2, ponteiro filaPrio3, ponteiro filaPrio4, Dados x);
int insere(ponteiro fp, Dados x);
int extrai(ponteiro f, Dados *x);