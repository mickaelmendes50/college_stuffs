#include <stdio.h>

int main(int argc, char const *argv[]) {
    // Entrada de valores
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    
    // Verifica se A + B < C
    if (A + B < C) {
        printf("A + B é menor que C\n");
    } else {
        printf("A + B é maior que C\n");
    }

    return 0;
}
