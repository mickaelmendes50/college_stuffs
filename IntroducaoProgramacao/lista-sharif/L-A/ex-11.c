#include <stdio.h>

main () {
    int numero, a, b, c;
    scanf("%d", &numero);

    a = numero/100;
    b = ((a*100)-numero)/10;
    b = -b;
    c = (a*100)+(b*10)-numero;
    c = -c;

    printf("%d%d%d", c, b, a);
}
