#include <stdio.h>

int main () {
    int mat[100][100];
    int num;
    scanf("%d", &num);
    for (int c = 0; c < num; c++) {
        for (int  i = 0; i < num; i++) {
            scanf("%d", &mat[c][i]);
        }
    }
    // Mostrar a Matriz
    for ( int c = 0; c < num; c++) {
        printf("\n");
        for (int i = 0; i < num; i++) {
            if (i == c) {
            printf("%d ", mat[c][i]);
            }
        }
    }

    return 0;
}
