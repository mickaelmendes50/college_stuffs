#include <stdio.h>

int main () {
    int mat[10][10];
    int m, n;

    do {
        scanf("%d", &m);
    } while (m <= 0 || m > 10);

    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 10);

    for (int c = 0; c < m; c++) {
        for (int  i = 0; i < n; i++) {
            scanf("%d", &mat[c][i]);
        }
    }

    // Mostrar a Matriz
    for ( int c = 0; c < m; c++) {
        printf("\n");
        for (int i = 0; i < n; i++) {
          //  if (c == num-1-i) {
            printf("%d ", mat[c][i]);
          //  }
        }
    }

    return 0;
}

