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
	char lixo[1];

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

	Agenda agenda[qtdeLinhas];

	for(int aux = 0; aux < qtdeLinhas; aux ++) {

		fscanf(file, "%[^\n]\n %[^\n]\n %[^\n]\n %d\n %[^\n]\n %[^\n]\n", 
			agenda[aux].nome_completo, 
			agenda[aux].celular, 
			agenda[aux].endereco,
			&agenda[aux].cep,
			agenda[aux].data_nascimento,
			lixo);
	}

	//for(int aux = 0; aux < total; aux ++) {

		printf("Nome: %s\n", agenda[2].nome_completo);
		printf("Celular: %s\n", agenda[2].celular);
		printf("Endereco: %s\n", agenda[2].endereco);
		printf("CEP: %d\n", agenda[2].cep);
		printf("DATA DE NASCIMENTO: %s\n", agenda[2].data_nascimento);
	//}
	
	return 0;
}