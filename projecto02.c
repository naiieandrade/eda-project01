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
	int contador = 0;
	int soma = 0;

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
	int **matrizMedia=(int **)calloc(qtdeLinhas,sizeof(int**));

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++){
		imagem[auxLinhas]=(int*)calloc(qtdeColunas,sizeof(int));
	}

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++){
		matrizMedia[auxLinhas]=(int*)calloc(qtdeColunas,sizeof(int));
	}

	rewind(file); 

	if(file==NULL){
	
		printf("Falha!\n");
	} else {

	    for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++){
	
	    	for(int auxColunas = 0; auxColunas < qtdeColunas; auxColunas ++){
	
	      		fscanf(file, "%d%*c", &imagem[auxLinhas][auxColunas]);
	      	}	
	    }
	}

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas +=3) {

		for(int auxColunas = 0; auxColunas < qtdeColunas; auxColunas +=3) {

			for(int linhas = auxLinhas; linhas < auxLinhas +3; linhas ++) {

				for(int colunas = auxColunas; colunas < auxColunas +3; colunas ++) {

					soma += imagem[linhas][colunas];
					contador ++;
				}
			}
			media = (double) soma/contador;
			matrizMedia[auxLinhas][auxColunas] = media;
			media = 0;	
		}
	}

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas +=3) {

		for(int auxColunas = 0; auxColunas < qtdeColunas; auxColunas +=3) {

			for(int linhas = auxLinhas; linhas < auxLinhas +3; linhas ++) {

				for(int colunas = auxColunas; colunas < auxColunas +3; colunas ++) {

					if (imagem[linhas][colunas] >= matrizMedia[auxLinhas][auxColunas]) {
						imagem[linhas][colunas] = 1;
					} else {
						imagem[linhas][colunas] = 0;
					}
				}
			}	
		}
	}

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++) {

		for(int auxColunas = 0; auxColunas < qtdeLinhas; auxColunas ++) {

			printf("%d\t", imagem[auxLinhas][auxColunas]);
		}
		printf("\n");
	}

	//media = (double)media/(qtdeLinhas * qtdeColunas);
	//printf("%.2lf\n", media);
	fclose(file);

	for(int aux = 0; aux < qtdeLinhas; aux ++) {
		free(*(imagem + aux));
	}

	for(int aux = 0; aux < qtdeLinhas; aux ++) {
		free(*(matrizMedia + aux));
	}

	free(imagem);
	free(matrizMedia);

	return 0;
}

