#include <stdio.h>

main () {
    int vezes;
    double pessoas, popular, geral, arquibancada, cadeiras, total;
    scanf("%d", &vezes);

    for (int i = 0; i < vezes; i++) {
        scanf("%lf %lf %lf %lf %lf", &pessoas, &popular, &geral, &arquibancada, &cadeiras);
        popular = (pessoas*(popular/100))*1;
        geral = (pessoas*(geral/100))*5;
        arquibancada = (pessoas*(arquibancada/100))*10;
        cadeiras = (pessoas*(cadeiras/100))*20;
        total = popular + geral + arquibancada + cadeiras;
        printf("A RENDA DO JOGO N. %d E = %.2lf\n", i+1, total);
    }
}
