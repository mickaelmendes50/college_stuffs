#include <stdio.h>

main () {
    int n;
    double soma, a;

    scanf("%d", &n);

    if (n > 3) {
        a = n;
        for (int i = 1; i <= n; ++i) {
            soma += (a/(i*i));
        }
        printf("%.5lf\n", soma);
    } else {
        printf("Numero invalido!\n");
    }
}
