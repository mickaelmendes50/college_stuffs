#include <stdio.h>

int main () {
    int mat[100][100];
    int num, x;
    scanf("%d", &num);
    for (int c = 0; c < num; c++) {
        for (int  i = 0; i < num; i++) {
            scanf("%d", &mat[c][i]);
        }
    }
    x = num;
    // Mostrar a Matriz
    for ( int c = 0; c < num; c++) {
        printf("\n");
        for (int i = 0; i < num; i++) {
            if (c == num-1-i) {
            printf("%d ", mat[c][i]);
            }
        }
    }

    return 0;
}
