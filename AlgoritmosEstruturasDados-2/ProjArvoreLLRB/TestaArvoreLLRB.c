#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"

int main()
{
    ArvLLRB * raiz = cria_ArvLLRB();
  
    int i, tamVetInt, vetInt[] ={20, 15, 30, 85, 50, 21, 70};
  
  	tamVetInt = sizeof(vetInt)/sizeof(vetInt[0]);
  	
  	printf("Arvore Rubro-Negra\n\n");
    for(i = 0; i < tamVetInt; i++){
        /*
        if(insere_ArvLLRB(raiz,val[i]))
            printf("Insercao: %d -> OK\n",val[i]);
        else
            printf("Insercao: %d -> ERRO\n",val[i]);
        */
        //printf("Insercao: %d -> OK\n",val[i]);
        insere_ArvLLRB(raiz, vetInt[i]);
    }

    //printf("Tamanho: %d \n",totalNO_ArvLLRB(raiz));
    printf("Travessia em-ordem:\n\n");
    emOrdem_ArvLLRB(raiz, 0);
    
	printf("\n\nTravessia pre-ordem:\n\n");
    preOrdem_ArvLLRB(raiz, 0);
    
    printf("\n\nTravessia pos-ordem:\n\n");
    posOrdem_ArvLLRB(raiz, 0);

    printf("\n----------------------------------------\n\n");
/*
    if(remove_ArvLLRB(raiz,10))
        printf("Remocao: Sucesso!\n\n");
    else
        printf("Remocao: Erro!\n\n");
    emOrdem_ArvLLRB(raiz,0);
*/
    remove_ArvLLRB(raiz, 15);
    printf("Depois de removido o no de chave 15...\n");
    printf("\n\nTravessia em-ordem:\n\n");
    emOrdem_ArvLLRB(raiz, 0);

    printf("\n\nTravessia pre-ordem:\n\n");
    preOrdem_ArvLLRB(raiz, 0);
    
    printf("\n\nTravessia pos-ordem:\n\n");
    posOrdem_ArvLLRB(raiz, 0);

    system("pause > nul");
    return 0;
}

