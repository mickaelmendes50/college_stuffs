#include <stdio.h>

void printVetor(int *A) {
    printf("Vetor A: ");
    for (int l = 0; l < 16; l++) {
        printf("%d ", A[l]);
    }
    printf("\n");
}

int Slice(int *A, int ini, int fim, int p) {
    int random = ini + (p%(fim-ini+1));

    int temp = A[random];
    A[random] = A[fim];
    A[fim] = temp;

    int x = A[fim];
    int j = ini;

    for (int i = ini; i < fim-1; i++) {
        if (A[i] <= x) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            j = j+1;
        }
    }
    int tempo = A[fim];
    A[fim] = A[j];
    A[j] = tempo;

        printf("Slice:\n");
        printf("- ini: %d\n", ini);
        printf("- fim: %d\n", fim);
        printVetor(A);
        return j;
}

int Algoritmo1(int *A, int ini, int fim, int i, int p) {
        if (ini == fim) {
        return A[ini];
    }
    
    int m = Slice(A, ini, fim, p);
    int k = m - ini + 1;

    if (i == k) {
        return A[m];
    } else {
        if (i < k) {
            printf("Recursao caso 1:\n");
            printf("- ini: %d\n", ini);
            printf("- fim: %d\n", fim);
            printf("- m: %d\n", m);
            printVetor(A);
            return Algoritmo1(A, ini, m-1, i, p);
        }
        printf("Recursao caso 2:\n");
        printf("- ini: %d\n", ini);
        printf("- fim: %d\n", fim);
        printf("- m: %d\n", m);
        printVetor(A);
        return Algoritmo1(A, m+1, fim, i-k, p);
    }
}

int main(int argc, char const *argv[])
{
    int A[16] = {11,14,9,6,2,12,1,7,4,15,3,16,10,8,5,13};
    int ini=2, fim=9, i=4, p=6;

    printf("Algoritmo1: %d\n", Algoritmo1(A, ini, fim, i, p));

    return 0;
}
