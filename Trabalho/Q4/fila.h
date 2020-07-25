#define N 30

typedef struct{
	int inicio;
	int fim;
	int v[N];
}fila;

void menu();
fila* criar();
int cheia(fila *p);
int vazia(fila *p);
int vazia_sp(fila *p);
void inserir(fila *p, int inserido);
int remover(fila *p);
int le_dados();
void impressao(fila *p);
void liberar(fila *p);
