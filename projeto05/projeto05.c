#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

Arvore* loadTreeFromFile(char arquivo[]) {

    int valor = 0;

    FILE *file;

    Arvore* arvore = cria_arvore(); 

    file = fopen(arquivo, "r");

        if(file==NULL){

        printf("Falha!\n");
    } else {

        for(int aux = 0; aux < 10; aux ++) {
      
            fscanf(file, "%d ", &valor);
            insere(&arvore,valor);
        }
    }

    fclose(file);

    return arvore;
}

int getHeight(Arvore *arvore) {

    if(arvore == NULL || (arvore->esquerda == NULL && arvore->direita == NULL)) {

        return 0;
    } else {

        return 1 + maior(getHeight(arvore->esquerda),getHeight(arvore->direita));
    }
}

void showTree(Arvore* arvore) {

    printf("Mostrar arvore:\n");
    print_ascii_tree(arvore);
    printf("\n\n");
}

void isFull(Arvore* arvore) {

    isFullTree(arvore);
}

int searchValue(Arvore* arvore, int valor) {
  
    if(arvore_vazia(arvore)) {
    
      return 0;
    }
  
    return arvore->valor == valor || searchValue(arvore->esquerda, valor) || searchValue(arvore->direita, valor);
}

Arvore* removeValue(Arvore* arvore,int valor) {

    Arvore* arvore_removida;

    arvore_removida = delete(valor,arvore);

    return arvore_removida;
}

void printInOrder(Arvore* arvore){

    if(arvore != NULL){
    
        printInOrder(arvore->esquerda);
        printf("%d ", arvore->valor);
        printInOrder(arvore->direita);
    }
}

void printPreOrder(Arvore* arvore) {
    
    if(arvore != NULL) {

        printf("%d ", arvore->valor);
        printPreOrder(arvore->esquerda);
        printPreOrder(arvore->direita);
    }
}

void printPostOrder(Arvore* arvore){

    if(arvore != NULL){
    
        printPostOrder(arvore->esquerda);
        printPostOrder(arvore->direita);
        printf("%d ", arvore->valor);
    }
}

char *escolhe_arquivos() {

    int opcao;
    char * arquivo;
    arquivo = malloc(sizeof(char)*9);

    do {

      printf("Escolha um arquivo válido [1-6]: \n");
      printf("1 - Arquivo bst1.txt \n");
      printf("2 - Arquivo bst2.txt \n");
      printf("3 - Arquivo bst3.txt \n");
      printf("4 - Arquivo bst4.txt \n");
      printf("5 - Arquivo bst5.txt \n");
      printf("6 - Arquivo bst6.txt \n");

      printf("\n\nOpção: ");
      scanf("%d",&opcao);

    } while(opcao < 1 || opcao > 6);
    

    switch (opcao) {

        case 1:

          strcpy(arquivo,"bst1.txt");
        break;
        
        case 2:
        
          strcpy(arquivo,"bst2.txt");
        break;
        
        case 3:
        
          strcpy(arquivo,"bst3.txt");
        break;
        
        case 4:
        
          strcpy(arquivo,"bst4.txt");
        break;
        
        case 5:
        
          strcpy(arquivo,"bst5.txt");
        break;
        
        case 6:
        
          strcpy(arquivo,"bst6.txt");
        break;
    }

    return arquivo;
}

int menu(){
    
    int opcao;

    printf("\n\n");
    printf("'-----------------------------'\n");
    printf("'        Bem Vindo            '\n");
    printf("'-----------------------------'\n");
    printf("Escolha alguma das opcoes:\n");
    printf("1. Carregar arquivo.\n");
    printf("2. Mostrar arvore.\n");
    printf("3. Verifica se a árvore é cheia.\n");
    printf("4. Procurar valor.\n");
    printf("5. Verifica altura da arvore.\n");
    printf("6. Remover valor.\n");
    printf("7. Imprimir arvore em ordem.\n");
    printf("8. Imprimir arvore em prá ordem.\n");
    printf("9. Imprimir arvore em pós ordem.\n");
    printf("10. Mostrar arvore balanceada.\n");
    printf("0. Sair\n");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    return opcao;
}

int main () {

    Arvore *arvore;
    char * arquivo; 
    int opcao = 0;
    int valor = 0;

    do {

        opcao = menu();

        switch(opcao) {

            case 1:
        
                arquivo = escolhe_arquivos();
                arvore = loadTreeFromFile(arquivo);
            break;

            case 2:

                showTree(arvore);
            break;

            case 3:
                
                isFull(arvore);
            break;

            case 4:

                printf("\n\n");
                
                printf("Insira o valor que deseja pesquisar na árvore \n");
                scanf("%d",&valor);

                if(searchValue(arvore, valor)) {

                    //COLOCAR O NIVEL DO NÓ
                    //MELHORAR ESSA PORRA
                    printf("\n" );
                    printf("Valor do pai: %d\n", arvore->valor);

                    /*if(arvore->esquerda != NULL) {

                        printf("Valor a esquerda: %d\n",arvore->esquerda);
                    } if(arvore->direita != NULL) {

                        printf("Valor a direita: %d\n", arvore->direita);
                    }*/
                    
                } else {
                
                    printf("\nO NÚMERO %d NÃO PERTENCE A ÁRVORE!\n\n",valor);
                }
                
            break;

            case 5:

                printf("Altura da árvore: %d\n", getHeight(arvore));
            break;

            case 6:

                printf("Insira o valor que deseja remover da árvore\n");
                scanf("%d",&valor);

                if(searchValue(arvore, valor)) {

                    arvore = removeValue(arvore,valor);

                } else {

                    printf("\nO NÚMERO %d NÃO PERTENCE A ÁRVORE!\n\n",valor);   
                }

            break;

            case 7:

                printf("Arvore em ordem\n");
                printInOrder(arvore);
            break;

            case 8:

                printPreOrder(arvore);
            break;

            case 9:

                printPostOrder(arvore);
            break;

        }
    } while(opcao != 0);
}