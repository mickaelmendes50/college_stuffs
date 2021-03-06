
typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, int data);
int remove_ArvAVL(ArvAVL *raiz, int valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int umFilho_ArvAVL(ArvAVL *raiz, int valor);
int consulta_ArvAVL(ArvAVL *raiz, int valor);
int consultaNO(ArvAVL *raiz, int valor, int *limitInf, int *limitSup);
int consultaIntervalarAVL(ArvAVL *raiz, int valor, int *limitInf, int *limitSup);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
int getCont();
void resetCont();
