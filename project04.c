#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CODIGO_AVIAO 7

struct aviao {

    char codigo[CODIGO_AVIAO];
    int combustivel;
    struct aviao *prox;
};
typedef struct aviao Aviao;

Aviao *inicializa_lista (void){
  
    return NULL;
}

Aviao *insere_na_lista (Aviao *aviao, char codigo_aviao[CODIGO_AVIAO]) {

	Aviao *novo;

	novo = (Aviao*) malloc(sizeof(Aviao));
	strcpy(novo->codigo,codigo_aviao); 
	novo->prox = aviao;

	return novo;
}

Aviao *ler_e_insere_na_lista () {

	Aviao *novo = (Aviao*) malloc(sizeof(Aviao));
	char codigo[CODIGO_AVIAO];
	char arquivo [] = "codigo_de_voos.txt";
	int qtdeLinhas = 0;
	char caracteres;

	FILE *file;
	
	file = fopen(arquivo, "r");

  	if(file==NULL){
	    
	    printf("Falha!\n");
	} else {

		while((caracteres=fgetc(file))!=EOF){
	      	
	      	if(caracteres=='\n'){
	        
	        	qtdeLinhas++;
	        } 
	    }		
	}

	qtdeLinhas +=1;

	rewind(file);

	for(int aux = 0; aux < qtdeLinhas; aux ++) {

		fscanf(file, "%[^\n]\n", codigo);
		
		novo = insere_na_lista(novo,codigo);
	}

	fclose(file);				
	return novo;
}

void imprime(Aviao *aviao){

    Aviao *voos;

    if(aviao==NULL) {
        
        printf("\n\nNão possui nenhum registro :(\n");
    } else {

        printf("\n\nVisualizar registros:\n");    
    }
    
    for(voos=aviao; voos!=NULL; voos=voos->prox){
        
        printf("Código: %s\n", voos->codigo);
    }

    printf("\n\n\n");
}

int gerar_numero(int lim_inf, int lim_sup){
	
	return (lim_inf + (rand() % lim_sup));
}

int main () {

	int nVoos = 0,nAproximacoes = 0,nDecolagens = 0,combaA = 0;

	nAproximacoes = gerar_numero(10,32);
	nDecolagens = gerar_numero(10,32);
	combaA = gerar_numero(0,12);
	nVoos = nAproximacoes + nDecolagens;

	/*Aviao *voos = (Aviao *)malloc(sizeof(Aviao));

	if(!voos){

        printf("Sem memória disponível!\n");
        exit(1);
    } else {

    	voos = inicializa_lista();
    	voos = ler_e_insere_na_lista();
    	imprime(voos);
    }*/

    srand(time(NULL));
	
	printf("Numero de voos: %d\n", nVoos);
	printf("Numero de aproximações: %d\n", nAproximacoes);
	printf("Numero de decolagens: %d\n", nDecolagens);
	printf("Numero combaA: %d\n", combaA);

    printf("HORA: %s\n",__TIME__);
}
