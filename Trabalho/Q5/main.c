#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	fila *pri = criar();
    int saida = 1;
    do{
		menu();
		switch(le_dados()){
            int valor, pos;
			case 1:// inserir
                printf("Digite o valor a ser inserido: \n");
                scanf("%d", &valor);
				inserir(pri, valor);
                impressao(pri);
				break;
			case 2:// furar fila
                printf("\nEscolha a posicao desejada: \n");
                scanf("%d", &pos);
                printf("Digite o valor a ser inserido: \n");
                scanf("%d", &valor);
                furafila(pri, valor, pos);
                impressao(pri);
				break;
			case 3: //remover
                if((valor = remover(pri)) != -1){
                    printf("Valor removida da fila: %d\n", valor);
                    impressao(pri);
                }
				break;
			case 4:// consulta
				impressao(pri);
				break;
			case 5:// bye bye
                saida = 0;
				printf("Até mais ver\n;););)");
				break;
			default:
				printf("Opção inexistente.\n");
				break;
		}
	}while(saida);
	liberar(pri);
}
