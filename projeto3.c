#include <stdio.h>
#include <conio.h>

typedef struct contatos
  {
    char nome[101];
    char celular[30];
    unsigned int CEP;
    char data_nascimento[];  
    struct contatos *prox;
    struct contatos *ant;
}agenda;



int main(void)
{    

  
  };