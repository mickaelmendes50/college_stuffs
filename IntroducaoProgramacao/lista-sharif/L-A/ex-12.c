#include <stdio.h>

main () {
    int valor, R100, R50, R10, R1;
    scanf("%d", &valor);

        R100 = valor/100;
        valor = valor - (R100*100);
        R50 = valor/50;
        valor = valor - (R50*50);
        R10 = valor/10;
        valor = valor - (R10*10);
        R1 = valor;

    printf("NOTAS DE 100 = %d \n", R100);
    printf("NOTAS DE 50 = %d \n", R50);
    printf("NOTAS DE 10 = %d \n", R10);
    printf("MOEDAS DE 1 = %d \n", R1);
}
