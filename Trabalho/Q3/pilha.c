#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha* criar(){
	pilha *p = (pilha*) malloc(sizeof(pilha));
	p->topo = -1;
	return(p);
}

int cheia(pilha *p){
	if(p->topo == N-1){
		return 1;
	}
	else{ 
		return(0);
	}
}

int vazia(pilha *p){
	 if(p->topo == -1){
		return 1;
	}
	else{ 
		return(0);
	}
}

int inserir(pilha *p, int inserido){
	if(cheia(p) == 1){
		printf("A pilha está cheia\n");
        return 0;
	}else{
      p->topo++;
      p->v[p->topo] = inserido;
      return 1;
   }
}

int remover(pilha *p){
	int aux;
	if(vazia(p) == 1){
		printf("A pilha está vazia\n");
	}else{
      aux = p->v[p->topo];
      p->topo--;
      return aux;
   }
}

void impressao(pilha *p){
	for(int i = 0; i < 10; i++){
        printf("O valor é: %d\n", p->v[i]);
    }
}

int le_dados(){
	int valor = 0;
	printf("Digite o valor a ser inserido na pilha:\n");
	scanf("%d", &valor);
	return valor;
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
