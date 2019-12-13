#include <stdio.h>

main () {
    int p1, p2, p3, p4;
    scanf("%d %d %d %d", &p1, &p2, &p3, &p4);

    if (p1 > 0 && p2 > 0 && p3 > 0 && p4 > 0) {

        if (p1 > 30 || p2 > 30 || p3 > 30 || p4 > 30) {
            printf("Nivel C, ");
        }
        else if ((p1 <= 30 && p1 >= 15) || (p2 <= 30 && p2 >= 15) || (p3 <= 30 && p3 >= 15) || (p4 <= 30 && p1 >= 15)) {
            printf("Nivel B, ");
        }
        else {
            printf("Nivel A, ");
        }

        if (p1 > p2 && p1 > p3 && p1 > p4) {
            printf("velocidade %d", p1);
        }
        else if (p2 > p1 && p2 > p3 && p2 > p4) {
            printf("velocidade %d", p2);
        }
        else if (p3 > p1 && p3 > p2 && p3 > p4) {
            printf("velocidade %d", p3);
        }
        else {
            printf("velocidade %d", p4);
        }
    }
    else {
        printf("Grupo invalido");
    }
}
