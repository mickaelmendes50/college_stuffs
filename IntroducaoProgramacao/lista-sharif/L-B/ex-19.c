#include <stdio.h>

main () {
    float a, b ,c;
    scanf("%f %f %f", &a, &b, &c);

    if ((a<b+c) && (b<a+c) && (c<a+b)) {
        printf("Perimetro = %.1f", a+b+c);
    } else {
        printf("Area = %.1f", ((a+b)*c)/2);
    }
}
