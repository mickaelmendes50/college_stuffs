#include <stdio.h>
#include <math.h>

main () {
    float L1, L2, L3, T, A;
    scanf("%f", &L1);
    scanf("%f", &L2);
    scanf("%f", &L3);

    T = (L1 + L2 + L3)/2;
    A = sqrt(T*(T-L1)*(T-L2)*(T-L3));
    printf("%.2f", truncf(A*100.0)/100.0);
}
