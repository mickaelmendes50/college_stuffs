#include <stdio.h>

int main () {
    int vet[100000], par[100000], impar[100000], n, aux, p = 0, i = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
    for (int k = 0; k < n; k++) {
        if (vet[k]%2 == 0) {
            par[p] = vet[k];
            p++;
        }
    }
    for (int k = 0; k < n; k++) {
        if (vet[k]%2 != 0) {
            impar[i] = vet[k];
            i++;
        }
    }

    for (int c = 0; c < p; c++) {
        for (int j = 0; j < p-1; j++) {
            if (par[c] < par[j]) {
                aux = par[c];
                par[c] = par[j];
                par[j] = aux;
            }
        }
    }
    for (int c = 0; c < i; c++) {
        for (int j = 0; j < i-1; j++) {
            if (impar[c] > impar[j]) {
                aux = impar[c];
                impar[c] = impar[j];
                impar[j] = aux;
            }
        }
    }

    for (int x = 0; x < p; x++) {
        printf("%d\n", par[x]);
    }
    for (int x = 0; x < i; x++) {
        printf("%d\n", impar[x]);
    }
    return 0;
}
