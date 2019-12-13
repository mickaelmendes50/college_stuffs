#include <stdio.h>
#include <math.h>

main () {
    float volume, altura, aresta, areaBase;
    scanf("%f %f", &altura, &aresta);

    areaBase = ((3*(aresta*aresta))*sqrt(3))/2;
    volume = (1*areaBase*altura)/3;
    printf("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS \n", truncf(volume*100.0)/100.0);
}
