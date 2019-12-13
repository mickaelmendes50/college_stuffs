#include <stdio.h>

int fatorial(int num) {
    int resultado = 1;

    while (num > 1) {
        resultado = resultado*num;
        num--;
    }
    return resultado;
}

main() {
    int v1, resultado;
    scanf("%d", &v1);

    resultado = fatorial(v1);
    printf("%d", resultado);
}
