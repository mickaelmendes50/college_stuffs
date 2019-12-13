#include <stdio.h>

int main() {
	int N, mat[100][100], diagPrincipal, diagSecundaria, linha[100], coluna[100], testeLinha = 1, testeColuna = 1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

    for ( int c = 0; c < N; c++) {
        for (int i = 0; i < N; i++) {
            if (i == c) {
                diagPrincipal = diagPrincipal + mat[c][i];
            }
            if (c == N-1-i) {
                diagSecundaria = diagSecundaria + mat[c][i];
            }
        }
    }

	for (int i = 0; i < N; i++) {
		linha[i] = 0;
		for (int j = 0; j < N; j++) {
			linha[i] += mat[i][j];
		}
	}

	for (int j = 0; j < N; j++) {
		coluna[j] = 0;
		for (int i = 0; i < N; i++) {
			coluna[j] += mat[i][j];
		}
	}

	for (int i = 1; i <  N; i++) {
		if (linha[i] != linha[i-1]) {
			testeLinha = 0;
			break;
		} else if (coluna[i] != coluna[i-1]) {
			testeColuna = 0;
			break;
		}
	}

	if (testeLinha && testeColuna && diagPrincipal == diagSecundaria && diagPrincipal == linha[0]) {
		printf("Quadrado Mágico");
	} else {
		printf("Não é quadrado Mágico");
	}

	return 0;
}
