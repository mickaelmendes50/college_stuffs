#include <stdio.h>

int main () {
    int mat[2][2];
    float determinante;
    for (int c = 0; c < 2; c++) {
        for (int  i = 0; i < 2; i++) {
            scanf("%d", &mat[c][i]);
        }
    }
    // Mostrar a Matriz
    /*for ( int c = 0; c < 2; c++) {
        printf("\n");
        for (int i = 0; i < 2; i++) {
            printf("%d ", mat[c][i]);
        }
    }*/
    determinante = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    printf("%.2f", determinante);

    return 0;
}
