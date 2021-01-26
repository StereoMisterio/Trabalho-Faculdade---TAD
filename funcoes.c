#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "funcoes.h"

typedef struct funcionario{
    char nome [100];
    char sexo;
    double salario;
    struct funcionario *proximo;
}tipoNo;

typedef struct lista{
    tipoNo *head;
}tipoLista;

int menu(){
  int opc;

    printf("\n\n---------- CADASTRO DE FUNCIONÁRIOS  ----------\n");
    printf("\nDigite um número para escolher a opção desejada: ");
    printf("\n1 - Cadastrar funcionário");
    printf("\n2 - Dados sobre maior salário");
    printf("\n3 - Média salarial masculina");
    printf("\n4 - Média salarial feminina");
    printf("\n5 - Sair\n\n");
    scanf("%d%*c", &opc);
    system("cls || clear");

    return opc;
}

void cadastrar(tipoLista *lista){
    
    tipoNo *novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if(!novoNo){
        printf("Impossível alocar");
    }else{
        printf("\nNome: ");
        fflush(stdin);
        gets(novoNo->nome);
        fflush(stdin);
        printf("Salário: ");
        scanf("%lf", &novoNo->salario);
        fflush(stdin);
        volta: printf("Sexo (F/M): ");
        scanf("%c", &novoNo->sexo);
        fflush(stdin);
        if (novoNo->sexo == 'f' || novoNo->sexo == 'F' ){
        	novoNo->proximo = lista->head;
   			lista->head = novoNo;
   		}else if (novoNo->sexo == 'm'|| novoNo->sexo == 'M'){
   			novoNo->proximo = lista->head;
   			lista->head = novoNo;
		}else{
        	printf("SEXO INVÁLIDO!\n");
            fflush(stdin);
            goto volta;
        }
	}
}

void escolha(tipoLista *lista, int opc){  
 	switch(opc){
        case 1:
            cadastrar(lista);
            break;
            
        case 2:
            imprimeMaiorSalario(lista);
            break;  
            
        case 3:
            calculaMediaSalarioHomens(lista);
            break;
         
        case 4:
            calculaMediaSalarioMulheres(lista);
            break;
        
        case 5:
           printf("\nPROGRAMA ENCERRADO COM SUCESSO!\n");
            break;
            
        default:
            printf("\nCÓDIGO INVÁLIDO!\n");
            break;
    } 
}

void imprimeMaiorSalario(tipoLista  *lista){ 
    tipoNo *aux = lista->head;
    tipoNo *maior = lista->head;
    
    if(aux == NULL){
	    printf("\nNENHUM ELEMENTO NA LISTA!\nPOR FAVOR, ESCOLHA A OPÇÃO 1 PARA CADASTRO\n");
	    printf ("\nPressione qualquer tecla para continuar...\n");
	    getchar();
    }else{
    	while(aux != NULL){ 
	        if(aux->salario > maior->salario){
	        	maior->salario = aux->salario;
	        	maior = maior->proximo;
	    	}	
    		aux = aux->proximo;
    	} 
    	if(maior->sexo == 'm'){
    		printf("\n\nDADOS DO FUNCIONÁRIO COM MAIOR SALÁRIO: \nNome: %s\nSexo: Masculino \nSalário: R$%.2f\n", maior->nome, maior->salario);
		} else{
			printf("\n\nDADOS DO FUNCIONÁRIO COM MAIOR SALÁRIO: \nNome: %s\nSexo: Feminino \nSalário: R$%.2f\n", maior->nome, maior->salario);
		}
	}	
}

void calculaMediaSalarioHomens(tipoLista *lista){
	int cont = 0;
	double soma = 0;
	tipoNo *aux = lista->head;
	    
	if(aux == NULL){
	    printf("\nNENHUM ELEMENTO NA LISTA!\nPOR FAVOR, ESCOLHA A OPÇÃO 1 PARA CADASTRO\n");
	    printf ("\nPressione qualquer tecla para continuar...\n");
	    getchar();
	}else if(aux->sexo == 'm'){ 
		while(aux != NULL){
		    soma += aux->salario;
			cont++;
			aux = aux->proximo;
	    }
	    printf("\nMédia salarial masculina: RS %.2lf\n", soma/cont);
		printf ("\n\nPressione qualquer tecla para continuar...\n");
		getchar();
	}
}
	
	
void calculaMediaSalarioMulheres(tipoLista *lista){
	int cont = 0;
	double soma = 0;
	tipoNo *aux = lista->head;
    
		if(aux == NULL){
	    	printf("\nNENHUM ELEMENTO NA LISTA!\nPOR FAVOR, ESCOLHA A OPÇÃO 1 PARA CADASTRO\n");
		    printf ("\nPressione qualquer tecla para continuar...\n");
		    getchar();
	}else if(aux->sexo == 'f'){
	    while(aux != NULL){
			soma += aux->salario;
			cont++;
			aux = aux->proximo;
		}	
		printf ("\n\nMédia salarial feminina: RS%.2lf\n", soma/cont);
		printf ("\nPressione qualquer tecla para continuar...\n");
		getchar();
	}
}
