#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define CODIGO_AVIAO 7
#define MAXIMO_DE_CARACTERES 17

struct aviao {

 	char codigo[CODIGO_AVIAO];
 	int combustivel;
 	char status[MAXIMO_DE_CARACTERES];
 	int numero_pista;
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

void pop (Fila* fila) {

 	char codigo_aviao[CODIGO_AVIAO];

 	if (vazia(fila)) {

 		printf("Fila vazia.\n");
 		exit(1);
 	}

 	strcpy(codigo_aviao,fila->inicio->codigo);

 	fila->inicio = retira_inicio(fila->inicio);

 	if (fila->inicio == NULL) {

 		fila->final = NULL;
 	}
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

struct tm* add_unidade_de_tempo(struct tm *now_tm, int qnt){

  int min;


  min = now_tm->tm_min;
  int num = 5 * qnt;
  if(min+num > 59){
    now_tm->tm_hour+=1;
    now_tm->tm_min=(now_tm->tm_min+num)-60;
  } else {
    now_tm->tm_min=now_tm->tm_min+num;
  }
  return now_tm;
}


void imprime (Fila* fila,int nVoos,int nAproximacoes,int nDecolagens) {

 	Aviao* aviao;
  time_t now;
  struct tm *now_tm;
  now = time(NULL);
  now_tm = localtime(&now);

  int hour, min;



 	printf("--------------------------------------------------------------------------------\n");
 	printf("Aeroporto Internacional de Brasília\n");
 	printf("Hora Inicial: %s\n",__TIME__);
 	printf("Fila de Pedidos: \n");
 	printf("NVoos: %d\n",nVoos);
 	printf("Naproximacoes: %d\n",nAproximacoes);
 	printf("NDecolagens: %d\n",nDecolagens);
 	printf("--------------------------------------------------------------------------------\n");
 	printf("Listagem de eventos\n\n");

 	for (aviao=fila->inicio; aviao!= NULL; aviao=aviao->prox){
    now_tm=add_unidade_de_tempo(now_tm, 1);
    hour = now_tm->tm_hour;
    min = now_tm->tm_min;

 		printf("Código do voo: %s\n", aviao->codigo);
 		printf("Status: \n");
 		printf("Horário do início do procedimento: %d:%d \n", hour, min);
 		printf("Número da pista: \n\n");
	}
}


int gerar_numero(int lim_inf, int lim_sup){


	int result = 0;

	for (int aux = 0; aux < 1; aux ++) {
		result = (rand() % (lim_sup - lim_inf + 1)) + lim_inf;
	}

	return result;
}

int main () {

 	Fila* fila = cria();

 	int nVoos = 0,nAproximacoes = 0,nDecolagens = 0,combustivelA = 0;
	int tempo = 5;
	srand(time(0));
	char codigo[CODIGO_AVIAO];
	char arquivo [] = "codigo_de_voos.txt";
	int qtdeLinhas = 0;
	char caracteres;

	nAproximacoes = gerar_numero(10,32);
	nDecolagens = gerar_numero(10,32);
	combustivelA = gerar_numero(0,12);
	nVoos = nAproximacoes + nDecolagens;

	FILE *file;

	file = fopen(arquivo, "r");

  	if(file==NULL){

	    printf("Falha!\n");
	} else {

		for(int aux = 0; aux < nVoos; aux ++) {

			fscanf(file, "%[^\n]\n", codigo);

			combustivelA = gerar_numero(0,12);
			push(fila,codigo,combustivelA);
		}
	}

	fclose(file);

 	imprime(fila,nVoos,nAproximacoes,nDecolagens);
 	libera(fila);

 	return 0;
}
