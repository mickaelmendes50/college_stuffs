#include <stdio.h>

main () {
    float salMinimo, kWatt, precoKWatt, valorConsumo, comDesconto;
    scanf("%f %f", &salMinimo, &kWatt);

    precoKWatt = (salMinimo*0.007);
    printf("Custo por kW: R$%.2f \n", truncf(precoKWatt*100.0)/100.0);

    valorConsumo = precoKWatt * kWatt;
    printf("Custo do consumo: R$%.2f \n", truncf(valorConsumo*100.0)/100.0);

    comDesconto = (valorConsumo * 0.1) - valorConsumo;
    printf("Custo com desconto: R$%.2f \n", -truncf(comDesconto*100.0)/100.0);
}
