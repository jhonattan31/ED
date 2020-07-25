#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "jogo.h"
#include <time.h>

int main(){
	srand(time(NULL));
	int qtd_part;
    int seq = 0;
    int con = 0;
    int cont = 0;
	printf("Quantas partidas serão jogadas?\n");
	scanf("%d", &qtd_part);
	printf("\n");
	Carta *baralho = criar_car();
	Jogador *jog1 = criar_jog(baralho);
	Jogador *jog2 = criar_jog(baralho);
	Jogador *jog3 = criar_jog(baralho);

    do{
		for(int j = 0; j<10; j++){
			seq = jogar(jog1, jog2, jog3);
            if(seq == 1){
                con = 1;
            }
            else if(seq == 2 && con == 1){
                con = 2;
            }
            else if(seq == 3 && con == 2){
                con = 3;
            }
            else con = 0;
            
            if(con == 3) cont++;
		}
		printf("A sequencia se repete %d vezes na partida!", cont);
        con = 0;
        cont = 0;
		
		ganhou_partida(jog1, jog2, jog3);
        
		liberar(jog1 -> deck);
		liberar(jog2 -> deck);
		liberar(jog3 -> deck);
		baralho = criar_car();
		jog1 -> cont = 0;
		jog2 -> cont = 0;
		jog3 -> cont = 0;
		jog1 -> deck = preencher_arvore(baralho);
		jog2 -> deck = preencher_arvore(baralho);
		jog3 -> deck = preencher_arvore(baralho);
        
        qtd_part--;
    }while(qtd_part);
    
    printf("Jogo finalizado!\n\n");
    
    vencedor_jogo(jog1, jog2, jog3);
	liberar_jog(jog1);
	liberar_jog(jog2);
	liberar_jog(jog3);
	return(0);
}
