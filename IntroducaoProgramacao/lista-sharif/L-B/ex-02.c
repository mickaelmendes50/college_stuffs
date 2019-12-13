#include <stdio.h>

main () {
    int conta;
    float consumo, residencial, comercial, industrial;
    char consumidor;
    scanf("%d %f %c", &conta, &consumo, &consumidor);
    printf("CONTA = %d \n", conta);

    if (consumidor == 'r' || consumidor == 'R') {
        residencial = 5 + (0.05*consumo);
        printf("VALOR DA CONTA = %.2f", truncf(residencial*100.0)/100.0);
    }
    if (consumidor == 'c' || consumidor == 'C') {
        if (consumo > 80) {
            comercial = 500 + ((consumo-80)*0.25);
            printf("VALOR DA CONTA = %.2f", truncf(comercial*100.0)/100.0);
        } else {
            comercial = 500;
        }
    }
    if (consumidor == 'i' || consumidor == 'I') {
        industrial = 800 + ((consumo-100)*0.04);
        printf("VALOR DA CONTA = %.2f", truncf(industrial*100.0)/100.0);
    }
}
