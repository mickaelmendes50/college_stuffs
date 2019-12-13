#include <stdio.h>

struct loteria {
    int apostas[6];
} sorteio[];

int main () {
    int num, *jogo, numeros[6], acertos = 0, concurso;
    scanf("%d", &num);

    jogo = (int *) malloc(num * sizeof(int));

    for (int i = 0; i < num; i++) {
        scanf("%d", &jogo[i]);
        for (int j = 0; j < 6; j++) {
            scanf("%d", &sorteio[i].apostas[j]);
        }
    }
    scanf("%d", &concurso);
    for (int i = 0; i < 6; i++) {
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 6; j++) {
            if (sorteio[i].apostas[j] == numeros[i]) {
                acertos++;
            }
        }
    }
    if (acertos == 6) {
        printf("SENA");
    } else if (acertos == 5) {
        printf("QUINA");
    } else if (acertos == 4) {
        printf("QUADRA");
    } else {
        printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO");
    }

    return 0;
}
