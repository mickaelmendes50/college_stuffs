#include <stdio.h>

main () {
    double num, soma;
    scanf("%lf", &num);

    if (num > 1) {
        for (double i = 0; i < num; i++) {
            soma += 1/(i+1);
        }
    } else {
        printf("Número inválido");
    }
    printf("%.6lf", soma);
}
