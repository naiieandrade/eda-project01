#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
  int vetor [3][3] = {0,0,1,0,1,0,0,1,0};
  char array [9];// = {0};
  char array_char[9][2];

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("%d\t",vetor[i][j] );
    }
    printf("\n");
  }

  for (int i=0;i<3;i++){
    array[i]=vetor[0][i];
  }
  for (int i=1; i<3; i++){
    array[i+2]=vetor[i][2];
  }
  int point=4;
  for (int i=1; i>-1;--i){
    array[i+point]=vetor[2][i];
    point++;
    point++;
  }
  for(int i=0; i<2;i++){
    array[i+7]=vetor[1][i];
  }

  for(int i=0; i<9;i++)
    printf("%d ", array[i]);

  /*for(int i=0;i<9;i++){
    int num;
    char let[1];
    num = array[i];
    sprintf(let, "%d", num);
    strncpy(array_char[i], let, 2);
  }*/

  //int s;
  int iiii = 0;
  unsigned int dec = 0;

  int s = 9;//strlen( array );
  //s = 9;
//  printf("%c\n", );
  printf("\nS = %d\n", s );
  while( s-- ) {
      if( array[s] == '0' || array[s] == '1' ) {
          dec = dec + pow(2, iiii++) * (array[s] - '0');
          printf("dec = %u, s=%d\n", dec,s);
      }
  };
  printf("\nDecimal Equivalent of Binary Number: \t %u\n", dec);

  return 0;
}
