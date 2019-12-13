#include <stdio.h>

main () {
    float fahrenheit, celsius, chuvaPol, chuvaMm;
    scanf("%f %f", &fahrenheit, &chuvaPol);

    celsius = (5*(fahrenheit-32))/9;
    printf("O VALOR EM CELSIUS = %.2f \n", truncf(celsius*100.0)/100.0);
    chuvaMm = chuvaPol*25.4;
    printf("A QUANTIDADE DE CHUVA E = %.2f \n", truncf(chuvaMm*100.0)/100.0);
}
