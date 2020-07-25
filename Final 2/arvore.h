

typedef struct arvore Arvore;

typedef struct no No;

Arvore* criar();

void inserir(Arvore *a, int valor);

int remover(Arvore *a);

int vazia(Arvore *a);

int cheia(Arvore *a);

/*int altura_No(No *no);

int calcBalanceamento(No *no);

int maior_Valor(int a, int b);

void rotacaoEsq(Arvore *a);

void rotacaoDir(Arvore *a);

void rotacaoEsqDir(Arvore *a);

void rotacaoDirEsq(Arvore *a);
*/
void liberar(Arvore *a);
