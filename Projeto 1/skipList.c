#include "skipList.h"

/* Funçao auxiliar que imprime a lista completa

void print(Skip *l){
    No* x = l->header;
    printf("LISTA COMPLETA\n");
    while (x && x->forward[0] != l->header) {
        if(x->forward[0]){
            printf("---- %s %s ----\n", x->forward[0]->verbe, x->forward[0]->defin);
        }
        x = x->forward[0];
    }
}
*/
// Função que gera números aleatórios entre 0-1
float randomize(){
    float result = 0.0;

    result = ((float)rand())/(float)(RAND_MAX);

    return result;
}
// Cria nível de tamanho aleatório, até TAMLVL
int randomLvl(){
    int result = 1;

    while(randomize() < P && result < MAXLVL)
        result++;
    
    return result;
}
// Cria nó
No* criarNo(int level, char verbe[50], char defin[140]){
    No* p = malloc(sizeof(No)); //Ponteiro do nó

    p->level = level; //Nível do nó

    p->forward = malloc((level+1)*sizeof(No*)); // Alocando o arranjo, com tamanho do nível
    
    //Inicializando o arranjo com null
    for(int i = 0; i < (p->level+1); i++)
        p->forward[i] = NULL;
    
    //Atribuindo os dados para o nó
    strcpy(p->verbe, verbe);
    strcpy(p->defin, defin);

    return p;
}
// Cria skip list
Skip* criarSkip(){
    Skip* p = malloc(sizeof(Skip));// Ponteiro da lista

    p->header = criarNo(MAXLVL, "null", "null"); //Criando o cabeçalho da lista, com nível máximo

    p->level = 0; //Nível da skip list sendo 0

    return p;
}

No* procurar(Skip* sl, char busca[50]){

    No* x = sl->header; // Aponta para o cabeçalho
    
    //Do nível mais alto para o mais baixo
    for(int i = x->level; i >= 0; i--){
        
        //Enquanto não achou o verbete e forward[i] não é null
        while(x->forward[i] != NULL && strcmp(x->forward[i]->verbe, busca) < 0)
            x = x->forward[i];
    
    }

    x = x->forward[0];

    //Retorna ponteiro, que pode ou não estar apontando para o verbete procurado

    return (No*)x;
}

//Funçao que busca verbete desejado
void existe(Skip* sl, char busca[50]){
    No* p = procurar(sl, busca); //Ponteiro que pode ou não estar apontando para o verbete
    
    if(p != NULL){//Verifica se é diferente de null
        if(strcmp(p->verbe, busca) == 0){ // Se o verbete do ponteiro condiz com o procurado
            printf("%s %s\n", busca, p->defin);
            return; //Sai da função
        }
    }
    // Se não o achar
    printf("OPERACAO INVALIDA\n");
}
// Função que altera definição
void alterar(Skip *sl, char busca[50], char alterar[140]){
    No *p = procurar(sl, busca);//Ponteiro que pode ou não estar apontando para o verbete

    if(p != NULL){ // Verifica se é diferente de null
        if(strcmp(p->verbe, busca) == 0){ // Se o verbete do ponteiro condiz com o procurado
            memset(p->defin, 0, strlen(p->defin));
            strcpy(p->defin, alterar); // Troca
            return; //Sai da função
        }
    }
    // Se não o achar
    printf("OPERACAO INVALIDA\n");
}
// Função de inserção
void inserir(Skip* sl, char verbe[50], char defin[140]){
    
    //Arranjo que atualiza os nós de forward
    No *update[MAXLVL+1];
    
    for(int i = 0; i < MAXLVL+1; i++)
        update[i] = NULL;

    //Aponta para o cabeçalho
    No* x = sl->header;

    int level = x->level; // Nível do cabeçalho

    //Do nível mais alto para o mais baixo
    for(int i = level; i >= 0; i--){

        //Enquanto não achou o verbete e forward[i] não é null
        while(x->forward[i] != NULL && strcmp(x->forward[i]->verbe, verbe) < 0)
            x = x->forward[i];
        
        // Guarda o nó que vai ser atualizado
        update[i] = x;
    }

    x = x->forward[0];

    // Caso ponteiro seja null ou x->verbe não seja igual ao verbete a ser inserido
    if(x == NULL || strcmp(x->verbe, verbe) != 0){

        int novoLvl = randomLvl(); //Nível do novo nó

        //Caso o novo nível seja maior que o nível da skip list  
        if(novoLvl > level){

            // Atualiza o update para que aponte para o cabeçalho da lista
            // entre a seu nível e o nível do novo nó
            for(int i = level + 1; i <= novoLvl; i++){
                update[i] = sl->header;
            }

            //Atualiza o nível do skip list
            sl->level = novoLvl;
        }

        // Cria o novo nó
        x = criarNo(novoLvl, verbe, defin);

        // Inserindo o novo nó na skip list
        for(int i = 0; i <= novoLvl; i++){
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }else
        printf("OPERACAO INVALIDA\n");
}

// Apagar nó
void apagarNo(No *x){
    if(x){
        free(x->forward);
        free(x);
    }  
}

void remover(Skip *sl, char verbe[50]){
    
    //Arranjo que atualiza os nós de forward
    No *update[MAXLVL+1];

    for(int i = 0; i < MAXLVL+1; i++)
        update[i] = NULL;

    //Aponta para o cabeçalho
    No *x = sl->header;

    int level = x->level;// Nível do cabeçalho

    //Do nível mais alto para o mais baixo
    for(int i = level; i >= 0; i--){

        //Enquanto não achou o verbete e forward[i] não é null
        while(x->forward[i] != NULL && strcmp(x->forward[i]->verbe, verbe) < 0)
            x = x->forward[i];

        // Guarda o nó que vai ser atualizado
        update[i] = x;
    }

    x = x->forward[0];

    // Caso ponteiro seja diferente null ou x->verbe
    // seja igual ao verbete a ser apagado
    if(x != NULL && strcmp(x->verbe, verbe) == 0){
        
        // Atualiza os ponteiros da skip list
        for(int i = 0; i <= level; i++){
            if(update[i]->forward[i] != x)
                break;

            update[i]->forward[i] = x->forward[i];
        }
        
        //Apagar nó
        apagarNo(x);

        //Diminuir tamanho do nível da skip list
        while(level > 1 && sl->header->forward[level] == sl->header)
            sl->level--;

    }else
        printf("OPERACAO INVALIDA\n");
}

// Função que imprime as verbetes e suas definições a partir de um char
void impressao(Skip *sl, char ch){
    No* x = sl->header; // Aponta para o cabeçalho
    int flag = 0; // Se há pelo menos uma palavra que comece com o char
    
    while (x && x->forward[0] != sl->header){ // Percorre os ponteiros
        if(x->forward[0]){ //Caso não seja null
            if(x->forward[0]->verbe[0] == ch){ //Verifica se o primeiro char da verbe é igual ao ch
                printf("%s %s\n", x->forward[0]->verbe, x->forward[0]->defin); // Imprime
                flag = 1; //Caso exista pelo menos uma palavra começada com ch
            }
        }
        x = x->forward[0]; // Anda
    }

    if(!flag)
        printf("NAO HA PALAVRAS INICIADAS POR %c\n", ch);

}

//Função que chama todas as operações
void operacao(char op[15], Skip *sl){
    char ch, string1[50], string2[140];

    if(strcmp(op, "insercao") == 0){
        scanf("%s %[^\n\t]s", string1, string2);
        getchar();
        inserir(sl, string1, string2);
    } 
    else if(strcmp(op, "alteracao") == 0){
        scanf("%s %[^\n\t]s", string1, string2);
        getchar();
        alterar(sl, string1, string2);
    }
    else if(strcmp(op, "remocao") == 0){
        scanf("%s", string1);
        getchar();
        remover(sl, string1);
    }
    else if(strcmp(op, "busca") == 0){
        scanf("%s", string1);
        getchar();
        existe(sl, string1);
    } 
    else if(strcmp(op, "impressao") == 0){
        scanf("%c", &ch);
        getchar();
        impressao(sl, ch);
    }
}