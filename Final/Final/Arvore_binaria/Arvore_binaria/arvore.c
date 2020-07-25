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

int altura_No(No *no){
    if(no == NULL){
        return -1;
    }
    return no->alt;
}

int calcBalanceamento(No *no){
    return labs(altura_No(no->esq) - altura_No(no->dir));
}

int maior_Valor(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

void rotacaoEsq(Arvore *a){
    No *no;
    no = a->raiz->esq;
    a->raiz->esq = no->dir;
    no->dir = a->raiz;
    
    a->raiz->alt = maior_Valor(altura_No(a->raiz->esq), altura_No(a->raiz->dir)) + 1;
    no->alt = maior_Valor(altura_No(no->esq), a->raiz->alt) + 1;
    
    a->raiz = no;
    
}

void rotacaoDir(Arvore *a){
    No *no;
    no = a->raiz->dir;
    a->raiz->dir = no->esq;
    no->esq = a->raiz;
    
    a->raiz->alt = maior_Valor(altura_No(a->raiz->esq), altura_No(a->raiz->dir)) + 1;
    no->alt = maior_Valor(altura_No(no->dir), a->raiz->alt) + 1;
    
    a->raiz = no;
}

void rotacaoEsqDir(Arvore *a){
    rotacaoDir(&(a->raiz->esq));
    rotacaoEsq(a->raiz);
}

void rotacaoDirEsq(Arvore *a){
    rotacaoEsq(&(a->raiz->dir));
    rotacaoDir(a->raiz);
}

int inserir(Arvore *a, int valor){
    int result;
    if(a->raiz == NULL){
        No *n = (No*) malloc(sizeof(No));
        if(n == NULL){
            return 0;
        }
        n->valor = valor;
        n->esq = NULL;
        n->dir = NULL;
        n->alt = 0;
        a->raiz = n;
        return 1;
    }
    
    No *Temp = a->raiz;
    if(valor <= Temp->valor){
       if((result=inserir(&(Temp->esq), valor)) == 1){ 
            if(calcBalanceamento(Temp) >= 2){
                if(valor <= a->raiz->esq-valor){
                    rotacaoEsq(a->raiz);
                }else{
                    rotacaoEsqDir(a->raiz);
                }
            }
       }
    }else{
        if(valor > Temp->valor){
            if((result=inserir(&(Temp->dir), valor)) == 1){
                if(calcBalanceamento(Temp) >= 2){
                    if(valor > a->raiz->dir-valor){
                        rotacaoDir(a->raiz);
                    }else{
                        rotacaoDirEsq(a->raiz);
                    }
                }
            }
        }
    }
    
    Temp->alt = maior_Valor(altura_No(Temp->esq), altura_No(Temp->dir)) + 1;
    
    return res;
}

/*void inserir(Arvore *a, int valor){
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
}*/

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

