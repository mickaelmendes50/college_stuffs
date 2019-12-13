#include <stdio.h>

unsigned int serieFibonacci(unsigned int n) {
    if (n == 0) {
        return 0;
    } else if (1 == n || n == 2) {
        return 1;
    } else {
        return serieFibonacci(n-1) + serieFibonacci(n-2);
    }
}

int main() {
    unsigned int n, i;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        printf("%u ", serieFibonacci(i));
    }
    return 0;
}