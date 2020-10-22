#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

using namespace std;

#define MAX 40000

typedef struct fila_prioridade FilaPrio;
FilaPrio* cria_FilaPrio();
void libera_FilaPrio(FilaPrio *fp);
int consulta_FilaPrio(FilaPrio *fp, int num);
int insere_FilaPrioDesordenada(FilaPrio *fp,int num,int prio);
int remove_FilaPrioDesordenada(FilaPrio *fp);
int insere_FilaPrioEncadeada(FilaPrio *fp,int num,int prio);
int remove_FilaPrioEncadeada(FilaPrio *fp);
int insere_FilaPrioHeap(FilaPrio *fp,int num,int prio);
int remove_FilaPrioHeap(FilaPrio *fp);
int insere_FilaPrioOrdenada(FilaPrio *fp,int num,int prio);
int remove_FilaPrioOrdenada(FilaPrio *fp);
int tamanho_FilaPrio(FilaPrio *fp);
int estaCheia_FilaPrio(FilaPrio *fp);
int estaVazia_FilaPrio(FilaPrio *fp);

struct ordenado{
    int num;
    int prio;
    struct ordenado *prox;
};
struct fila_prioridade{
    int qtd;
    struct ordenado dados[MAX];
    struct ordenado *inicio;
};

void libera_FilaPrio(FilaPrio* fp){
    free(fp);
}

FilaPrio * cria_FilaPrio(){
FilaPrio *fp;
fp = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
if(fp!=NULL){
    fp->qtd = 0;
    return fp;
    }
}
int insere_FilaPrioDesordenada(FilaPrio* fp, int num, int prio){
    if(fp==NULL){
        return 0;
    }
    if(fp->qtd == MAX){
        return 0;
    }
    int i = fp->qtd-1;

    fp->dados[i+1].num = num;
    fp->dados[i+1].prio = prio;
    fp->qtd++;
    return 1;

}
int remove_FilaPrioDesordenada(FilaPrio *fp){
    if(fp == NULL){
        return 0;
    }
    if(fp->qtd==0){
        return 0;
    }
    fp->qtd--;
    return 1;

}

void promoverElemento(FilaPrio *fp, int f){
int p;
struct ordenado temp;
p = (f-1)/2;
    while((f>0)&& (fp->dados[p].prio<= fp->dados[f].prio)){
        temp = fp->dados[f];
        fp->dados[f] = fp->dados[p];
        fp->dados[p] = temp;
        f = p;
        p = (p-1)/2;
    }
}
int insere_FilaPrioHeap(FilaPrio* fp, int num, int prio){
    if(fp==NULL){
        return 0;
    }
    if(fp->qtd == MAX){
        return 0;
    }
    int i = fp->qtd-1;

    fp->dados[fp->qtd].num = num;
    fp->dados[fp->qtd].prio = prio;
    promoverElemento(fp,fp->qtd);
    fp->qtd++;
    return 1;

}
void rebaixarElemento(FilaPrio *fp, int p){
    struct ordenado temp;
    int f = 2 * p +1;
    while(f < fp->qtd){
        if(f<fp->qtd-1){
            if(fp->dados[f].prio<fp->dados[f+1].prio){
                f++;
                if(fp->dados[p].prio>= fp->dados[f].prio){
                    break;
                }
            }
        }
        temp = fp->dados[p];
        fp->dados[p] = fp->dados[f];
        fp->dados[f] = temp;

        p = f;
        f = 2*p+1;

    }


}
int remove_FilaPrioHeap(FilaPrio *fp){
    if(fp == NULL){
        return 0;
    }
    if(fp->qtd==0){
        return 0;
    }
    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElemento(fp,0);
    return 1;

}

int insere_FilaPrioEncadeada(FilaPrio* fp, int num, int prio){
    struct ordenado *lista;


    if(fp==NULL){
        return 0;
    }
    if(fp->qtd == MAX){
        return 0;
    }
       lista = (struct ordenado*)malloc(sizeof(struct ordenado));
       lista->num = num ;
       lista->prio = prio;
        if(fp->qtd == 0){
            fp->inicio = lista;
            fp->inicio->prox = NULL;
        }else{
           struct  ordenado *aux;
            aux = fp->inicio;
            while(aux->prox!=NULL && prio < aux->prio){
                aux = aux->prox;
            }
            lista->prox = aux->prox;
            aux->prox = lista;
        }
        fp->qtd++;
        return 1;


    return 1;

}
int remove_FilaPrioEncadeada(FilaPrio *fp){
    if(fp == NULL){
        return 0;
    }
    if(fp->qtd==0){
        return 0;
    }
    struct ordenado * aux;
    aux = fp->inicio;
    fp->inicio = aux->prox;
    free(aux);
    fp->qtd--;

    return 1;

}

int insere_FilaPrioOrdenada(FilaPrio* fp, int num, int prio){
    if(fp==NULL){
        return 0;
    }
    if(fp->qtd == MAX){
        return 0;
    }
    int i = fp->qtd-1;
    while(i>= 0 && fp->dados[i].prio>=prio){
        fp->dados[i+1] = fp->dados[i];
        i--;
    }
    fp->dados[i+1].num = num;
    fp->dados[i+1].prio = prio;
    fp->qtd++;
    return 1;

}
int remove_FilaPrioOrdenada(FilaPrio *fp){
    if(fp == NULL){
        return 0;
    }
    if(fp->qtd==0){
        return 0;
    }
    fp->qtd--;
    return 1;

}

void mostra_Tempo(clock_t tempo_inicial, clock_t tempo_final) {
    double tempo;
    tempo = ((tempo_final - tempo_inicial) * 1000)/CLOCKS_PER_SEC;
    cout << "Tempo: " << tempo << endl;
}

int main() {
    FilaPrio* fp;
    fp = cria_FilaPrio();
    int n=1, i=0;

    clock_t tempo_inicial;
    tempo_inicial = clock();

    for(i=0; i<=MAX; i++){
        insere_FilaPrioDesordenada(fp,n,i);
        n++;
    }

    clock_t tempo_final;
    tempo_final = clock();

    cout << "Desordenada Inserção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);

    tempo_inicial = clock();
    for(i=0; i <=MAX; i++){
        remove_FilaPrioDesordenada(fp);
    }
    tempo_final = clock();

    cout << "Desordenada Remoção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);

    libera_FilaPrio(fp);
    fp = cria_FilaPrio();
    n=1;

    tempo_inicial = clock();

    for(i=0; i<=MAX; i++){
        insere_FilaPrioHeap(fp,n,i);
        n++;
    }

    tempo_final = clock();

    cout << "Heap Inserção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);

    n = 0;

    tempo_inicial = clock();
    for(i=0; i <=MAX; i++){
        remove_FilaPrioHeap(fp);
    }
    tempo_final = clock();

    cout << "Heap Remoção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);

    libera_FilaPrio(fp);
    fp = cria_FilaPrio();
    n=1;

    tempo_inicial = clock();

    for(i = 1; i<=MAX; i++){
        insere_FilaPrioEncadeada(fp,i,i);
    }

    tempo_final = clock();

    cout << "Encadeada Inserção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);

    tempo_inicial = clock();
    for(i=0; i<=MAX; i++){
        remove_FilaPrioEncadeada(fp);
    }
    tempo_final = clock();
    cout << "Encadeada Remoção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);

    libera_FilaPrio(fp);
    fp = cria_FilaPrio();
    n=1;
    int aleat=0;

    tempo_inicial = clock();

    for(i = 1; i<=MAX; i++){
        insere_FilaPrioOrdenada(fp,i,i);
    }

    tempo_final = clock();

    cout << "Ordenada Inserção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);
    n = 0;

    tempo_inicial = clock();
    for(i=0; i<=MAX; i++){
        remove_FilaPrioOrdenada(fp);
    }
    tempo_final = clock();
    cout << "Ordenada Remoção" << endl;
    mostra_Tempo(tempo_inicial, tempo_final);

    return 0;
}