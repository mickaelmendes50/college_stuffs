#include <stdio.h>

main () {
    int vezes;
    double fahrenheit, celcius;
    scanf("%d", &vezes);

    for (int i = 0; i < vezes; i++) {
        scanf("%lf", &fahrenheit);
        celcius = (5*(fahrenheit-32))/9;
        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", fahrenheit, celcius);
    }
}

