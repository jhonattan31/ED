#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "jogo.h"
#include <time.h>


struct carta{
	int cont1;
	int cont2;
	int cont3;
	int cont4;
	int cont5;
	int cont6;
	int cont7;
	int cont8;
	int cont9;
	int cont10;
	int cont11;
	int cont12;
	int cont13;
};

Jogador* criar_jog(Carta *baralho){
    Jogador *a = (Jogador*) malloc(sizeof(Jogador));
    printf("Insira o nome do jogador:\n");
    setbuf(stdin, NULL);
    fgets(a -> nome, sizeof(a -> nome), stdin);
    a->nome[strlen(a->nome) - 1] = 0;
    a -> deck = preencher_arvore(baralho);
    a -> cont = 0;
    a-> partidas = 0;
    return a;
}

Carta* criar_car(){
	Carta *a = (Carta*) malloc(sizeof(Carta));
	a->cont1=0;
	a->cont2=0;
	a->cont3=0;
	a->cont4=0;
	a->cont5=0;
	a->cont6=0;
	a->cont7=0;
	a->cont8=0;
	a->cont9=0;
	a->cont10=0;
	a->cont11=0;
	a->cont12=0;
	a->cont13=0;
	return a;
}

Arvore* preencher_arvore(Carta *baralho){
    Arvore *a;
    int num_gerado;
    int n = 0;
    do{
        num_gerado = 1 + rand()%13; 
        printf("----Valor gerado----%d\n", num_gerado);
        
        if(num_gerado == 1 && baralho-> cont1 < 4){
			n++;
			baralho-> cont1++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 2 && baralho-> cont2 < 4){
			n++;
			baralho-> cont2++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 3 && baralho-> cont3 < 4){
			n++;
			baralho-> cont3++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 4 && baralho-> cont4 < 4){
			n++;
			baralho-> cont4++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 5 && baralho-> cont5 < 4){
			n++;
			baralho-> cont5++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 6 && baralho-> cont6 < 4){
			n++;
			baralho-> cont6++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 7 && baralho-> cont7 < 4){
			n++;
			baralho-> cont7++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 8 && baralho-> cont8 < 4){
			n++;
			baralho-> cont8++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 9 && baralho-> cont9 < 4){
			n++;
			baralho-> cont9++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 10 && baralho-> cont10 < 4){
			n++;
			baralho-> cont10++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 11 && baralho-> cont11 < 4){
			n++;
			baralho-> cont11++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 12 && baralho-> cont12 < 4){
			n++;
			baralho-> cont12++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}else
		if(num_gerado == 13 && baralho-> cont13 < 4){
			n++;
			baralho-> cont13++;
			printf("\n\n\n\nVAlor do result: %d \n\n", inserir(a, num_gerado));
		}
		//int aux = a->valor;
		//printf("\n###VALOR DA RAIZ ATUAL : %d ###\n", aux);
    }while(n < 10);
    return a;
}

void jogar(Jogador *jog1, Jogador *jog2, Jogador *jog3){
    int jogada1 = remover(jog1->deck);
    int jogada2 = remover(jog2->deck);
    int jogada3 = remover(jog3->deck);

    if(jogada1 == jogada2 && jogada1 == jogada3){
		//printf("\n\n\nTodos empataram  %d\n\n\n",jogada1);
        jog1->cont++;
        jog2->cont++;
        jog3->cont++;
        
    }else if(jogada1 == jogada2 && jogada1 > jogada3){
		//printf("\n\n\n1 e 2 empataram \n\n\n");
        jog1->cont++;
        jog2->cont++;
        
    }else if(jogada1 == jogada3 && jogada1 > jogada2){
				//printf("\n\n\n1 e 3 empataram\n\n\n");

        jog1->cont++;
        jog3->cont++;
        
    }else if(jogada3 == jogada2 && jogada1 < jogada3){
				//printf("\n\n\n3 e 2 empataram\n\n\n");

        jog3->cont++;
        jog2->cont++;
        
    }else if(jogada1 > jogada2 && jogada1 > jogada3){
				//printf("\n\n\n1 Venceu\n\n\n");

        jog1->cont++;
 
    }else if(jogada1 < jogada2 && jogada2 > jogada3){
        		//printf("\n\n\n2  venceu\n\n\n");

        jog2->cont++;   
         
        
    }else{
		  //      		printf("\n\n\n3  venceu\n\n\n");

        jog3->cont++;
        
    }
}

void ganhou_partida(Jogador *jog1, Jogador *jog2, Jogador *jog3){
    if(jog1 -> cont == jog2 -> cont && jog1 -> cont == jog3 -> cont){
			jog1->partidas++;
			jog2->partidas++;
			jog3->partidas++;
			printf("Todos os jogadores EMPATARAM na partida!\n\n");
			
		}else if(jog1 -> cont == jog2 -> cont && jog1 -> cont > jog3 -> cont){
			jog1->partidas++;
			jog2->partidas++;
			printf("Jogadores 1: %s e 2: %s EMPATARAM nessa partida!\n\n", jog1->nome, jog2->nome);
		
			
		}else if(jog1 -> cont == jog3 -> cont && jog1 -> cont > jog2 -> cont){
			jog1->partidas++;
			jog3->partidas++;
			printf("Jogadores 1: %s e 3: %s EMPATARAM nessa partida!\n\n", jog1->nome, jog3->nome);
		
			
		}else if(jog3 -> cont == jog2 -> cont && jog1 -> cont < jog3 -> cont){
			jog3->partidas++;
			jog2->partidas++;
			printf("Jogadores 2: %s e 3: %s EMPATARAM nessa partida!\n\n", jog2->nome, jog3->nome);
		
			
		}else if(jog1 -> cont > jog2 -> cont && jog1 -> cont > jog3 -> cont){
			jog1->partidas++;
			printf("Jogador 1: %s ganhou a partida!\n\n", jog1->nome);
			
		
			
		}else if(jog1 -> cont < jog2 -> cont && jog2 -> cont > jog3 -> cont){
			jog2->partidas++;
			printf("Jogador 2: %s ganhou a partida!\n\n", jog2->nome);
		
			
		}else{
			jog3->partidas++;
			printf("Jogador 3: %s ganhou a partida!\n\n", jog3->nome);
			
		}
}

void vencedor_jogo(Jogador *jog1, Jogador *jog2, Jogador *jog3){
       if(jog1 -> partidas == jog2 -> partidas && jog1 -> partidas == jog3 -> partidas){
        
        printf("Todos os jogadores EMPATARAM com %d partidas vencidas!\n\n", jog1 -> partidas);
        
    }else if(jog1 -> partidas == jog2 -> partidas && jog1 -> partidas > jog3 -> partidas){
        
        printf("Jogadores 1: %s e 2: %s EMPATARAM com %d partidas vencidas!\n\n", jog1->nome, jog2->nome, jog1 -> partidas);
    
    }else if(jog1 -> partidas == jog3 -> partidas && jog1 -> partidas > jog2 -> partidas){
        
        printf("Jogadores 1: %s e 3: %s EMPATARAM com %d partidas vencidas!\n\n", jog1->nome, jog3->nome, jog1 -> partidas);
        
    }else if(jog3 -> partidas == jog2 -> partidas && jog1 -> partidas < jog3 -> partidas){
        
        printf("Jogadores 2: %s e 3: %s EMPATARAM com %d partidas vencidas!\n\n", jog2->nome, jog3->nome, jog2 -> partidas);
        
    }else if(jog1 -> partidas > jog2 -> partidas && jog1 -> partidas > jog3 -> partidas){
        
        printf("Jogador 1: %s ganhou com %d partidas vencidas!\n\n", jog1->nome, jog1 -> partidas);
        
    }else if(jog1 -> partidas < jog2 -> partidas && jog2 -> partidas > jog3 -> partidas){
        
        printf("Jogador 2: %s ganhou com %d partidas vencidas!\n\n", jog2->nome, jog2 -> partidas);
    
        
    }else{
        
        printf("Jogador 3: %s ganhou com %d partidas vencidas!\n\n", jog3->nome, jog3 -> partidas);

    }
}

void liberar_jog(Jogador *a){
    liberar(a->deck);
    free(a);
}
