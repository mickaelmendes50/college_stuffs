#include <stdio.h>

main () {
    int numero, a, b, c, valor;
    scanf("%d", &numero);

    if (numero < 999) {
        c = numero%10;
        numero = numero/10;

        b = numero%10;
        numero = numero/10;

        a = numero;
        valor = (c*100)+(b*10)+(a);
        printf("%d", valor);
    }
    else {
        printf("INVÁLIDO");
    }
}
