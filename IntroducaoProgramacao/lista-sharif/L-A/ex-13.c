#include <stdio.h>

main () {
    float a, b, c, d, e, f, x, y;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    scanf("%f", &e);
    scanf("%f", &f);

    x = ((c*e)-(b*f))/((a*e)-(b*d));
    y = ((a*f)-(c*d))/((a*e)-(b*d));

    printf("O VALOR DE X E = %.2f \n", truncf(x*100.0)/100.0);
    printf("O VALOR DE Y E = %.2f \n", truncf(y*100.0)/100.0);
}
