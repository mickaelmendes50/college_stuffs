#include <stdio.h>

main () {
    int num;
    scanf("%d", &num);

    if (num%3 == 0 && num%5 == 0) {
        printf("O NUMERO E DIVISIVEL");
    } else {
        printf("O NUMERO NAO E DIVISIVEL");
    }
}
