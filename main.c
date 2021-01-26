#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "funcoes.h"
#include "funcoes.c"


int main() 
{
   setlocale(LC_ALL, "Portuguese");
   
   tipoLista *lista = (tipoLista*)malloc(sizeof(tipoLista));
    if(!lista){
        printf("Impossível alocar lista");
    }else {
        lista->head = NULL;
    }
   
   int opcao;
   
   do{
    opcao = menu();
    escolha(lista, opcao);
   }while(opcao != 5);
   
    return 0;
}

