
//Arquivo FilaPrioridade.h
#define MAX 100

typedef struct fila_prioridade FilaPrio;

FilaPrio* cria_FilaPrio();
void libera_FilaPrio(FilaPrio* fp);
int consulta_FilaPrioHeap(FilaPrio* fp, char* nome);
int consulta_FilaPrioArray(FilaPrio* fp, char* nome);
int insere_FilaPrioHeap(FilaPrio* fp, char *nome, int  prioridade);
int insere_FilaPrioArray(FilaPrio* fp, char *nome, int  prioridade);
int remove_FilaPrioHeap(FilaPrio* fp);
int remove_FilaPrioArray(FilaPrio* fp);
int tamanho_FilaPrio(FilaPrio* fp);
int estaCheia_FilaPrio(FilaPrio* fp);
int estaVazia_FilaPrio(FilaPrio* fp);
void imprime_FilaPrio(FilaPrio* fp);
