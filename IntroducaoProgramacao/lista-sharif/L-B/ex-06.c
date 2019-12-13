#include <stdio.h>

main () {
    float salario;
    scanf("%f", &salario);

    if (salario <= 300) {
        salario += (salario*0.5);
    } else {
        salario += (salario*0.3);
    }
    printf("SALARIO COM REAJUSTE = %.2f", salario);
}
