#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define CODIGO_AVIAO 7

struct aviao {

    char codigo[CODIGO_AVIAO];
    int combustivel;
    struct aviao *prox;
};
typedef struct aviao Aviao;

struct pista_de_decolagem {

	struct Aviao *inicio;
	struct Aviao *final;
};
typedef struct pista_de_decolagem Pista_de_decolagem;

Aviao *inicializa_lista (void){
  
    return NULL;
}

Aviao *insere_na_lista (Aviao *aviao, char codigo_aviao[CODIGO_AVIAO],int combustivelA) {

	Aviao *novo;

	novo = (Aviao*) malloc(sizeof(Aviao));
	strcpy(novo->codigo,codigo_aviao);
	novo->combustivel = combustivelA; 
	novo->prox = aviao;

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
        printf("Combustivel: %d\n", voos->combustivel);
    }

    printf("\n\n\n");
}

int gerar_numero(int lim_inf, int lim_sup){
	

	int result = 0;

	for (int aux = 0; aux < 1; aux ++) {
		result = (rand() % (lim_sup - lim_inf + 1)) + lim_inf;
	}

	return result;
}

int main () {

	int nVoos = 0,nAproximacoes = 0,nDecolagens = 0,combustivelA = 0;
	int uniTempo = 5;

    srand(time(0));

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

	Aviao *voos = (Aviao *)malloc(sizeof(Aviao));

	if(!voos){

        printf("Sem memória disponível!\n");
        exit(1);
    } else {

    	voos = inicializa_lista();
    	
		for(int aux = 0; aux < qtdeLinhas; aux ++) {

			fscanf(file, "%[^\n]\n", codigo);
			
			combustivelA = gerar_numero(0,12);
			voos = insere_na_lista(voos,codigo,combustivelA);
		}    	

    	imprime(voos);
    }

	fclose(file);

	nAproximacoes = gerar_numero(10,32);
	nDecolagens = gerar_numero(10,32);
	combustivelA = gerar_numero(0,12);
	nVoos = nAproximacoes + nDecolagens;
 
	printf("\n");	
	printf("Numero de voos: %d\n", nVoos);
	printf("Numero de aproximações: %d\n", nAproximacoes);
	printf("Numero de decolagens: %d\n", nDecolagens);
	printf("Numero combaA: %d\n", combustivelA);

    printf("HORA: %s\n",__TIME__);
}
