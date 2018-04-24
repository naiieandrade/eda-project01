#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1025

int main(){

  char path[]="teste.txt";
  FILE *file;

  file=fopen(path,"r");

  int rows=0;
  int cols=0;
  char ch;

  if(file==NULL){
    printf("Falha!\n");
  } else {
    while((ch=fgetc(file))!=EOF){
      if(ch=='\n'){
        rows++;
      } else if(ch==';'&&rows==0){
        cols++;
      }
    }
  }

  cols +=1; //Corrigir, porque volta 1024
  printf("rows: %d\n", rows);
  printf("cols: %d\n", cols);


  int **photo=(int**)malloc(rows*sizeof(int*));

  for(int i=0; i<rows; i++){
    photo[i]=(int*)malloc(cols*sizeof(int));
    for(int j=0; j<cols; j++){
      photo[i][j]=0;
    }
  }

  //aloca matriz com os valores obtidos
  //int photo[rows][cols];

  rewind(file);

  if(file==NULL){
    printf("Falha!\n");
  } else {
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        fscanf(file, "%d%*c", &photo[i][j]);
      }
    }
  }

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      printf("%d\t", photo[i][j]);
    }
  }

  printf("%d", photo[2][0]);

  //não esquecer nunca de fechar
  fclose(file);

  return 0;
}
