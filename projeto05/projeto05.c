#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct arvore {
  
  	int valor;
  	int altura;
  	struct arvore* direita; 
  	struct arvore* esquerda; 
} Arvore;

/*Necessario para fazer o showTree */

struct asciinode_struct{

  	asciinode * esquerda, * direita;

  	/*esquerda = left, direita = right */
  
  	int comprimento; /*edge_lenght*/
  	int altura; /*height*/
  	int lablen;
  	int parent_dir;
  	char label[11];
};
typedef struct asciinode_struct asciinode;

asciinode * build_ascii_tree(Arvore* arvore){
  
  	asciinode *node;
  	
  	if (arvore == NULL) {

  		return NULL;	
  	}

  	node = build_ascii_tree_recursive(t);
  	node->parent_dir = 0;
  	
  	return node;
}

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

void showTree(Arvore* arvore) {


}

void print_ascii_tree(Tree * t)
{
  asciinode *proot;
  int xmin, i;
  if (t == NULL) return;
  proot = build_ascii_tree(t);
  compute_edge_lengths(proot);
  for (i=0; i<proot->height && i < MAX_HEIGHT; i++)
  {
    lprofile[i] = INFINITY;
  }
  compute_lprofile(proot, 0, 0);
  xmin = 0;
  for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
  {
    xmin = MIN(xmin, lprofile[i]);
  }
  for (i = 0; i < proot->height; i++)
  {
    print_next = 0;
    print_level(proot, -xmin, i);
    printf("\n");
  }
  if (proot->height >= MAX_HEIGHT)
  {
    printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
  }
  free_ascii_tree(proot);
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