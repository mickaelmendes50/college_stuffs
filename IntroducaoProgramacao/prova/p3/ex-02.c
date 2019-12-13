#include <stdio.h>

int maior (int *v, int num, int cont) {
    int x =0;
    for (int c = 0; c < cont; c++) {
        if (v[c] >= num) {
            x++;
        }
    }
    return x;
}

int main () {
    int v[1000], n, k;

    do {
    scanf("%d", &n);

    } while (1 >= n || n >= 1000);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &k);
    printf("%d", maior(v, k, n));

    return 0;
}
