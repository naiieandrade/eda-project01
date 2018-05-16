#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nome_completo[101];
    char celular[14];
    unsigned int cep;
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

		fscanf(file,"%s^\n %s %d %s", agenda[aux].nome_completo, agenda[aux].celular,
									  &agenda[aux].cep, agenda[aux].data_nascimento);
	}

	for(int aux = 0; aux < total; aux ++) {

		printf("%s\n", agenda[aux].celular);
	}

	// for(int aux = 0; aux < qtdeLinhas; aux++) {

	// 	fscanf(file, "%s^\n %s %d %s", agenda[aux].nome_completo, agenda[aux].celular, &agenda[aux].cep, agenda[aux].data_nascimento);
	// }

	//  for(int aux = 0; aux < qtdeLinhas; aux ++) {

	//  	printf("%s\n", agenda[aux].nome_completo);
	//  }

	//printf("%d\n", qtdeLinhas);
	// scanf("%d", &agenda.cep);
	// printf("%d\n", agenda.cep);
	
	return 0;
}