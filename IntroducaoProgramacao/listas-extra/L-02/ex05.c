#include <stdio.h>

int main(int argc, char const *argv[]) {
    int numero, soma = 0, contador = -1;
    do {
        scanf("%d", &numero);

        // Se o resto da divisão de numero por 2 for diferente de zero,
        // ou seja, se o número for ímpar, ele não entra na soma;
        if (!(numero%2 != 0)) {
            soma+=numero;
            contador++;
        }
    } while (numero != 0);
    int media = soma/contador;
    //printf("soma: %d\n", soma);
    //printf("cont: %d\n", contador);  
    printf("Media: %d\n", media); 
    return 0;
}

/*
inicio
    inteiro numero, soma <- 0, contador <- -1;
    faça {
        leia(numero);

        // Se o resto da divisão de numero por 2 for zero,
        // ou seja, se o número for par, ele entra na soma;
        se (numero%2 == 0)) então {
            soma <- soma + numero;
            contador <- contador + 1;
        }
    } enquanto (numero != 0);

    inteiro media <- soma/contador;
    escreva("Media =", media); 
fim
*/