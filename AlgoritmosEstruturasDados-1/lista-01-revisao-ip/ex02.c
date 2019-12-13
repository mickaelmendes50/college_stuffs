#include <stdio.h>

int main () {
    int n1, n2, a, b, c, invertido1, invertido2;
    //puts("Digite dois numeros");
    scanf("%d %d", &n1, &n2);

    a = n1%10;
    n1 = n1/10;
    b = n1%10;
    n1 = n1/10;
    c = n1;

    invertido1 = (a*100)+(b*10)+c;

    a = n2%10;
    n2 = n2/10;
    b = n2%10;
    n2 = n2/10;
    c = n2;

    invertido2 = (a*100)+(b*10)+c;

    if (invertido1 > invertido2) {
        printf("%d", invertido1);
    } else {
        printf("%d", invertido2);
    }

    return 0;
}