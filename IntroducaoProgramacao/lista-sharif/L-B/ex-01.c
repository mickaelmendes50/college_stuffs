#include <stdio.h>

main () {
    float N1, N2, N3, media;
    scanf("%f %f %f", &N1, &N2, &N3);

    media = (N1 + N2 + N3)/3;
    printf("MEDIA = %.2f \n", truncf(media*100.0)/100.0);

    if (media >= 6) {
        printf("APROVADO");
    }
    else {
        printf("REPROVADO");
    }
}
