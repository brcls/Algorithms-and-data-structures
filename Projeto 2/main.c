#include "rubronegra.h"
#define COUNT 10

void print2DUtil(No *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->dir, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d/%d\n", root->info, root->cor); 
  
    // Process left child 
    print2DUtil(root->esq, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(No *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 
  

int main(void) {
    RB *a = criar();
    
    int op = 0, qnt = 0;

    scanf("%d", &qnt);

    for(int i = 0; i < qnt; i++){
        scanf("%d", &op);
        operacao(op, a);
    }
    print2D(a->raiz); 
    destruir(a);

    return 0; // sucesso
}
