//
//conjunto.h
//
#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto Conjunto;

int criaConjunto(Conjunto* *C);
int conjuntoVazio(Conjunto* C);
int tamanhoConjunto(Conjunto* C);
int pertenceConjunto(int x, Conjunto* C);
int insereElementoConjunto(int x, Conjunto* C);
int excluirElementoConjunto(int x, Conjunto* C);
int maior(int x, Conjunto* C);
int menor(int x, Conjunto* C);
int conjuntosIdenticos(Conjunto* C1, Conjunto* C2);
int subconjunto(Conjunto *C1, Conjunto *C2);
Conjunto* complemento(Conjunto *C1, Conjunto *C2);
Conjunto* uniao(Conjunto *C1, Conjunto *C2);
Conjunto* interseccao(Conjunto *C1, Conjunto *C2);
Conjunto* diferenca(Conjunto *C1, Conjunto *C2);
int destroiConjunto(Conjunto* C);

//
// conjunto.c
//
struct conjunto{
    int *elementos;
    int quantidadeAtual;
};

int criaConjunto(Conjunto* *C){

    *C = (Conjunto*) malloc(sizeof(Conjunto));
    if( (*C) != NULL){
        (*C)->elementos = (int *) malloc(0 * sizeof(int));
        (*C)->quantidadeAtual = 0;
        return 1;
    }
    else 
        return 0;

}
int tamanhoConjunto(Conjunto* C){
    return C->quantidadeAtual;
}

int pertenceConjunto(int x, Conjunto* C){
    for(int i = 0; i< C->quantidadeAtual; i++){
        if(x == C->elementos[i])
            return 1;
    }
    return 0;
}

int insereElementoConjunto(int x, Conjunto* C){

    if(pertenceConjunto(x, C)){
        return 0;
    }
    C->quantidadeAtual++;
    // int valores_atuais[C->quantidadeAtual];
    // for(int i = 0; i<C->quantidadeAtual;i++){
    //     valores_atuais[i] = c->elementos[i];
    // }
    C->elementos = (int *) realloc(C->elementos, sizeof(int) * (C->quantidadeAtual));

    C->elementos[C->quantidadeAtual-1] = x;
}

int conjuntoVazio(Conjunto* C){
    if( C->quantidadeAtual ==0 )
        return 1;
    else
        return 0;
}
int excluirElementoConjunto(int x, Conjunto* C){
    if(pertenceConjunto(x, C)){
        for(int i = 0; i< C->quantidadeAtual; i++){
            if(C->elementos[i] == x){
                for(int j = i; j< C->quantidadeAtual-1;j++){
                    C->elementos[j] = C->elementos[j+1];
                }
            }
        }
        C->quantidadeAtual--;
        C->elementos = (int *) realloc(C->elementos, sizeof(int) * (C->quantidadeAtual));
    }
    return 0;
}
int maior(int x, Conjunto* C){
    int maiores = 0;
    for(int i = 0; i< C->quantidadeAtual; i++){
        if(C->elementos[i] > x){
            maiores++;
        }
    }
    return maiores;
}
int menor(int x, Conjunto* C){
    int menores = 0;
    for(int i = 0; i< C->quantidadeAtual; i++){
        if(C->elementos[i] < x){
            menores++;
        }
    }
    return menores;
}

int conjuntosIdenticos(Conjunto* C1, Conjunto* C2){
    if(C1->quantidadeAtual != C2->quantidadeAtual){
        return 0;
    }else{
        int tudo_igual=0;
        for(int i = 0; i< C1->quantidadeAtual; i++){
            if(pertenceConjunto(C1->elementos[i], C2)){
                tudo_igual++;
            }
        }
        if(tudo_igual == C1->quantidadeAtual)
            return 1;
        else
            return 0;
    }
}
int subconjunto(Conjunto *C1, Conjunto *C2){
    int tudo_igual=0;
        for(int i = 0; i< C1->quantidadeAtual; i++){
            if(pertenceConjunto(C1->elementos[i], C2)){
                tudo_igual++;
            }
        }
        if(tudo_igual == C1->quantidadeAtual)
            return 1;
        else
            return 0;
    
}
//complemento de c1 em relação a c2, são os numeros de c2 que não estão em c1 
Conjunto* complemento(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
    criaConjunto(&C3);
    for(int i = 0; i< C2->quantidadeAtual; i++){
            if(!pertenceConjunto(C2->elementos[i], C1)){
                insereElementoConjunto(C2->elementos[i], C3);
            }
        }
    return C3;
}

Conjunto* uniao(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
        criaConjunto(&C3);
        for(int i = 0; i< C2->quantidadeAtual; i++){
            if(!pertenceConjunto(C2->elementos[i], C1)){
                insereElementoConjunto(C2->elementos[i], C3);
            }
        }
        for(int i = 0; i< C1->quantidadeAtual; i++)
            insereElementoConjunto(C1->elementos[i], C3);
    return C3;
}
Conjunto* interseccao(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
    criaConjunto(&C3);
    for(int i = 0; i< C1->quantidadeAtual; i++){
        if(pertenceConjunto(C1->elementos[i], C2)){
            insereElementoConjunto(C2->elementos[i], C3);
        }
    }

    return C3;
}
Conjunto* diferenca(Conjunto *C1, Conjunto *C2){
    return complemento(C2,C1);
}

int destroiConjunto(Conjunto *C){
    if(C != NULL)
        free(C);
}

//
//main.c
//
int main(){
    Conjunto *C1, *C2, *C3, *C4, *C5, *C6, *C7;
    printf("Cojunto 1 criado %d \n", criaConjunto(&C1));
    printf("Conjunto Vazio? %d \n", conjuntoVazio(C1));
    insereElementoConjunto(0,C1);
    insereElementoConjunto(1,C1);
    insereElementoConjunto(2,C1);
    insereElementoConjunto(3,C1);
    insereElementoConjunto(4,C1);
    printf("elemento 1: %d\n", C1->elementos[0]);
    printf("elemento 2: %d\n", C1->elementos[1]);
    printf("elemento 3: %d\n", C1->elementos[2]);
    printf("elemento 4: %d\n", C1->elementos[3]);
    printf("elemento 5: %d\n", C1->elementos[4]);
    printf("Quantidade de elementos menores que 3: %d\n", menor(3,C1));
    printf("Quantidade de elementos maiores que 3: %d\n", maior(3,C1));
    printf("Conjunto Vazio? %d \n", conjuntoVazio(C1));
    printf("Conjunto 2 criado %d \n", criaConjunto(&C2));
    insereElementoConjunto(4,C2);
    insereElementoConjunto(3,C2);
    insereElementoConjunto(1,C2);
    insereElementoConjunto(2,C2);
    insereElementoConjunto(0,C2);
    printf("Conjunto 3 criado %d \n", criaConjunto(&C3));
    insereElementoConjunto(0,C3);
    insereElementoConjunto(1,C3);
    insereElementoConjunto(2,C3);
    insereElementoConjunto(3,C3);
    insereElementoConjunto(4,C3);
    insereElementoConjunto(5,C3);
    insereElementoConjunto(6,C3);
    printf("Conjunto 1 é igual ao 2? %d\n", conjuntosIdenticos(C1,C2));
    printf("Conjunto 1 é igual ao 3? %d\n", conjuntosIdenticos(C1,C3));
    printf("Conjunto 1 é subconjunto do 3? %d\n", subconjunto(C1,C3));
    printf("Conjunto 3 é subconjunto do 1? %d\n", subconjunto(C3,C1));
    printf("Criando Conjunto complemento de C1 em relação a C3\n");
    C4 = complemento(C1,C3);
    printf("elemento 1: %d\n", C4->elementos[0]);
    printf("elemento 2: %d\n", C4->elementos[1]);
    printf("Criando Conjunto união de C1 em relação a C3\n");
    C5 = uniao(C1,C3);
    printf("elemento 1: %d\n", C5->elementos[0]);
    printf("elemento 2: %d\n", C5->elementos[1]);
    printf("elemento 3: %d\n", C5->elementos[2]);
    printf("elemento 4: %d\n", C5->elementos[3]);
    printf("elemento 5: %d\n", C5->elementos[4]);
    printf("elemento 6: %d\n", C5->elementos[5]);
    printf("elemento 7: %d\n", C5->elementos[6]);
    printf("Criando Conjunto intersecção de C1 em relação a C3\n");
    C6 = interseccao(C1,C3);
    printf("elemento 1: %d\n", C6->elementos[0]);
    printf("elemento 2: %d\n", C6->elementos[1]);
    printf("elemento 3: %d\n", C6->elementos[2]);
    printf("elemento 4: %d\n", C6->elementos[3]);
    printf("elemento 5: %d\n", C6->elementos[4]);
    printf("elemento 6: %d\n", C6->elementos[5]);
    printf("Criando Conjunto diferença de C3 em relação a C1\n");
    C7 = diferenca(C3,C1);
    printf("elemento 1: %d\n", C7->elementos[0]);
    printf("elemento 2: %d\n", C7->elementos[1]);
    printf("elemento 3: %d\n", C7->elementos[2]);
    printf("elemento 4: %d\n", C7->elementos[3]);
    printf("elemento 5: %d\n", C7->elementos[4]);
    printf("quantidade atual: %d\n", C7->quantidadeAtual);
    destroiConjunto(C1);
    destroiConjunto(C2);
    destroiConjunto(C3);
    destroiConjunto(C4);
    destroiConjunto(C5);
    destroiConjunto(C6);
    destroiConjunto(C7);
    
}