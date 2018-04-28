#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int soma_media_dec=0;
	int count_expoente = 0;
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

	int **imagem = (int**) calloc(qtdeLinhas,sizeof(int*));
	double **matrizMedia = (double **) calloc(qtdeLinhas,sizeof(double*));
	int *vetorNormalizado = (int*) malloc(qtdeLinhas * sizeof(int));

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++){
		imagem[auxLinhas]=(int*)calloc(qtdeColunas,sizeof(int));
	}

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++){
		matrizMedia[auxLinhas]=(double*)calloc(qtdeColunas,sizeof(double));
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

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas -2; auxLinhas +=1) {

		for(int auxColunas = 0; auxColunas < qtdeColunas -2; auxColunas +=1) {

			for(int linhas = auxLinhas; linhas < auxLinhas +3; linhas ++) {

				for(int colunas = auxColunas; colunas < auxColunas +3; colunas ++) {

					soma += imagem[linhas][colunas];
					contador ++;
				}
			}
			media = (double) soma/contador;
			matrizMedia[auxLinhas][auxColunas] = media;
			media = 0;
			soma = 0;	
		}
	}	

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas -2; auxLinhas +=1) {

		for(int auxColunas = 0; auxColunas < qtdeColunas-2; auxColunas +=1) {

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

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas -2; auxLinhas +=1) {
		count_expoente =0;
		for(int auxColunas = 0; auxColunas < qtdeColunas-2; auxColunas +=1) {
			vetorNormalizado[auxLinhas] = imagem[auxLinhas][auxColunas];
			
			for(int linhas = auxLinhas; linhas < auxLinhas +3; linhas ++) {
			
				for(int colunas = auxColunas; colunas < auxColunas +3; colunas ++) {
					
					//tirar o soma caso quiser ver cada numero
					vetorNormalizado[linhas]+= imagem[linhas][colunas] * pow(2,count_expoente);
					
					//printf("%d\t",vetorNormalizado[linhas]);
					count_expoente++;
						
				}
					soma_media_dec+=vetorNormalizado[linhas];
						
					//printf("%d\t",soma_media_dec);
				
				//printf(" %d\t",vetorNormalizado[linhas]);
				
				//está dando erro na soma final está somando um a mais na primeira linha 
			}	
			if(imagem[0][0]==1){
				soma_media_dec= soma_media_dec-1;
			}

			printf("%d\t",soma_media_dec);	
		}
		
	}

	for(int auxLinhas = 0; auxLinhas < qtdeLinhas; auxLinhas ++) {

		for(int auxColunas = 0; auxColunas < qtdeLinhas; auxColunas ++) {

			//printf("%d\t", vetorNormalizado[auxLinhas]);
		}
		printf("\n");
	}

	fclose(file);

	for(int aux = 0; aux < qtdeLinhas; aux ++) {
		free(*(imagem + aux));
	}

	for(int aux = 0; aux < qtdeLinhas; aux ++) {
		free(*(matrizMedia + aux));
	}

	free(imagem);
	free(matrizMedia);
	free(vetorNormalizado);

	return 0;
}

