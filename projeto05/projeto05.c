#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  
  	int valor;
  	struct arvore* sub_direita; 
  	struct arvore* sub_esquerda; 
} Arvore;

Arvore* cria_arvore() {
	  
  	return NULL;
}

int arvore_vazia(Arvore* arvore) {
  
  	return arvore == NULL;
}

void insere(Arvore** arvore, int valor) {
  
  	if(*arvore == NULL) {
    	
    	*arvore = (Arvore*)malloc(sizeof(Arvore)); 
    	(*arvore)->sub_esquerda = NULL; 
    	(*arvore)->sub_direita = NULL; 
    	(*arvore)->valor = valor; 
  	} else {

    	if(valor < (*arvore)->valor) {
    	/* Se o número for menor então vai pra esquerda */
      	/* Percorre pela subárvore à esquerda */
      		insere(&(*arvore)->sub_esquerda, valor);
    	}
    	if(valor > (*arvore)->valor) {
    	/* Se o número for maior então vai pra direita */
      	/* Percorre pela subárvore à direita */
      		insere(&(*arvore)->sub_direita, valor);
    	}
  	}
}

void imprime(Arvore* arvore) {
  
  	if(!arvore_vazia(arvore)) {

    	printf("%d \n", arvore->valor); /* mostra a raiz */
    	imprime(arvore->sub_esquerda); /* mostra a sae (subárvore à esquerda) */
    	imprime(arvore->sub_direita); /* mostra a sad (subárvore à direita) */
  	}
}

int main () {

	char arquivo [] = "bst1.txt";
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

	imprime(arvore);

	fclose(file);
}