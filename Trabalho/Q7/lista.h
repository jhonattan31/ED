typedef struct no{
	int valor;
	struct no *prox;
	struct no *ant;
}No;

typedef struct lista{
    No *ini;
    No *fim;
    int qtd_elem;
}Lista;

void menu();

Lista* criar();

void inserir(Lista *l, int valor, int pos);

int remover(Lista *l, int pos);

int vazia(Lista *l);

int cheia(Lista *l);

void imprimir(Lista *l, int pos);

void liberar(Lista *l);

void duas_lista(Lista *l);
