#include <stdio.h>

int main () {
    double mat[2][2], rest[2][2];
    for (int c = 0; c < 2; c++) {
        for (int  i = 0; i < 2; i++) {
            scanf("%lf", &mat[c][i]);
        }
    }

    for (int i = 0;i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          rest[i][j] = rest[i][j] + (mat[i][k] * mat[k][j]);

        }
      }
    }
    for ( int c = 0; c < 2; c++) {
        printf("\n");
        for (int i = 0; i < 2; i++) {
            printf("%.3lf ", rest[c][i]);
        }
    }
    return 0;
}
