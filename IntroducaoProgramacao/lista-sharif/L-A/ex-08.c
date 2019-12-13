#include <stdio.h>

main () {
    float precoFabrica, percentualDistribuidor, percentualImpostos, precoFinal;
    scanf("%f %f %f", &precoFabrica, &percentualDistribuidor, &percentualImpostos);

    percentualDistribuidor = (percentualDistribuidor/100)*precoFabrica;
    percentualImpostos = (percentualImpostos/100)*precoFabrica;

    precoFinal = precoFabrica + percentualDistribuidor + percentualImpostos;

    printf("O VALOR DO CARRO E = %.2f \n", precoFinal);
}
