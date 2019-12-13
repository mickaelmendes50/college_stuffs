#include <stdio.h>

int value(int k, int *v, int z) {
    for (int j = 0; j < k; j++) {
        if (v[j] == z) {
            return 1;
        }
    }
}

int main() {
    int v[100000], n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    scanf("%d", &m);
    for (int c = 0; c < m; c++) {
        scanf("%d", &x);
        if (value(n, v, x) == 1) {
            printf("ACHEI\n");
        } else {
            printf("NAO ACHEI\n");
        }
    }
    return 0;
}
