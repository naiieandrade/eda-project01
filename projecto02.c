#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main() {

  	char arquivo [] = "matrix.txt";
	char caracteres;
	int qtdeLinhas = 0;
	int qtdeColunas = 0;
	double media = 0.0;

	FILE *file;
	
	file = fopen(arquivo, "r");

  	if(file==NULL){
	    
	    printf("Falha!\n");
	} else {
	    
	   while((caracteres=fgetc(file))!=EOF){
	      	
	      	if(caracteres=='\n'){
	        
	        	qtdeLinhas++;
	    	} else if(caracteres==';'&&qtdeLinhas==0){
	        	
	        	qtdeColunas++;
	      	}
	    }
	}

	qtdeColunas +=1; 

	int **imagem=(int**)calloc(qtdeLinhas,sizeof(int*));

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++){
		imagem[auxLinhas]=(int*)calloc(qtdeColunas,sizeof(int));
	}

	rewind(file); 

	if(file==NULL){
	
		printf("Falha!\n");
	} else {

	    for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++){
	
	    	for(int auxColunas = 0; auxColunas < qtdeColunas; auxColunas ++){
	
	      		fscanf(file, "%d%*c", &imagem[auxLinhas][auxColunas]);
	      		media += imagem[auxLinhas][auxColunas];
	      	}	
	    }
	}

	media = (double)media/(qtdeLinhas * qtdeColunas);
	printf("%.2lf\n", media);
	fclose(file);

	return 0;
}

