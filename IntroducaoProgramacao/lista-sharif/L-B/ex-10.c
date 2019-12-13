#include <stdio.h>

main () {
    float n1, n2, n3, a, b, c;
    scanf("%f %f %f", &n1, &n2, &n3);

    if (n1 > n2 && n1 > n3) {
        a = n1;
        if (n2 > n3) {
            b = n2;
            c = n3;
        }
        else {
            b = n3;
            c = n2;
        }
    } else if (n2 > n1 && n2 > n3) {
        a = n2;
        if (n1 > n3) {
            b = n1;
            c = n3;
        }
        else {
            b = n3;
            c = n1;
        }
    }
    else {
        a = n3;
        if (n1 > n2) {
            b = n1;
            c = n2;
        }
        else {
            b = n2;
            c = n1;
        }
    }
    printf("%.2f, %.2f, %.2f", c, b, a);
}
