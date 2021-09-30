#include <stdio.h>

int main(int argc, char const *argv[]) {
    int numero, soma = 0, contador = 0;
    do {
        scanf("%d", &numero);

        // Se o numero for maior que zero, ou seja,
        // se o número for positivo, ele entra na soma;
        if (numero > 0) {
            soma+=numero;
            contador++;
        }
    } while (numero > 0);
    int media = soma/contador;
    //printf("soma: %d\n", soma);
    //printf("cont: %d\n", contador);  
    printf("Media: %d\n", media); 
    return 0;
}

/*
inicio
    inteiro numero, soma <- 0, contador <- 0;
    faça {
        leia(numero);

        // Se o numero for maior que zero, ou seja,
        // se o número for positivo, ele entra na soma;
        se (numero > 0) então {
            soma <- soma + numero;
            contador <- contador + 1;
        }
    } enquanto (numero > 0);

    inteiro media <- soma/contador;
    escreva("Media =", media); 
fim
*/