#include <stdio.h>

main () {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    if (n1%2==0) {
            for (int i = 1; i < n2; i++) {
            n1+=2;
            printf("%d\n", n1);
        }
    } else {
        printf("O PRIMEIRO NUMERO NAO E PAR");
    }
}

