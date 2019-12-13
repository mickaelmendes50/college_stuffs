#include <stdio.h>

main () {
    int horas, minutos, segundos, sM, sH, sS;

    scanf("%d", &horas);
    scanf("%d", &minutos);
    scanf("%d", &segundos);

    sM = minutos * 60;
    sH = horas * 60 * 60;
    //sH = sH * 60;
    sS = sH + sM + segundos;

    printf("%d", sS);
}
