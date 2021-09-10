#include <stdio.h>

int main(int argc, char const *argv[]) {

    // Entrada dos valores
    float n1, n2;
    scanf("%f %f", &n1, &n2);

    // Aplica os pesos
    n1 *= 2;
    n2 *= 3;

    // Calcula a média
    float media = (n1 + n2)/5;
    printf("Media: %.1f\n", media);
    return 0;
}
