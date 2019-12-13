#include <stdio.h>

main () {
    int cc, dr, rt, aux;
    scanf("%d %d %d", &cc, &dr, &rt);
    aux = 0;

    if (cc < 7) {
        aux = 1;
    }
    if (dr > 50) {
        aux++;
    }
    if (rt > 80000) {
        aux++;
    }

    if (aux == 1) {
        printf("ACO DE GRAU = 8");
    } else if (aux == 2) {
        printf("ACO DE GRAU = 9");
    } else if (aux == 3) {
        printf("ACO DE GRAU = 10");
    } else {
        printf("ACO DE GRAU = 7");
    }
}
