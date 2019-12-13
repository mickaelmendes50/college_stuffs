#include <stdio.h>

main () {
    float raio, altura, custoPorMetro2, areaCirculo, areaLateral, areaTotal, custo, pi;
    scanf("%f %f", &raio, &altura);

    pi = 3.14159;
    //custoPorMetro2 = 100;
    areaCirculo = (pi*(raio*raio));
    areaLateral = 2*pi*raio*altura;
    areaTotal = (2*areaCirculo) + areaLateral;
    custo = areaTotal*100;
    printf("O VALOR DO CUSTO E = %.2f", truncf(custo*100.0)/100.0);
}
