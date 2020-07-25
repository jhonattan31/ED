typedef struct no* Arvore;

int altura_No(struct no *n)

int calcBalanceamento(struct no *n);

int maior_Valor(int a, int b);

int inserir(Arvore *a, int valor);

int remover(Arvore *a);

void rotacaoEsq(Arvore *a);

void rotacaoDir(Arvore *a);

void rotacaoEsqDir(Arvore *a);

void rotacaoDirEsq(Arvore *a);

void liberar(Arvore *a);
