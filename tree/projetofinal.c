 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib.h"
#define cols 10
#define max_file 9


int menu(){
  int opt;

  printf("'-----------------------------'\n");
  printf("'        bem vindo            '\n");
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
  printf("9. pesquisar\n");
  printf("0. Sair\n");
  printf("\n\nOpção: ");
  scanf("%d", &opt);

  return opt;
}

char *choseFile(){
  int opt;
  char * arquivo;
  arquivo = malloc(sizeof(char)*9);
    printf("Escolha um arquivo válido [1-6]: \n");
    scanf("%d",&opt);

    switch (opt) {
      case 1:
        strcpy(arquivo,"BSTs/bst1.txt");
        //printf("%s\n", arquivo);
        break;
      case 2:
        strcpy(arquivo,"BSTs/bst2.txt");
        break;
      case 3:
        strcpy(arquivo,"BSTs/bst3.txt");
        break;
      case 4:
        strcpy(arquivo,"BSTs/bst4.txt");
        break;
      case 5:
        strcpy(arquivo,"BSTs/bst5.txt");
        break;
      case 6:
        strcpy(arquivo,"BSTs/bst6.txt");
        break;
      default:
      printf("Digite uma opcao valida (: \n\n");
    }
  return arquivo;
}


int * loadFile(char *arquivo, int *vetor){

  int valor = 0;
  char ch;

  FILE *file;
  file = fopen(arquivo, "r");

  rewind(file);
  if(file==NULL){
    printf("Falha!\n");
  } else {
    for(int aux=0; aux < cols; aux++){
      fscanf(file, "%d%*c", &vetor[aux]);
    }
  }

  printf("Os valores do arquivo sao: \n");
  for(int i=0;i<cols;i++)
    printf("%d ",vetor[i]);

  printf("\n\n");

  return vetor;
  //fclose(file);
}

Tree* loadTreeFromFile(Tree *root, char *arquivo){

  root = make_empty(root);

  FILE *file;
  file = fopen(arquivo, "r");
  rewind(file);
  int *valor;
  if(file==NULL){
    printf("Falha!\n");
  } else {
    for(int aux=0; aux < cols; aux++){
      fscanf(file, "%d%*c", &valor[aux]);
      root = insert(valor[aux], root);
    }
  }

  printf("O arquivo selecionado eh: %s \n\n", arquivo);

  fclose(file);

  return root;
}

void showTree(Tree * root){

  printf("Mostrar arvore:\n");
  print_ascii_tree(root);
  printf("\n\n");
}

void getHeight(Tree* root){
  int h = checkHeight(root);
  printf("\nAltura da arvore eh: %d\n\n\n",h);
}


void printInOrder(Tree * root){
  printf("Impressao da arvore em ordem:\n");
  inOrder(root);
  printf("\n\n\n");
}

void printPreOrder(Tree * root){
  printf("Impressao da arvore em pre ordem:\n");
  preOrder(root);
  printf("\n\n\n");
}

void printPostOrder(Tree * root){
  printf("Impressao da arvore em pos ordem:\n");
  postOrder(root);
  printf("\n\n\n");
}

void balanceTree(Tree * rootB, int * vetor){

  for(int aux=0; aux<cols; aux++){
    rootB = insertBalanced(rootB, vetor[aux]);
  }

  printf("\nArvore balanceada: \n\n");
  print_ascii_tree(rootB);
  printf("\n\n\n");

}
Tree *searchValue(Tree * root ,int key){
	if(root != NULL) {
		if(key == root->element) {
			printf("Data found!\n");
			return root;
		}
		else {
			if(key < root->element)
				return searchValue(root->left,key);
			else
				return searchValue(root->right,key);
		}
	}
	else {
		printf("Data not found!\n");
		return NULL;
	
	}
}Tree *searchValue(Tree * root ,int key){
	if(root != NULL) {
		if(key == root->element) {
			printf("Data found!\n");
			return root;
		}
		else {
			if(key < root->element)
				return searchValue(root->left,key);
			else
				return searchValue(root->right,key);
		}
	}
	else {
		printf("Data not found!\n");
		return NULL;
	
	}
}
/*
struct tree* search(int key,struct tree *leaf) {
	if(leaf != NULL) {
		if(key == leaf->data) {
			printf("Data found!\n");
			return leaf;
		}
		else {
			if(key < leaf->data)
				return search(key,leaf->left);
			else
				return search(key,leaf->right);
		}
	}
	else {
		printf("Data not found!\n");
		return NULL;
	}
}*/

int main(){
  int search_num =100;
  int pesquisar=0;	
  int * vetor;
  Tree * root;
  Tree * rootB;
  char *arquivo;

  root = NULL;
  rootB = NULL;

  make_empty(root);
  make_empty(rootB);

  int opt;
  do{
    opt=menu();

    switch (opt) {
      case 0:
        printf("Libera\n");
        break;
      case 1:
        arquivo = choseFile();
        vetor = calloc(cols,sizeof(int));
        vetor = loadFile(arquivo, vetor);
        root = loadTreeFromFile(root,arquivo);
        break;
      case 2:
        showTree(root);
        break;
      case 3:
        {
          if(isFullTree(root))
              printf("\n\nArvore é cheia. :) \n\n");
          else
              printf("\n\nArvore não é cheia. :( \n\n");
        };
        break;
      case 4:
        getHeight(root);
        break;
      case 5:
        printInOrder(root);
        break;
      case 6:
        printPreOrder(root);
        break;
      case 7:
        printPostOrder(root);
        break;
      case 8:
        balanceTree(rootB, vetor);
        break;
      case 9:
      		//scanf("%d",&search_num);
 			searchValue(root,search_num);
      		
      default:
        printf("Digite uma opcao valida (: \n\n");
    }
  } while(opt);
  return 0;

}
