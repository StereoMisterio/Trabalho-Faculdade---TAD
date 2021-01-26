#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct funcionario tipoNo;

typedef struct lista tipoLista;

void cadastrar(tipoLista *lista);
int menu();
void escolha(tipoLista *lista, int opc);
void imprimeMaiorSalario(tipoLista *lista);
void calculaMediaSalarioHomens(tipoLista *lista);
void calculaMediaSalarioMulheres(tipoLista *lista);

