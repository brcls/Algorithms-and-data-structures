#include "grandesNum.h"
// Função que torna verdadeiro o sinal se o número for falso
void negativo(Lista *l){
    l->sinal = TRUE;
}
// Função de criar lista
Lista *cria(){
    Lista *l = malloc(sizeof(Lista));
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
    l->sinal = FALSE;
    return l;
}
// Função que destrói lista
void destroi(Lista *l){
    if(l != NULL){
        No *p = l->ini;
        while (p != NULL) {
            l->ini = l->ini->prox;
            free(p);
            p = l->ini;
        }
        free(l);
    } 
}
// Função que destrói e cria outra lista
Lista* limpa(Lista *l){
    destroi(l);
    l = cria();
    return l;
}
// Função que insere no início
void insereInicio(Lista *l, int x){
    assert(l != NULL);
    No *p = malloc(sizeof(No));
    p->numero = x;
    p->prox = NULL;
    p->ant = NULL;
    
    p->prox = l->ini;
    if(l->ini != NULL) l->ini->ant = p;
    l->ini = p;
    
    if (l->fim == NULL) l->fim = p;
        
    l->tam++;
}
// Função que insere no fim
void insereFim(Lista *l, int x){
    if (l->fim == NULL && x == 0) 
        return;
    No *p = malloc(sizeof(No));
    p->numero = x;
    p->prox = NULL;
    p->ant = NULL;
    
    p->ant = l->fim;
    if (l->fim != NULL) l->fim->prox = p;
    l->fim = p;

    if (l->ini == NULL) l->ini = p;
    
    l->tam++;
}
// Função de imprimir lista
void imprime(Lista *l){
    assert(l != NULL);

    No *p = l->ini;
    while (p != NULL) {
        printf("%d", p->numero);
        p = p->prox;
    }
    printf("\n");
}
// Função soma os números
Lista *somaNum(Lista *n1, Lista *n2){
    No *p1 = n1->fim;
    No *p2 = n2->fim;

    Lista *total = cria(); // Total da soma

    int num = 0, carry = 0;

    while(p1 != NULL || p2 != NULL){
        //Se algum número já estiver "acabado", soma-se somente o número restante
        num = carry + (p1 ? p1->numero : 0) + (p2 ? p2->numero : 0); 
        //Caso passe de 10, como na lógica matemática
        carry = (num >= 10) ? 1 : 0;
        num = num%10;
        
        insereInicio(total, num);
          
        if(p1)
            p1 = p1->ant;
        if(p2)
            p2 = p2->ant;
    }
    if (carry > 0)
        insereInicio(total, carry);
    
    return total;
}
// Função que verifica se os números são iguais
int maiorMenor(Lista *n1, Lista *n2){
    if(n2->sinal > n1->sinal)// Se o sinal for TRUE, então n2 é negativo, logo, menor
        return 1;
    if(n1->tam > n2->tam) // Se for maior em tamanho
        return 1;
    
    No *p1 = n1->ini;
    No *p2 = n2->ini;
    
    while (p1 != NULL || p2 != NULL){
        if (p1->numero > p2->numero) //Se achar um número maior
            return 1;
        else
            return 0;

        p1 = p1->prox;
        p2 = p2->prox;
    }

    return 0;
}
// Função que verifica se os números são iguais
int igual(Lista *n1, Lista *n2){
    if (n1->sinal != n2->sinal) // Se um for ímpar, não são iguais
        return 0;
    if(n1->tam != n2->tam) // Se tiverem tamanhos diferentes
        return 0;

    No *p1 = n1->ini;
    No *p2 = n2->ini;
    
    while (p1 != NULL || p2 != NULL ){
        if (p1->numero != p2->numero) // Se achar um número diferente
            return 0;
        p1 = p1->prox;
        p2 = p2->prox;
    }

    return 1; //Se forem iguais
}
//Função que lê os números
void lerNumeros(Lista *n1, Lista *n2){
    //Strings auxiliares para transferir os números para as listas
    char *number1 = malloc(sizeof(char)*300);
    char *number2 = malloc(sizeof(char)*300);
    
    scanf("%[^ ]s", number1);
    getchar();
    scanf("%s", number2);

    for(int i = 0; i < strlen(number1); i++){
        if(number1[i] ==  '-') // Se for negativo, torna verdadeiro o sinal
            negativo(n1);
        else
            insereFim(n1, (int)number1[i] - '0'); //Char pra int pela tabela ASCII 
    }
    for(int i = 0; i < strlen(number2); i++){
        if(number2[i] ==  '-')
            negativo(n2);
        else
            insereFim(n2, (int)number2[i] - '0');
    }

    free(number1);
    free(number2);
}
//Função que seleciona as operações
void operacao(Lista *n1, Lista *n2, int num){
    char op[5];    
    for(int i = 0; i < num; i++){
        scanf("%s", op); //Qual operação
        getchar();
        lerNumeros(n1, n2);
        printf("Resultado %d: ", i+1);
        
        if(!strcmp(op, "sum"))
            imprime(somaNum(n1, n2));
        else if(!strcmp(op, "big"))
            printf("%d\n", maiorMenor(n1, n2));
        else if(!strcmp(op, "sml"))
            printf("%d\n", maiorMenor(n2, n1));
        else if (!strcmp(op, "eql"))
            printf("%d\n", igual(n1, n2));
        //Limpa e aloca novas listas
        n1 = limpa(n1);
        n2 = limpa(n2);
    }
}