#include <stdio.h>

main () {
    int num;
    scanf("%d", &num);

    if (num > 1) {
        num = num*num;
        printf("Y = %d", num);
    } else if (num == 1) {
        num = 0;
        printf("Y = %d", num);
    } else if (num < 1){
        printf("Y = %d", num);
    }
}
