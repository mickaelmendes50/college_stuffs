#include <stdio.h>

main () {
    int N, A, S;
    printf("Informe um número");
    scanf("%d", &N);
    A = N - 1;
    S = N + 1;
    printf("O antecessor é %d e o sucessor é %d", A, S);
}

// Segundo método

include <stdio.h>

main () {
    int N;
    printf("Informe um número");
    scanf("%d", &N);
    A = N - 1;
    S = N + 1;
    printf("O antecessor é %d e o sucessor é %d", N--, N++);
}
