#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu(){
	printf("******************\n");
	printf("***MENU INICIAL***\n");
	printf("*******FILA*******\n");
	printf("1- Prioridade\n");
	printf("2- Geral\n");
	printf("3- Atendimento\n");
	printf("4- Consultar Prioridades\n");
	printf("5- Consultar Geral\n");
	printf("6- Sair\n\n");
	printf("Escolha sua opção:\n");
}

fila* criar(){
	fila *p = (fila*) malloc(sizeof(fila));
	p->inicio = -1;
	p->fim = -1;
	return(p);
}

int cheia(fila *p){
	if(p->fim == N-1){
		printf("A fila está cheia\n");
		return 1;
	}
	else{ 
		return(0);
	}
}

int vazia_sp(fila *p){
	 if(p->fim == -1){
		return 1;
	}
	else{ 
		return(0);
	}
}

int vazia(fila *p){
	 if(p->fim == -1){
		printf("A fila está vazia\n");
		return 1;
	}
	else{ 
		return(0);
	}
}

void inserir(fila *p, int inserido){
	if(!cheia(p)){
        if(p->inicio == -1) {
            p->inicio = 0;
        }
        p->fim++;
        p->v[p->fim] = inserido;
    }
}

int remover(fila *p){
	if(vazia(p)){
	   return 0;
	}

	int aux = p->v[p->inicio];
	for(int i = 0; i < p->fim; i++){
		p->v[i] = p->v[i + 1];
	}
	p->fim--;
	return aux;

}

int le_dados(){
	int valor = 0;
	printf("Qual opcao desejada:\n");
	scanf("%d", &valor);
	return valor;
}

void impressao(fila *p){
    for(int i = 0; i < N; i++){
        if(p->v[i] != 0){
            printf("A posição é %d == %d\n",i ,p->v[i]);
        }
    }
}

void liberar(fila *p){
	free(p);
}

