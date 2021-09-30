#include <stdio.h>

int main(int argc, char const *argv[]) {

    int i = 0, contador = 0, a;
    do {
        scanf("%d", &a);
        if (a < 0) {
            contador++;
        }
        i++;
    } while (i < 5);
    printf("%d números são negativos\n", contador);
    return 0;
}


/*
inicio
    inteiro i = 0, contador = 0, a;
    faça {
        leia(a);
        se (a < 0) então {
            contador <- contador + 1;
        }
        i <- i + 1;
    } enquanto (i < 5);
    escreva("números negativos =", contador);
fim
*/