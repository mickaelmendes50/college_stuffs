#include <stdio.h>
#include <math.h>

int fatorial(int n1, int n2) {
    int resultado;
    resultado = n1+n2;
    return resultado;
}

main() {
    int v1, v2, resultado;
    scanf("%d %d", &v1, &v2);

    resultado = fatorial(v1,v2);
    printf("%d", resultado);
}

