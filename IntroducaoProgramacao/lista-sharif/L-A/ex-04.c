#include <stdio.h>

main () {
    float A, B, C, delta;
    scanf("%f %f %f", &A, &B, &C);

    delta = (B*B) - 4*A*C;
    printf("O VALOR DE DELTA E = %.2f \n", truncf(delta*100.0)/100.0);
}
