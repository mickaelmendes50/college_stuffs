#include <stdio.h>

main() {
    int razao, n, a1, an;

    printf("Entre com a razão:");
    scanf("%d", &razao);

    printf("Entre com o primeiro termo:");
    scanf("%d", &a1);

    printf("Entre com o elemento N:");
    scanf("%d", &n);
    an = a1+(n-1)*razao;

    printf("O elemento %d é %d", n, an);
}
