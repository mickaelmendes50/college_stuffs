#include <stdio.h>

main () {
    int n[4];
    char a1, a2, a3;
    scanf("%d %d %d\n%c %c %c", &n[1], &n[2], &n[3], &a1, &a2, &a3);

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
          if (n[i] > n[i+1]) {
             int temp = n[i];
             n[i] = n[i+1];
             n[i+1] = temp;
          }
        }
    }

    if (a1 == 'A') {
       printf("%d ", n[0]);
    } else if (a1 == 'B') {
        printf("%d ", n[1]);
    } else {
        printf("%d ", n[2]);
    }

    if (a2 == 'A') {
       printf("%d ", n[0]);
    } else if (a2 == 'B') {
        printf("%d ", n[1]);
    } else {
        printf("%d ", n[2]);
    }

    if (a3 == 'A') {
       printf("%d ", n[0]);
    } else if (a3 == 'B') {
        printf("%d ", n[1]);
    } else {
        printf("%d ", n[2]);
    }
}
