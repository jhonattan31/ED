
#define N 20
typedef struct{
	int v[N];
	int topo; 
}pilha;

pilha* criar();
int cheia(pilha *p);
int vazia(pilha *p);
int inserir(pilha *p, int inserido);
int remover(pilha *p);
void impressao(pilha *p);
int le_dados();
pilha* inverter(pilha *p1);
void liberar(pilha *p);
