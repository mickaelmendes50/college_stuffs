#include <stdio.h>

main () {
    int num;
    scanf("%d", &num);

    for (int i = 2; i <=num; i=i+2) {
        printf("%d^2 = %d\n", i, i*i);
    }
}
