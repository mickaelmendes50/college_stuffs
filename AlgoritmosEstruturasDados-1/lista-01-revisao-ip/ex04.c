#include <stdio.h>

int main () {
    int quant, num, i, result[50], a, b;
    scanf("%d", &quant);

    if (quant >= 1) {
        for (i = 0; i < quant; i++) {
            scanf("%d", &num);
            if (num <= 9999) {
                a = num%10;
                b = (num/10)%10;
                result[i] = (a*1000)+(b*100)+(b*10)+a;

                if (result[i] == num) {
                    printf("yes ");
                } else {
                    printf("no ");
                }
            }
        }

        /*for (i = 0; i < quant; i++) {
            if (result[i] == num) {
                printf("yes ");
            } else {
                printf("no ");
            }
        }*/
    }    

    return 0;
}