#include "arvore.h"

typedef struct jogador Jogador;

struct jogador{
    char nome[20];
    Arvore *deck;
    int cont;
    int partidas;
};

typedef struct carta Carta; 

Jogador* criar_jog();

Arvore* preencher_arvore(Carta *baralho);

Carta* criar_car();

void jogar(Jogador *jog1, Jogador *jog2, Jogador *jog3);

void ganhou_partida(Jogador *jog1, Jogador *jog2, Jogador *jog3);

void vencedor_jogo(Jogador *jog1, Jogador *jog2, Jogador *jog3);

void liberar_jog(Jogador *a);
