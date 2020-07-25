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
    struct no *esq;
    struct no *dir;
}

int altura_No(struct no *n){
    if(n == NULL){
        return -1;
    }
    return n->alt;
}

int calcBalanceamento(struct no *n){
    return labs(altura_No(n->esq) - altura_No(n->dir));
}

int maior_Valor(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

void rotacaoEsq(Arvore *a){
    struct no *n;
    n = (*a)->esq;
    (*a)->esq = n->dir;
    n->dir = *a;
    
    (*a)->alt = maior_Valor(altura_No((*a)->esq), altura_No((*a)->dir)) + 1;
    n->alt = maior_Valor(altura_No(n->esq), (*a)->alt) + 1;
    
    (*a) = n;
    
}

void rotacaoDir(Arvore *a){
    struct no *n;
    n = (*a)->dir;
    (*a)->dir = n->esq;
    n->esq = (*a);
    
    (*a)->alt = maior_Valor(altura_No((*a)->esq), altura_No((*a)->dir)) + 1;
    n->alt = maior_Valor(altura_No(n->dir), (*a)->alt) + 1;
    
    (*a) = n;
}

void rotacaoEsqDir(Arvore *a){
    rotacaoDir(&(*a)->esq);
    rotacaoEsq(a);
}

void rotacaoDirEsq(Arvore *a){
    rotacaoEsq(&(*a)->dir);
    rotacaoDir(a);
}

int inserir(Arvore *a, int valor){
	
    int result;
    if(*a == NULL){
        struct no *n = (struct no*) malloc(sizeof(struct no));
        if(n == NULL){
            return 0;
        }
        n-> valor = valor;
        n->esq = NULL;
        n->dir = NULL;
        n->alt = 0;
        *a = n;
        return 1;
    }
    
    struct no *Temp = *a;
    if(valor <= Temp->valor){
       if((result = inserir(&(Temp->esq), valor)) == 1){ 
            if(calcBalanceamento(Temp) >= 2){
                if(valor <= (*a)->esq->valor){
                    rotacaoEsq(a);
                }else{
                    rotacaoEsqDir(a);
                }
            }
       }
    }else{
        if(valor > Temp->valor){
            if((result=inserir(&(Temp->dir), valor)) == 1){
                if(calcBalanceamento(Temp) >= 2){
                    if(valor > (*a)->dir->valor){
                        rotacaoDir(a);
                    }else{
                        rotacaoDirEsq(a);
                    }
                }
            }
        }
    }
    
    Temp->alt = maior_Valor(altura_No(Temp->esq), altura_No(Temp->dir)) + 1;
    
    return result;
}
/*
void inserir(No *a, int valor){
    No *temp  = a;
    No *ant = NULL;
    int pos=0;
    
    No *n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    n->alt = 0;
    
    if(vazia(a)){
        a = n;
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
*/
int remover(Arvore *a){
    if(*a == NULL){//valor não existe
		printf("Valor não existe!!\n");
		return 0;
	}
	int result;
	if((*a)->esq != NULL){
		if((result = remover(&(*a)->esq)) == 1){
			if(calcBalanceamento(*a) >= 2){
				if(altura_No((*a)->dir->esq) <- altura_No((*a)->dir->dir)){
					rotacaoDir(a);
				}else{
					rotacaoDirEsq(a);-
				}
			}
		}
	}else{
		if(((*a)->dir != NULL)){
			struct no *ant_no = *a;
			*a = (*a)->dir;
			free(ant_no);
		}
	}
	return result;
}

void liberar(Arvore *a){
    free(a);
}
