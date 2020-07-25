#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
	pilha *p = criar();
    int valor = le_dados();
	int aux = 0;
    
    while(valor != 0){
		aux = valor % 10;
		valor = valor/10;
		inserir(p, aux);
	}
	
    
    p = inverter(p);
    
   
    
    printf("O numero inverso: ");
    while(!vazia(p)){
		printf("%d",remover(p));
	}
	 printf("\n");
    
	liberar(p);
}
