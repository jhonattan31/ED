#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No *primeiro = NULL;

Lista* criar(){
    Lista *l = (Lista*) malloc(sizeof(struct lista));
    l->ini = NULL;
    l->fim = NULL;
    l->qtd_elem = 0;
    return l;
}

int vazia(Lista *l){
    if(l->qtd_elem == 0 ) return 1;
    else return 0; 
}

void menu(){
        printf("1- Inserir na Lista 1\n");
        printf("2- Inserir na Lista 2\n");
        printf("3- Mostrar nova lista\n");
        printf("4- Encerrar\n");
        printf("\nSelecione uma opcao --> ");
}

void inserir(Lista *l, int valor, int pos){
    if(pos>=0 && pos<=l->qtd_elem){
        if(vazia(l)){
            l->ini = (No*) malloc(sizeof(struct no));
            l->fim = l->ini;
            l->ini->valor = valor;
            l->ini->prox = NULL;
            l->ini->ant = NULL;
        }else{
            No *n= (No*) malloc(sizeof(struct no));
            n->valor = valor;
            
            if(pos==0){
                n->prox = l->ini;
                n->ant = NULL;
                l->ini->ant = n;
                l->ini = n;
            }else{
                int i = 0;
                No *temp = l->ini;
                for(int i=0;i<pos-1;i++) temp = temp->prox;
                
                n->prox = temp->prox;
                if(pos != l->qtd_elem) temp->prox->ant = n;
                n->ant = temp;
                temp->prox = n;
                
                if(pos == l->qtd_elem) l-> fim = n;
            }
        }
        l-> qtd_elem = l->qtd_elem+1;
    }else{
        printf("Posição de inserção inválida\n");
    }
    
}

int remover(Lista *l, int pos){  
    int i=0;
    No *temp = l->ini;
    int valor = 0;
    if(pos>=0 && pos<l->qtd_elem){
        if(!vazia(l)){
            if(pos == 0){
                l->ini = l->ini->prox;
                if(l->ini != NULL) l->ini->ant = NULL;
                valor = temp->valor;
                free(temp);
                l->qtd_elem = l->qtd_elem -1;
                return(valor);
           }else{
                for(int i=0;i<pos;i++) temp = temp->prox;
               
                if(pos != l->qtd_elem-1) temp->prox->ant = temp->ant;
                temp->ant->prox = temp->prox;
               
                if(pos == l->qtd_elem-1) l->fim=temp->ant;
               
                valor = temp->valor;
                free(temp);
                l->qtd_elem = l->qtd_elem -1;
                return(valor);
           }
       }else{
            printf("Lista vazia impossível remover\n");
            exit(0);
       }
   }else{
        printf("Posição inválida de remoção\n");
        exit(0);
   }
}


int cheia(Lista *l){
    return 0;
}

void imprimir(Lista *l, int pos){
    No *temp = l->ini;
        if(pos>=0 && pos<l->qtd_elem){
            for(int i=0; i<pos; i++){
                temp = temp->prox;  
                printf("[%d]\n", temp->valor);
            } 
        }else{
            printf("Valor de posição inválido\n");
        }
}

void mostrar(Lista *l){
    int pare = 1;
    No *temp = l->ini;
    do{
        if(temp != NULL){
            printf("[%d]\n", temp->valor);
            temp = temp->prox;
        }else {
            pare = 0;
        }
    } while (pare == 0);
    
}

void liberar(Lista *l){
    if(l->ini != NULL){
    No *temp = l->ini;
    No *temp2 = l->ini->prox;
    while(temp!=NULL){
       free(temp);
       temp = temp2;
       if(temp2 != NULL) temp2= temp2->prox;
    }
   
  }
  free(l);
}


void duas_lista(Lista *l){
    int op = 0, valor, pos = 0, remover_l1, remover_l2, pos = 0;
    Lista *l1 = criar();
    Lista *l2 = criar();
    Lista *aux = criar();

    do{
        menu();
        scanf("%d\n", &op);
        system("clear");
        switch (op){
    
            case 1:
                printf("Digite o valor a ser inserido na Lista 1: ");
                scanf("%d", &valor);
                printf("Digite a posição a ser inserido: ");
                scanf("%d", &pos);
                inserir(l1, valor, pos);
                
            break;
            case 2:
                printf("Digite o valor a ser inserido na Lista 2: ");
                scanf("%d", &valor);
                printf("Digite a posição a ser inserido: ");
                scanf("%d", &pos);
                inserir(l2, valor, pos);
               
            break;
            case 3:
                while(!vazia(l1) && !vazia(l2)){
                    inserir(aux, remover(l1, 0), pos);
                    pos++;
                    inserir(aux, remover(l2, 0), pos);
                    pos++;
                }
                for(int i=0; i<pos; i++){
                    imprimir(aux, i);
                }
                
            break;
            case 4:
                liberar(aux);
                exit(1);
            break;
            default:
                printf("Opção Inválida!!\n\n");
            break;
        }
    }while(op != 0);

}
