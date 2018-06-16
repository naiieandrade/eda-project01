#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_HEIGHT 1000
#define INFINITY (1<<20)

int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
int gap = 3;
int print_next;

typedef struct arvore {
  
    int valor;
    int altura;
    struct arvore* direita; 
    struct arvore* esquerda; 
} Arvore;

Arvore* libera(Arvore* arvore) {

    if (arvore != NULL) {
    
        libera(arvore->esquerda);
        libera(arvore->direita);
        free(arvore);
    }

    return NULL;
}

/* Acha a altura da arvore */
int height(Arvore *arvore) {
    
    if (arvore == NULL) {
        
        return 0;
    }

    return arvore->altura;
}

/*Acha elemento */
Arvore *find(int elem, Arvore *arvore) {
    
    if (arvore == NULL){
    
        return NULL;
    }

    if (elem < arvore->valor) {
    
        return find(elem, arvore->esquerda);
    } else if (elem > arvore->valor) {
    
        return find(elem, arvore->direita);
    } else {
    
        return arvore;
    }
}

Arvore* cria_arvore() {
    
    return NULL;
}

Arvore* insere(Arvore** arvore, int valor) {
  
    if(*arvore == NULL) {
      
        *arvore = (Arvore*)malloc(sizeof(Arvore)); 
        (*arvore)->esquerda = NULL; 
        (*arvore)->direita = NULL; 
        (*arvore)->valor = valor; 
    } else {

        if(valor < (*arvore)->valor) {

            insere(&(*arvore)->esquerda, valor);
        }

        if(valor > (*arvore)->valor) {

            insere(&(*arvore)->direita, valor);
        }
    }
}

Arvore *find_min(Arvore *arvore) {

    if (arvore == NULL){
    
        return NULL;
    } else if (arvore->esquerda == NULL) {
    
        return arvore;
    } else {
    
        return find_min(arvore->esquerda);
    }
}

Arvore * delete(int valor, Arvore * arvore) {
  
    Arvore *tmp_cell;

    if (arvore==NULL) {

        return NULL;
    }

    if (valor < arvore->valor) {
    
        arvore->esquerda = delete(valor, arvore->esquerda);
    } else if (valor > arvore->valor) {
    
        arvore->direita = delete(valor, arvore->direita);
    } else if (arvore->esquerda && arvore->direita) {
    
        tmp_cell = find_min(arvore->direita);
        arvore->valor = tmp_cell->valor;
        arvore->direita = delete(arvore->valor, arvore->direita);
    } else {
        
        tmp_cell = arvore;
        
        if (arvore->esquerda == NULL) {
        
           arvore = arvore->direita;
        } else if (arvore->direita == NULL) {
        
            arvore = arvore->esquerda;
        }
        free(tmp_cell);
    }

    return arvore;
}

typedef struct asciinode_struct asciinode;

struct asciinode_struct {
    
    asciinode * esquerda, * direita;

    int comprimento; /*edge_length*/
    int altura; /*altura */
    int lablen;
    int parent_dir;
    char label[11];
};


int MIN (int X, int Y) {
  
    return ((X) < (Y)) ? (X) : (Y);
}

int MAX (int X, int Y) {
    
    return ((X) > (Y)) ? (X) : (Y);
}

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

int arvore_vazia(Arvore* arvore) {
  
    return arvore == NULL;
}

void imprime(Arvore* arvore) {
  
    printf("<");
    if(!arvore_vazia(arvore)) {

      printf("%d \n", arvore->valor);
      imprime(arvore->esquerda);  
      imprime(arvore->direita);  
    }
     printf(">");
}

/* Função que verifica se um elemento pertence ou não à árvore */
int searchValue(Arvore* arvore, int valor) {
  
    if(arvore_vazia(arvore)) {
    
      return 0;
    }
  
    return arvore->valor==valor || searchValue(arvore->esquerda, valor) || searchValue(arvore->direita, valor);
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
    
    int opt;

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
    scanf("%d", &opt);

    return opt;
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
            loadTreeFromFile(arquivo);
            break;
        }
    } while(opcao != 0);
}