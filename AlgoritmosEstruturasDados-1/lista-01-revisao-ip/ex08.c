#include <stdio.h>

int main () {
    int quant, i, div;
    //puts("Quantos numeros?");
    scanf("%d", &quant);
    int num[quant];

    for (i = 0; i < quant; i++) {
        scanf("%d", &num[i]);
        div = num[i]-1;
        if (div == 0) {
            printf("composto\n");
        } else {
            while (num[i]%div != 0) {
                div--;
            }
            if (div == 1) {
                printf("primo\n");
            } else {
                printf("composto\n");
            }   
        }
    }

    return 0;
}