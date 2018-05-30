#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main () {

	Aviao *voos = (Aviao *)malloc(sizeof(Aviao));

	if(!voos){

        printf("Sem memória disponível!\n");
        exit(1);
    } else {

    	voos = inicializa_lista();
    	voos = ler_e_insere_na_lista();
    	imprime(voos);
    }
}
