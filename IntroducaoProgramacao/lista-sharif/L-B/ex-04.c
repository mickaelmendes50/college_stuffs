#include <stdio.h>

main () {
    int horas, valor, tres, i = 0;
    scanf("%d", &horas);

    if (horas >= 3) {
        while (horas >= 3) {
            horas = horas - 3;
            i++;
        }
        valor = (i*10)+(horas*5);
    } else {
        valor = horas*5;
    }

    printf("%d", valor);
}
