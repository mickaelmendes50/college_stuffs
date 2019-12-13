#include <stdio.h>

double le_numero(int x) {
    scanf("%d", &x);
    return x;
}

int main() {
    int n;
    double media, a;
    n = le_numero(n);

    for (int i = 0; n > i; i++) {
        scanf("%lf", &a);
        media += a;
    }
    printf("%.2lf", media/n);
}
