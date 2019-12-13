#include <stdio.h> 
#include <string.h>

int main () {
    int m, n, i ,j, k;
    char operacao[1];
    scanf("%d %d", &m, &n);

    int mat_1[m][n], mat_2[m][n], mat_3[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat_1[i][j]);
        }
    }

    scanf("%s", operacao);
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat_2[i][j]);
        }
    }

    if (strcmp(operacao, "+") == 0) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                mat_3[i][j] = mat_1[i][j] + mat_2[i][j];
            }
        }
        for (i = 0; i < m; i++) {
            printf("\n");
            for (j = 0; j < n; j++) {
                printf("%d ", mat_3[i][j]);
            }
        }
    } else if (strcmp(operacao, "x") == 0) {
        if (m == n) {
            for (i = 0; i < m; i++) {
                for (j = 0; j < m; j++) {
                    mat_3[i][j] = 0;
                    for (k = 0; k < n; k++) {
                        mat_3[i][j] = mat_3[i][j] + (mat_1[i][k] * mat_2[k][j]);
                    }
                }
            }
            for (i = 0; i < m; i++) {
                printf("\n");
                for (j = 0; j < n; j++) {
                    printf("%d ", mat_3[i][j]);
                }
            }
        } else {
            printf("ERROR");
        }
    } 

    return 0;
}