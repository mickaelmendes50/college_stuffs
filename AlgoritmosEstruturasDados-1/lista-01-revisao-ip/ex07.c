#include <stdio.h>
#define DISTANCIA_PEDRAS 100

int main () {
    int i, pedras, sapos, posicaoInicial, distanciaFixa;
    scanf("%d %d", &pedras, &sapos);

    if (pedras >= 1 && pedras <= 50 &&
        sapos >= 1 && sapos <= 100) {
        for (i = 0; i < sapos; i++) {
            scanf("%d %d", &posicaoInicial, &distanciaFixa);
        }
    }

    return 0;
}