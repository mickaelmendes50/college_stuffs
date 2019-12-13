#include <stdio.h>

main () {
    double massa, aceleracao, tempo, velocidade, espaco, trabalho;
    scanf("%lf", &massa);
    scanf("%lf", &aceleracao);
    scanf("%lf", &tempo);

    massa = massa*1000;
    velocidade = (aceleracao*tempo)*3.6;
    printf("VELOCIDADE = %.2lf \n", truncf(velocidade*100.0)/100.0);
    espaco = (aceleracao*(tempo*tempo))/2;
    printf("ESPACO PERCORRIDO = %.2lf \n", truncf(espaco*100.0)/100.0);
    velocidade = velocidade/3.6;
    trabalho = (massa*(velocidade*velocidade))/2;
    printf("TRABALHO REALIZADO = %.2lf \n", truncf(trabalho*100.0)/100.0);
}
