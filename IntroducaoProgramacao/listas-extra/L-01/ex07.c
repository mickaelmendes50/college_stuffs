#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    // Entrada dos valores
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Verifica quem é o menor
    int n1, n2, n3;
    if (a < b && a < c) {
        n1 = a;
    } else if (b < a && b < c) {
        n1 = b;
    } else {
        n1 = c;
    }

    // Verifica quem é o maior
    if (a > b && a > c) {
        n3 = a;
    } else if (b > a && b > c) {
        n3 = b;
    } else {
        n3 = c;
    }

    // Verifica qual o valor restante
    if (a != n1 && a != n3) {
        n2 = a;
    } else if (b != n1 && b != n3) {
        n2 = b;
    } else {
        n2 = c;
    }

    printf("%d %d %d\n", n1, n2, n3);
    
    return 0;
}
