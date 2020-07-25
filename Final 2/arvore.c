#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include <math.h>
#include "jogo.h"
#include <time.h>
#define ESQUERDA 1
#define DIREITA 2

struct no{
    int valor;
    int alt;
    No *esq;
    No *dir;
};

struct arvore{
    No *raiz;
};

Arvore* criar(){
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return(a);
}


int vazia(Arvore *a){
    if(a->raiz == NULL)
        return 1;
    else
        return 0;
}

int cheia(Arvore *a){
    return 0;
}
void inserir(Arvore *a, int valor){
    No *temp  = a->raiz;
    No *ant = NULL;
    int pos=0;
    
    No *n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    n->alt = 0;
    
    if(vazia(a)){
        a->raiz = n;
    }else{
        while(temp != NULL){
            if(valor < temp->valor){
                ant = temp;
                temp = temp->esq;
                pos = ESQUERDA;
            }else{
                if(valor > temp->valor){
                    ant = temp;
                    temp = temp->dir;
                    pos = DIREITA;
                } else if(valor == temp->valor){
						n -> esq = temp -> esq;
						temp -> esq = n;
						return;
                  }
            }
        }
        
        if(pos == ESQUERDA){
            ant->esq = n;
        }else if(pos == DIREITA) ant->dir = n;
    }
}

int remover(Arvore *a){
    if(!vazia(a)){
        //percorrendo a árvore com temp
        No *temp = a->raiz;
        No *ant =NULL;
        int pos_temp = 0;
        while(temp -> esq !=NULL){
            ant = temp;
            temp = temp->esq;
              
        }
        
        if(temp == a->raiz) {
            a->raiz = a->raiz->dir;
        }else{
            ant -> esq = temp -> dir;
        }
        
        pos_temp = temp -> valor;
        free(temp);
        return(pos_temp);
        
    }
    
    return(0); // quando está vazia retorna 0
}

void liberar(Arvore *a){
    free(a);
}

