#include <stdio.h>

int main(int argc, char const *argv[]) {

    // Entrada dos valores
    int a, b, c;
    scanf("%d %d", &a, &b);

    // Verifica se a = b
    if (a == b) {
        c = a + b;
    } else {
        c = a * b;
    }
    
    printf("%d\n", c);

    return 0;
}
