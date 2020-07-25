#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu(){
	printf("******************\n");
	printf("***MENU INICIAL***\n");
	printf("*******FILA*******\n");
	printf("1- Inserir\n");
	printf("2- Furar Fila\n");
	printf("3- Remover\n");
	printf("4- Consultar Fila\n");
	printf("5- Sair\n\n");
}

int le_dados(){
	int valor = 0;
	printf("Qual opcao desejada:\n");
	scanf("%d", &valor);
	return valor;
}

void atencao(char *msg){
    printf("\n!!!! %s !!!!\n\n", msg);
}

void impressao(fila *f){
    if(vazia(f)){
        return;
    }
        
    if((f->fim - f->ini) >= 0){
        for(int i = f->ini; i <= f->fim; i++){
            printf("A posição %d : %d\n", i, f->v[i]);
        }
    }else{
        
        for(int i = f->ini; i < N; i++){
            printf("A posição %d : %d\n", i, f->v[i]);
        }
        for(int i = 0; i <= f->fim; i++){
            printf("A posição %d : %d\n", i, f->v[i]);
        }    
        
    }
    printf("\n");
}

void liberar(fila *p){
	free(p);
}

fila* criar(){
    fila *f = (fila*) malloc(sizeof(fila));
    f->qtd_elem = 0;
    f->ini = -1; 
    f->fim = -1;
    return(f);
}

int cheia(fila *f){
	if(f->qtd_elem == N){
		atencao("A fila está cheia");
		return 1;
	}else{ 
		return(0);
	}
}

int cheia_sp(fila *f){
	if(f->qtd_elem == N){
		return 1;
	}else{ 
		return(0);
	}
}

int vazia(fila *f){
	 if(f->qtd_elem == 0){
		atencao("A fila está vazia");
		return 1;
	}else{ 
		return(0);
	}
}

int vazia_sp(fila *f){
	 if(f->qtd_elem == 0){
		return 1;
	}else{ 
		return(0);
	}
}

void inserir(fila *f, int valor){
    if(cheia(f)){
        return;
    }
    
    if(vazia_sp(f)){ // se a fila esta vazia, inicio tambem deve ser alterado
        f-> ini = 0; 
        f-> fim = 0; 
    }else{
        f->fim++;
    }
        
    if( f->fim == N){ // Caso o valor de fim tenha passado da ultima posicao do vetor, ele deve retornar a posicao 0
        f->fim = 0; 
    }
    
    f->v[f->fim] = valor;
    f->qtd_elem++;	
}

int remover(fila *f){
    int valor;

    if(vazia_sp(f)){ // verificando se a fila está vazia
        atencao("Nao e possivel fazer remocao");
        return -1;
    }

    // salvando o valor do inicio da fila na variável valor
    valor = f->v[f->ini];

    // reduzindo o tamanho da fila passando o inicio para frente e reduzindo a quantidade de elementos
    f->ini++;
    f->qtd_elem--;

    if(f->ini == N) { // Caso o valor de ini tenha passado da ultima posicao do vetor, ele deve retornar a posicao 0
        f->ini = 0;
    }
    
    if(vazia_sp(f)){
        liberar(f);
        f = criar();
    }
    
    return valor; 
}

void furafila(fila *f, int inserido, int pos){
    if(cheia(f) || pos < 0 || pos == f->fim){
        if(!cheia_sp(f)){
            atencao("Posição invalida");
        }
        return;
    }else if(vazia_sp(f)){ // se a fila esta vazia, inicio tambem deve ser alterado
        inserir(f, inserido); 
        return;
    }else if((f->fim - f->ini) > 0){
        if((pos > f->fim) || (pos < f->ini)){
            atencao("Posicao invalida");
            return;     
        }
    }else{
        if( (pos > f->fim) && (pos < f->ini) ){ // for(int i = f->fim; i >= pos; i--)
            atencao("Posicao invalida");
            return;
        }
    }
    
    if((f->fim - f->ini) > 0){ //caso fila esteja positiva
        for(int i = f->fim; i >= pos; i--){
            if( i+1 == N){ // Caso o valor de fim tenha passado da ultima posicao do vetor, ele deve retornar a posicao 0
                f->v[0] = f->v[i];
                f->fim = -1;
            }else{
                f->v[i+1] = f->v[i];
            }
        }
        f->fim++;
    }else{ //caso fila esteja negativa
        
        for(int i = f->fim; i > -1; i--){
            f->v[i+1] = f->v[i];
        }
        
        f->v[0] = f->v[N-1];
        
            for(int i = N-2; i <= pos; i--){
                printf("\ni = %d\n",i);
                f->v[i+1] = f->v[i];
            } 
        }
        
        if(f->fim == N-1){
            f->fim = 0;    
        }else{
            f->fim++;   
        }
    }
   
    f->v[pos] = inserido;
    f->qtd_elem++;
}
