#include <stdio.h>

main () {
    int n[4];
    scanf("%d %d %d %d", &n[0], &n[1], &n[2], &n[3]);

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
          if (n[i] > n[i+1]) {
             int temp = n[i];
             n[i] = n[i+1];
             n[i+1] = temp;
          }
        }
    }
    printf("%d", n[0]+n[1]+n[2]);
}
