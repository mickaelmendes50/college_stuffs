#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Selection(int *vetor,int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(vetor[j]<vetor[min]){
            min=j;
            }
        }
        if(vetor[i]!=vetor[min]){
            troca(&vetor[i],&vetor[min]);
        }
    }
}

void troca(int *v,int *b){
    int aux;
    aux=*v;
    *v=*b;
    *b=aux;
}

int main()
{
    int *Vetoraux;
    int tamanho,i,j,cont,aux,test;
    do{
            scanf("%d",&test);
    }while((test<1)||(test>100));
    do{
        do{
            scanf("%d",&tamanho);
        }while((tamanho<1)||(tamanho>10000));
        int vetor[tamanho][2];
        Vetoraux=(int *) malloc(tamanho*sizeof(int));
        for(i=0;i<tamanho;i++){
            for(j=0;j<2;j++){
                scanf("%d",&vetor[i][j]);
            }
            Vetoraux[i]=(vetor[i][0]*60)+vetor[i][1];
        }
        Selection(Vetoraux,tamanho);
        aux=0;
        for(i=0;i<tamanho-1;i++){
            cont=0;
            for(j=i;j<tamanho;j++){
                if(Vetoraux[i]==Vetoraux[j]){
                    cont++;
                }
            }
            if(cont>aux){
                aux=cont;
            }
        }
        printf("%d\n",aux);
        free(vetor);
        free(Vetoraux);
        test--;
    }while(test>0);
    return 0;
}