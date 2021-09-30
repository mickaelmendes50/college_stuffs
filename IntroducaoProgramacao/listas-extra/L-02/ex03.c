#include <stdio.h>

int main(int argc, char const *argv[]) {
    real tamanho_chico = 1.5, crescimento_chico = 0.02;
    real tamanho_ze = 1.1, crescimento_ze = 0.03;
    int anos = 0;

    while (tamanho_chico > tamanho_ze) {
        tamanho_chico += crescimento_chico;
        tamanho_ze += crescimento_ze;
        anos++;
    }
    //printf("Chico: %.2f\n", tamanho_chico);
    //printf("Ze: %.2f\n", tamanho_ze);
    printf("Anos: %d\n", anos);
    return 0;
}

/*
inicio
    real tamanho_chico = 1.5, crescimento_chico = 0.02;
    real tamanho_ze = 1.1, crescimento_ze = 0.03;
    inteiro anos = 0;

    enquanto (tamanho_chico > tamanho_ze) {
        tamanho_chico <- tamanho_chico + crescimento_chico;
        tamanho_ze <- tamanho_ze + crescimento_ze;
        anos <- anos + 1;
    }
    escreva("Anos:", anos);
fim
*/