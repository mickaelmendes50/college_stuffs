#include <stdio.h>

main () {
    float n[4];
    scanf("%f %f %f %f", &n[0], &n[1], &n[2], &n[3]);

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
          if (n[i] > n[i+1]) {
             int temp = n[i];
             n[i] = n[i+1];
             n[i+1] = temp;
          }
        }
    }
    printf("%.2f, %.2f, %.2f, %.2f", n[0], n[1], n[2], n[3]);
}
