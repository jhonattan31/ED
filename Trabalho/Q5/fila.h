#define N 5

typedef struct{
   int v[N];
   int qtd_elem;
   int ini, fim;
}fila;

void menu();
fila* criar();
int cheia(fila *p);
int vazia(fila *p);
void inserir(fila *p, int inserido);
void furafila(fila *p, int inserido, int pos);
int remover(fila *p);
int le_dados();
void atencao(char *msg);
void impressao(fila *p);
void liberar(fila *p);
int vazia_sp(fila *f);
int cheia_sp(fila *f);
