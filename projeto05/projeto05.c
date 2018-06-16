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

void showTree(Arvore* arvore) {

    printf("Mostrar arvore:\n");
    print_ascii_tree(arvore);
    printf("\n\n");
}

void isFull(Arvore* arvore) {

    isFullTree(arvore);
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

    printf("'-----------------------------'\n");
    printf("'        Bem Vindo            '\n");
    printf("'-----------------------------'\n");
    printf("Escolha alguma das opcoes:\n");
    printf("1. Carregar arquivo.\n");
    printf("2. Mostrar arvore.\n");
    printf("3. Verifica se a árvore é cheia.\n");
    printf("4. Verifica altura da arvore.\n");
    printf("5. Imprimir arvore em ordem.\n");
    printf("6. Imprimir arvore em pre ordem.\n");
    printf("7. Imprimir arvore em pos ordem.\n");
    printf("8. Mostrar arvore balanceada.\n");
    printf("0. Sair\n");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    return opcao;
}

int main () {

    Arvore *arvore;
    char * arquivo; 
    int opcao = 0;

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
        }
    } while(opcao != 0);
}