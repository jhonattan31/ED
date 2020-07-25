#define N 30

typedef struct{
	char v[N];
	int topo;
}pilha;

pilha* criar();
int cheia(pilha *p);
int vazia(pilha *p);
int vazia_sp(pilha *p);
void inserir(pilha *p, char inserido);
char remover(pilha *p);
void impressao(pilha *p, pilha *l);
pilha* inverter(pilha *p1);
void liberar(pilha *p);
