// Para uso da fila
#define MAX 500

typedef struct NO* ArvBin;
// Para uso da fila
typedef struct fila Fila;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
//
int insere_EmLargura(ArvBin *raiz, int valor);
void desenheArvore(ArvBin *raiz, char TipoArv);
void desenheSubarvore(ArvBin *raizAbsoluta, ArvBin *raiz, int espacos, char separator[], char TipoArv);
struct NO* searchFatherEmLargura(ArvBin *raiz, int el);

struct NO* searchFather (ArvBin *raiz, int el);

int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor, int *info);
int consulta_ArvBinRec(ArvBin *raiz, int valor, int *info);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
// 
void visitaEmLargura(ArvBin *raiz);
int totalNO_ArvBin_Iter(ArvBin *raiz);
int altura_ArvBin_Iter(ArvBin *raiz);
void removerPar(ArvBin *raiz);

// Para uso da fila
Fila* cria_Fila();
void libera_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
int insere_Fila(Fila* fi,  struct NO *a1);
int insere_inicio_Fila(Fila* fi, struct NO *a1);

int remove_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct NO **a1);
