#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nome_completo[101];
    char celular[14];
    unsigned int cep;
    char endereco[40];
    char data_nascimento[11];  
    struct Agenda *proximo;
    struct Agenda *anterior;
}Agenda;

int main () {

	char arquivo [] = "contatos.txt";
	int qtdeLinhas = 0;
	int qtdeDolar = 0;
	char caracteres;
	int total = 0;
	char nome[100];

	FILE *file;
	
	file = fopen(arquivo, "r");

  	if(file==NULL){
	    
	    printf("Falha!\n");
	} else {

		while((caracteres=fgetc(file))!=EOF){
	      	
	      	if(caracteres=='\n'){
	        
	        	qtdeLinhas++;
	        } if(caracteres=='$') {
	        	qtdeDolar++;
	        }
	    }		
	}

	rewind(file); 

	Agenda agenda[6];
	printf("%d\n", qtdeLinhas);
	printf("%d\n", qtdeDolar);
	
	total = qtdeLinhas/qtdeDolar;

	for(int aux = 0; aux < total; aux ++) {

		fscanf(file, "%[^\n]\n %[^\n]\n %[^\n]\n %d\n %[^\n]\n", 
			agenda[aux].nome_completo, 
			agenda[aux].celular, 
			agenda[aux].endereco,
			&agenda[aux].cep,
			agenda[aux].data_nascimento);
	}

	for(int aux = 0; aux < total; aux ++) {

		printf("Nome: %s\n", agenda[aux].nome_completo);
		printf("Celular: %s\n", agenda[aux].celular);
		printf("Endereco: %s\n", agenda[aux].endereco);
		printf("CEP: %d\n", agenda[aux].cep);
		printf("DATA DE NASCIMENTO: %s\n", agenda[aux].data_nascimento);
	}
	
	return 0;
}