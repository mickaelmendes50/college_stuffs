#include <stdio.h>

main () {
    int quant;
    float n[4];
    scanf("%d %f %f %f", &quant, &n[0], &n[1], &n[2]);

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 2; i++) {
          if (n[i] > n[i+1]) {
             int temp = n[i];
             n[i] = n[i+1];
             n[i+1] = temp;
          }
        }
    }
    switch (quant) {
    case 1:
    printf("%.2f, %.2f, %.2f", n[0], n[1], n[2]);
    break;

    case 2:
    printf("%.2f, %.2f, %.2f", n[2], n[1], n[0]);
    break;

    case 3:
    printf("%.2f, %.2f, %.2f", n[1], n[2], n[0]);
    break;
    }
}
