#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
	pilha *p = criar();
	int valor = le_dados();
	do{
		if(valor % 2){
			inserir(p,1);
		}
		else{
			inserir(p,0);
		}
	}while(valor /= 2);
	
	printf("O valor em binario e:\n");
	while(!vazia(p)){
		printf("%d", remover(p));
		
	}
}
