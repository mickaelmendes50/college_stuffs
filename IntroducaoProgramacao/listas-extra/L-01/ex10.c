#include <stdio.h>

int main(int argc, char const *argv[]) {

    // Entrada dos valores
    int a, b;
    scanf("%d %d", &a, &b);

    if (b%a == 0 || a%b == 0) {
        printf("São múltiplos\n");
    } else {
        printf("Não são múltiplos\n");
    }
    
    return 0;
}
