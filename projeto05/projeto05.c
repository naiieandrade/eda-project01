#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  
  	int valor;
  	int altura;
  	struct arvore* direita; 
  	struct arvore* esquerda; 
} Arvore;

/* Libera a arvore, destruindo seus filhos esquerdos e direitos antes */

Arvore *libera(Arvore *arvore) {

  	if (arvore != NULL) {
    	
    	libera(arvore->esquerda);
    	libera(arvore->direita);
    	free(arvore);
  	}

  	return NULL;
}

/* Pega a altura da arvore */

int	getHeight(Arvore *arvore) {

    if (arvore == NULL) {
        
        return 0;
    }
    
    return arvore->altura;
}

/* Verifica se a árvore é cheia ou não */

int isFull(Arvore* arvore) {
  
  	if(arvore==NULL) {

  		printf("Árvore vazia\n");
    	return 1;
  	}

  	if(arvore->esquerda == NULL && arvore->direita==NULL) {

  		printf("Árvore vazia\n");
    	return 1;
  	}

  	if((arvore->esquerda)&&(arvore->direita)) {

  		printf("Árvore cheia \n");
    	return (isFull(arvore->esquerda)&& isFull(arvore->direita));
  	}
}

/* Print in order*/
void printInOrder(Arvore* arvore) {
  
  	if(arvore != NULL) {
    
    	printInOrder(arvore->esquerda);
    	printf("%d ", arvore->valor);
    	printInOrder(arvore->direita);
  	}
}

/* Print in pre order */

void printPreOrder(Arvore* arvore) {
    
    if(arvore != NULL) {
        
        printf("%d ", arvore->valor);
        printPreOrder(arvore->esquerda);
        printPreOrder(arvore->direita);
    }
}



/* Print post-order */
void printPostOrder(Arvore* arvore) {

  	if(arvore != NULL){
    
    	printPostOrder(arvore->esquerda);
    	printPostOrder(arvore->direita);
    	printf("%d ", arvore->valor);
  	}
}



Arvore* cria_arvore() {
	  
  	return NULL;
}

void insere(Arvore** arvore, int valor) {
  
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

	arvore = loadTreeFromFile("bst1.txt");
	imprime(arvore);

	
}