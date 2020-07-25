#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

pilha* criar(){
	pilha *p = (pilha*) malloc(sizeof(pilha));
	p->topo = -1;
	return(p);
}

int cheia(pilha *p){
	if(p->topo == N-1) {
        printf("A pilha está cheia\n");
        return(1);
    }
    return(0);
}

int vazia(pilha *p){
	 if(p->topo == -1) {
        printf("A pilha está vazia\n");
        return(1);
    }
    return(0);
}

int vazia_sp(pilha *p){
	 if(p->topo == -1) {
        return(1);
    }
    return(0);
}

void inserir(pilha *p, char inserido){
	if(!cheia(p)){
      p->topo++;
      p->v[p->topo] = inserido;
      return;
   }
}

char remover(pilha *p){
	char aux;
	if(vazia(p)){
		printf("A pilha está vazia\n");
	}else{
      aux = p->v[p->topo];
      p->topo--;
      return aux;
   }
}

void impressao(pilha *p, pilha *l){
    if(vazia(p) || vazia(l)){
        return;
    }
        printf("Conteúdo das Pilhas:\n");
    for(int i = 0; i < N; i++){
        if(p->v[i] != 0 && l->v[i] != 0){
            printf(" %c || %c\n", p->v[i], l->v[i]);
        }
    }
}

pilha* inverter(pilha *p1){
	pilha *aux = criar();
	while(!vazia(p1)){
		inserir(aux, remover(p1));	
	}
	return aux;
}

void liberar(pilha *p){
	free(p);
}
