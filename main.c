#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1025

int main(){

  char path[]="asphalt_01.txt";
  FILE *file;
  int photo[MAX][MAX];

  file=fopen(path,"r");

  if(file==NULL){
    printf("Falha!\n");
  } else {
    for(int i=0; i<MAX; i++){
      for(int j=0; j<MAX; j++){
        fscanf(file, "%d%*c", &photo[i][j]);
      }
    }
  }

  printf("%d", photo[2][0]);
  fclose(file);

  return 0;
}
