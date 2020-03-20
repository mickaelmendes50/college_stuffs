#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ArvoreBinaria.h"

using namespace std;

void bubble_sort(vector<int> &vet) {
    int i, j, cont = 0;
    for(i = 0; i < vet.size(); i++){
        for(j = 0; j < vet.size()-1; j++){
            if(vet[j] > vet[j+1]){
                int tmp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = tmp;
            }
        }
    }
}

int main()
{
    //int N, dados[] = {50,100,30,20,40,45,35,37};
    //int N, dados[] = {50, 46, 65,35, 47, 75, 15, 40, 70, 85, 5, 38, 42, 36, 43};
    //int N, dados[] = {4, 2, 6, 1, 3, 5, 10, 8};
    int N, dados[] = {33, 15, 41, 38, 47, 34, 43, 49};
    //int N, dados[] = {92, 2, 100, 1, 58, 98, 10, 81, 96, 77, 95, 79, 94, 93};

    N = sizeof(dados)/sizeof(dados[0]);

    ArvBin* raiz = cria_ArvBin();
    int i, info;
    
    for(i=0; i < N; i++)
        insere_ArvBin(raiz, dados[i]);

    desenheArvore(raiz, 'B'); // Desenho de �rvore bin�ria de Busca

    printf("\n\nPercurso em pre-ordem:\n");
    preOrdem_ArvBin(raiz);
    printf("\n\nPercurso em-ordem:\n");
    emOrdem_ArvBin(raiz);
    printf("\n\nPercurso pos-ordem:\n");
    posOrdem_ArvBin(raiz);

    printf("\n\n");
    
    //printf("\n\nTotal de nos da arvore (rec): %i\n", totalNO_ArvBin(raiz));
    //printf("\n\nTotal de nos da arvore (iter): %i\n\n", totalNO_ArvBin_Iter(raiz));    
    printf("\nAltura da arvore (rec): %i\n", altura_ArvBin(raiz));
    //printf("\nAltura da arvore (iter): %i\n\n", altura_ArvBin_Iter(raiz));
    
    printf("\nPercurso largura:\n");
    visitaEmLargura(raiz);

   vector<int> vet;
   printf("\n\nPercurso em-ordem (sem pares):\n");
   for (int i = 0; i < 50; i++) {
      if (consulta_ArvBin(raiz, i, &info)) {
         vet.push_back(i);
      }
   }

   bubble_sort(vet);
   cout << vet[vet.size()-1];
 

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    system("pause > nul");
    return 0;
}

