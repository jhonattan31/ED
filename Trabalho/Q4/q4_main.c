#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	fila *pri = criar(), *geral = criar();
	int saida = 1, key_pri = 0, key_geral = 100;
    int cont_prio = 0;
		do{
		menu();
		switch(le_dados()){
			case 1:// distribuiçao de senha prioridade
                key_pri++;
                printf("Sua senha é: %d\n", key_pri);
				inserir(pri, key_pri);
				break;
			case 2:// distribuiçao de senha geral
                key_geral++;
                printf("Sua senha é: %d\n", key_geral);
				inserir(geral, key_geral);
				break;
			case 3: //atendimento
                if(!vazia_sp(geral) && !vazia_sp(pri) && cont_prio < 3){
                    printf("Senha chamada: Prioridade-%d\n", remover(pri));
                    cont_prio++;
                }else{
                    if(!vazia_sp(geral) && !vazia_sp(pri) && cont_prio == 3){
                        printf("Senha chamada: Geral-%d\n", remover(geral));
                        cont_prio = 0;
                    }
                }
                
				if(vazia(pri)){
					printf("Senha chamada: Geral-%d\n", remover(geral));
				}else{
                    if(vazia(geral)){
                        printf("Senha chamada: Prioridade-%d\n", remover(pri));
                    }
                }
                        
				break;
			case 4:// consulta prioridade
				impressao(pri);
				break;
			case 5:// consulta geral
                impressao(geral);
				break;
			case 6:
				saida = 0;
				printf("Até mais ver\n;););)");
				break;
			default:
				printf("Opção inexistente.\n");
				break;
		}
	}while(saida);
	liberar(pri);
    liberar(geral);
}
