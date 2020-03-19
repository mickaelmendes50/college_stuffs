#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

//Defini��o do tipo Fila
struct elemento{
    //struct aluno dados;
    struct NO *dados;
    struct elemento *prox;
};

typedef struct elemento Elem;
//Defini��o do N� Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};
   

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}


int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento j� existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}


int insere_EmLargura(ArvBin *raiz, int valor)
{
 if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else {	
   	struct NO *q;
   	Fila* f = cria_Fila(); // fila auxiliar
   	insere_Fila(f, *raiz); /* insere raiz na fila */
   	do {
      	if (consulta_Fila(f, &q)) {
         	remove_Fila(f); /* retira n� q da fila */
         	if (q != NULL) { /* q � n�o vazio ? */
            	if (q->esq == NULL) {
               		q->esq = novo;
               		break;
         		}
               
            	insere_Fila(f, q->esq); /* insere sub-�rvore esq. na fila */
            	if (q->dir == NULL) {
            		q->dir = novo;
               	break;
					}
            	insere_Fila(f, q->dir); /* insere sub-�rvore dir. na fila */
         	}
      	}
   	} while (!Fila_vazia(f));  
	}	// Fim if
	return 1;
}


struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}


// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    //printf("alt_esq de %i: %i ", (*raiz)->info, alt_esq);
    
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    //printf("alt_dir de %i: %i ", (*raiz)->info, alt_esq);
    return(alt_esq + alt_dir + 1);
}


int totalNO_ArvBin_Iter(ArvBin *raiz)
{
   struct NO *q;
   Fila* f = cria_Fila(); // fila auxiliar
   insere_Fila(f, *raiz); /* insere raiz na fila */
   int Cont = 0;
   do {
      if (consulta_Fila(f, &q)) {
         remove_Fila(f); /* retira n� q da fila */
         if (q != NULL) { /* q � n�o vazio ? */
            Cont++;
            insere_Fila(f, q->esq); /* insere sub-�rvore esq. na fila */
            insere_Fila(f, q->dir); /* insere sub-�rvore dir. na fila */
         }
      }
   } while (!Fila_vazia(f));  
   return Cont;
}


int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    //printf("alt_esq de %i: %i ", (*raiz)->info, alt_esq);
    
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    //printf("alt_dir de %i: %i ", (*raiz)->info, alt_dir);
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


int altura_ArvBin_Iter(ArvBin *raiz)
{
   struct NO *q;
   Fila* f = cria_Fila(); // fila auxiliar
   insere_Fila(f, *raiz); // insere raiz na fila
   int ContEsq = 0;
   int ContDir = 0;
   int Altura = 0;
   int JaCalcAlt;
   
   do {
      if (consulta_Fila(f, &q)) {
         
         remove_Fila(f); // retira n� q da fila 
         JaCalcAlt = 0;
         if (q != NULL) { // q � n�o vazio ? 
            if (q->esq != NULL) {
               printf("\nq->esq: %i Altura: %i", q->esq->info, Altura);
               if (!JaCalcAlt) {
                  ContEsq++;
                  printf("ContEsq++ ");
                  JaCalcAlt = 1;
               }
               printf(" q->info: %i", q->info);
               
            }
               
            insere_Fila(f, q->esq); // insere sub-�rvore esq. na fila

            if (q->dir != NULL) {
               //printf("\nq->dir: %i ", q->dir->info);
               printf("\nq->dir: %i Altura: %i", q->dir->info, Altura);
               
               if (!JaCalcAlt) {
                  ContDir++;
                  printf("ContDir++ ", q->info);
                  
                  JaCalcAlt = 1;
               }
               printf(" q->info: %i", q->info);
            }

            insere_Fila(f, q->dir); // insere sub-�rvore dir. na fila             
         }
      }
   } while (!Fila_vazia(f));  
   
   printf("\nContEsq: %i\nContDir: %i", ContEsq, ContDir);
   printf("\nAltura: %i\n", Altura);
   if (ContDir > ContEsq)
      return ContDir + 1;
   else
       return ContEsq + 1;
}


int consulta_ArvBin(ArvBin *raiz, int valor, int *info)
{
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;

    while(atual != NULL){
        if(valor == atual->info){
           *info = atual->info;
           return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

// Corrigir erro decorrente de quando o valor n�o � encontrado
int consulta_ArvBinRec(ArvBin *raiz, int valor, int *info)
{
    if(raiz == NULL)
       return 0;
        
    struct NO* atual = *raiz;
    
    if(valor == atual->info)
       return 1;
    else if(valor < atual->info)
       consulta_ArvBinRec(&((*raiz)->esq), valor, info);
    else
       consulta_ArvBinRec(&((*raiz)->dir), valor, info);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d, ",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }

}


void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d, ",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}


void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d, ",(*raiz)->info);
    }
}

void visitaEmLargura(ArvBin *raiz)
{
   struct NO *q;
   Fila* f = cria_Fila(); // fila auxiliar
   insere_Fila(f, *raiz); /* insere raiz na fila */
   do {
      if (consulta_Fila(f, &q)) {
         remove_Fila(f); /* retira n� q da fila */
         if (q != NULL) { /* q � n�o vazio ? */
            printf("(%d) ", q->info);
            if (q->esq == NULL)
               //printf("e%d:null ", q->info);
               printf("null ");
            else
               printf("%i ", q->esq->info);
            insere_Fila(f, q->esq); /* insere sub-�rvore esq. na fila */
            if (q->dir == NULL)
               //printf("d%d ", q->info);
               printf("null ");
            else
               printf("%i ", q->dir->info);
            insere_Fila(f, q->dir); /* insere sub-�rvore dir. na fila */
         }
      }
   } while (!Fila_vazia(f));  
}


void desenheArvore(ArvBin *raiz, char TipoArv)
{
     char separador[10];
     separador[0] = ' ';
     separador[1] = 192;
     separador[2] = 196;
     separador[3] = 196;
     separador[4] = '\0';

     strcpy(separador, " |__");

     if(raiz == NULL)
        return;

     if (*raiz == NULL) {
        printf("�rvore vazia!");
        return;
     }

     printf("Arvore Binaria de Busca:\n");
     printf("%i (R)\n", (*raiz)->info);
     desenheSubarvore(raiz, &((*raiz)->esq), 0, separador, TipoArv);
     desenheSubarvore(raiz, &((*raiz)->dir), 0, separador, TipoArv);
}


void desenheSubarvore(ArvBin *raizAbsoluta, ArvBin *raiz, int espacos, char separator[], char TipoArv)
{
     int e;
     struct NO *noPai;

     if (*raiz != NULL) {
        for (e=1; e<=espacos; e++)
            printf(" ");

        if (TipoArv == 'B')
          noPai = searchFather(raizAbsoluta, (*raiz)->info);
        else  // TipoArv == 'D'
          noPai = searchFatherEmLargura(raizAbsoluta, (*raiz)->info);


        if (noPai->esq == *raiz)
        //if (noPai->esq == *raizAbsoluta)
           printf("%s%d (E)\n", separator, (*raiz)->info);
        else
           printf("%s%d (D)\n", separator, (*raiz)->info);
        //printf("%s%d\n", separator, (*raiz)->info);
        desenheSubarvore(raizAbsoluta, &((*raiz)->esq), espacos+4, separator, TipoArv);
        desenheSubarvore(raizAbsoluta, &((*raiz)->dir), espacos+4, separator, TipoArv);
     }
}

struct NO* searchFatherEmLargura(ArvBin *raiz, int valor)
{
   struct NO *noPai = NULL;
   struct NO *q;
   Fila* f = cria_Fila(); // fila auxiliar
   insere_Fila(f, *raiz); /* insere raiz na fila */
   do {
      if (consulta_Fila(f, &q)) {
         remove_Fila(f); /* retira n� q da fila */
         if (q != NULL) { /* q � n�o vazio ? */
            if (q->esq != NULL && q->esq->info == valor) {
              noPai = q;
              break;
            }
            insere_Fila(f, q->esq); /* insere sub-�rvore esq. na fila */

            if (q->esq != NULL && q->dir->info == valor) {
              noPai = q;
              break;
            }
            insere_Fila(f, q->dir); /* insere sub-�rvore dir. na fila */
         }
      }
   } while (!Fila_vazia(f));
   return noPai;
}


struct NO* searchFather(ArvBin *raiz, int el) 
{
      struct NO* p = *raiz;
		struct NO* prev = NULL; 

		while (p != NULL && p->info != el) {  // acha o n� p com a chave el
			prev = p;                           
			if (p->info < el)
               p = p->dir;
			else 
               p = p->esq;
		}
		if (p != NULL && p->info == el) {
           return prev;
        }
           
		return NULL;
}

void removerPar(ArvBin *raiz){
    remove_ArvBin(raiz, 34);
    remove_ArvBin(raiz, 38);
}


// Para uso da fila
Fila* cria_Fila()
{
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->qtd = 0; // 31/08/2017 - 16h30  
        fi->inicio = 0;
        fi->final = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi)
{
    free(fi);
}

int insere_Fila(Fila* fi, struct NO *al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}


int insere_inicio_Fila(Fila* fi, struct NO *al)
{
    if(fi == NULL)
       return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
       return 0;
    no->dados = al;
    no->prox = fi->inicio;
    fi->inicio = no;
    if (fi->final == NULL) //fila vazia
       fi->final = no;      
    
    fi->qtd++;
    return 1;
}


int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int Fila_cheia(Fila* fi)
{
    if(fi == NULL)
        return -1;
    //if (fi->inicio == (fi->final+1)%MAX)   // 31/08/2017 - 16h28
        //return 1;
    else
        return (fi->qtd == MAX);
}

int Fila_vazia(Fila* fi)
{
    if(fi == NULL)
        return -1;
    //return (fi->inicio == fi->final);  // 31/08/2017 - 16h28
    return (fi->qtd == 0);
}


int consulta_Fila(Fila* fi, struct NO **al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

