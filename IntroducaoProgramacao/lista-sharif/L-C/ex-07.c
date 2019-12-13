#include <stdio.h>

main() {
    int matricula;
    double nf, mp, ml, nt, prova, lista;
    scanf("%d", &matricula);
    for (int i = 0; i < 8; i++) {
        scanf("%lf", &prova);
        mp += prova;
    }
    mp = mp/8;
    for (int i = 0; i < 5; i++) {
        scanf("%lf", &lista);
        ml += lista;
    }
    ml = ml/5;
    scanf("%lf", &nt);
    nf = 0.7*mp+0.15*ml+nt;
    printf("%d", matricula);
    printf("%.2lf", nf);
}
