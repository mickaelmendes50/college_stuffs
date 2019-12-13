#include <stdio.h>

unsigned int gerarNatural(unsigned int n, unsigned int m) {
    if (m != 0) {
        printf("%u ", m);
    }
    if (n == m) {
        return n;
    } else {
        return gerarNatural(n, (m+ 1));
    }
}

int main () {
    unsigned int n;
    scanf("%d", &n);
    gerarNatural(n, 0);
    return 0;
}