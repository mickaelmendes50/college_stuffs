#include <stdio.h>

int familiaDeTroia(int x, int *familias, int vet[100][100]) {
    int i;
    for (i = 0; i < vet[x][x].size(); i++) {
		
		int v = lista[x][i];
		
		if (parentes[v] == -1) {
			parentes[v] = parentes[x];
			familiaDeTroia(v);
		}
	}

    return 0;
}

int main() {
    int m, n, i, j;
    scanf("%d %d", &n, &m);

    int familias[10000];
    int vet[100][100];
    int num_familia = 0;

    for (i = 0; i < n; i++) {
        familias[i] = -1;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &vet[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        if (familias[i] == -1) {
            num_familia++;
            familias[i] = num_familia;
            familiaDeTroia(i, familias, vet);
        }
    }

    return 0;
}