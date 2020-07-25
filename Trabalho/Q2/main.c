#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
	pilha *p = criar();
	pilha *aux = criar();
    pilha *temp = criar();
    int iguais = 1, i = 0;
    int num = 0;
    
    printf("Digite o tamanho da palavra\n");
    scanf("%d", &num);
    setbuf(stdin, NULL);
    
    
    for(int i = 0; i < num; i++){
        char c;
        printf("Digite o caracter a ser inserido na pilha:\n");
        scanf(" %c", &c);
        inserir(p, c);

    }
    
    while(!vazia_sp(p)){
        char c = remover(p);
        inserir(aux, c);
        inserir(temp, c);
    }
    p = inverter(temp);
    
    impressao(p, aux);
    
    while(!vazia_sp(aux) && !vazia_sp(p)){
        if(remover(p) != remover(aux)){
			iguais = 0;
		}
    }
    if(iguais == 1){
		printf("Palindromo detectado.");	
	}else{
		printf("Não é um palindromo");
	}
	liberar(p);
    liberar(aux);
    liberar(temp);
}
