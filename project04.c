#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define CODIGO_AVIAO 7

struct aviao {
 	
 	char codigo[CODIGO_AVIAO];
 	int combustivel;
 	struct aviao* prox;
};
typedef struct aviao Aviao;

struct fila {
 	
 	Aviao* inicio;
 	Aviao* final;
};
typedef struct fila Fila;

Fila* cria ();
void push (Fila* fila, char codigo[CODIGO_AVIAO],int combustivel);
char pop (Fila* fila);
int vazia (Fila* fila);
void libera (Fila* fila);

Fila* cria () {
 
 	Fila* fila = (Fila*) malloc(sizeof(Fila));
 	fila->inicio = fila->final = NULL;
 	
 	return fila;
}

Aviao* ins_fim (Aviao* final, char codigo[CODIGO_AVIAO],int combustivel) {
 
 	Aviao* novo = (Aviao*) malloc(sizeof(Aviao));
 	
 	strcpy(novo->codigo,codigo);
 	novo->combustivel = combustivel;
 	novo->prox = NULL;
 	
 	if (final != NULL) { 
 		
 		final->prox = novo;
 	}

 	return novo;
}

Aviao* retira_inicio (Aviao* inicio) {
 	
 	Aviao* aviao = inicio->prox;
 	
 	free(inicio);
 	
 	return aviao;
}

void push (Fila* fila, char codigo[CODIGO_AVIAO],int combustivel) {
 
 	fila->final = ins_fim(fila->final,codigo,combustivel);
 
 	if (fila->inicio == NULL) {

 		fila->inicio = fila->final;
	}
}

char pop (Fila* fila) {

 	float v;
 	char retirado;
 	
 	if (vazia(fila)) {
 		
 		printf("Fila vazia.\n");
 		exit(1); 
 	}

 //v = f->ini->info;
 	fila->inicio = retira_inicio(fila->inicio);
 	
 	if (fila->inicio == NULL) { 
 		
 		fila->final = NULL;
 	}

 	return retirado;
}

int vazia (Fila* fila) {
 	
 	return (fila->inicio == NULL);
}

void libera (Fila* fila) {
 
 	Aviao* aviao = fila->inicio;
 	
 	while (aviao != NULL) {
 		
 		Aviao* t = aviao->prox;
 		free(aviao);
 		aviao = t;
 	}

 	free(fila);
}

void imprime (Fila* fila) {
 	
 	Aviao* aviao;
 	
 	for (aviao=fila->inicio; aviao!= NULL; aviao=aviao->prox){
 		
 		printf("Nome: %s\n", aviao->codigo);
 		printf("Combustivel: %d\n", aviao->combustivel);
	}
}

int main () {

 	Fila* fila = cria();
 	push(fila,"Victor",42);
 	push(fila,"Isabela",42);
 	push(fila,"Naruto",42);
 	push(fila,"teste",42);

 	printf("Fila:\n");
 	imprime(fila);
 	libera(fila);
 	
 	return 0;
}

/*struct aviao {

    char codigo[CODIGO_AVIAO];
    int combustivel;
    struct aviao *prox;
};
typedef struct aviao Aviao;

struct fila {

	struct Aviao *inicio;
	struct Aviao *final;
};
typedef struct fila Fila;

Fila* cria () {
	
	Fila* novo = (Fila*) malloc(sizeof(Fila));
 	
 	novo->inicio = novo->final = NULL;
 	
 	return novo;
}

Aviao* insere_inicio(Aviao *aviao,char codigo_aviao[CODIGO_AVIAO],int combustivelA) {

	Aviao *novo = (Aviao*) malloc(sizeof(Aviao));

	strcpy(novo->codigo,codigo_aviao);
	novo->combustivel = combustivelA;

	novo->prox = NULL;

	if(aviao != NULL) {
		aviao->prox = novo;
	}

	return novo;
}

Aviao* retira_inicio(Aviao *aviao) {

	Aviao *retira = aviao->prox;
	free(aviao);

	return retira;
}

void insere (Fila* f, char codigo_aviao[CODIGO_AVIAO],int combustivelA) {
 f->final = insere_inicio(f->final,codigo_aviao,combustivelA);
 if (f->inicio==NULL) /* fila antes vazia? 
 f->inicio = f->final;
}

/*Aviao *inicializa_lista(){
  
    return NULL;
}

Pista_de_decolagem *cria() {

	Pista_de_decolagem *pista_de_decolagem = (Pista_de_decolagem*) malloc(sizeof(Pista_de_decolagem));

	pista_de_decolagem->inicio = pista_de_decolagem->final = NULL;

	return pista_de_decolagem;
}

Aviao *insere_inicio(Aviao *aviao,char codigo_aviao[CODIGO_AVIAO],int combustivelA) {

	Aviao *novo = (Aviao*) malloc(sizeof(Aviao));

	strcpy(novo->codigo,codigo_aviao);
	novo->combustivel = combustivelA;

	novo->prox = NULL;

	if(aviao != NULL) {
		aviao->prox = novo;
	}

	return novo;
}

Aviao *retira_inicio(Aviao *aviao) {

	Aviao *retira = aviao->prox;
	free(aviao);

	return retira;
}

void push(Pista_de_decolagem *pista_de_decolagem,char codigo_aviao[CODIGO_AVIAO],int combustivelA) {

	pista_de_decolagem->inicio = insere_inicio(pista_de_decolagem->final,codigo_aviao,combustivelA);
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
			//push(voos,codigo,combustivelA);
		}    		
    }

    imprime(voos);
	fclose(file);


	/*nAproximacoes = gerar_numero(10,32);
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

int main () {

	printf("HORA: %s\n",__TIME__);
}*/