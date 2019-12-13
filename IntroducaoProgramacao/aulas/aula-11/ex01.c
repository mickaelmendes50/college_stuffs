#include <stdio.h>

float media (float *vet) {
    float soma = 0, med = 0;
    for (int i = 0; i < 10; i++) {
        soma = soma + vet[i];
    }
    med = soma/10;
    return med;
}

main () {
    float vet[10], m;

    for (int i = 0; i < 10; i++) {
        scanf("%f", &vet[i]);
    }

    m = media(vet);
    printf("%.1f", m);
}
