#include <stdio.h>
#include <math.h>

int main () {
    int quant, i;
    //printf ("%Lf", MAX);
    scanf("%d", &quant);
    if (quant >= 1 && quant <= 50) {
        long double n1[quant], n2[quant], result[quant];
        for (i = 0; i < quant; i++) {
            scanf("%Le %Le", &n1[i], &n2[i]);
            result[i] = n1[i]*n2[i];
            printf("%.0Lf\n", result[i]);
        }
    }
    return 0;
}