#include <stdio.h>
#define anoBase 1986

int main () {
    int anoAtual, anoProximo = anoBase, cont = 0, bissexto;
    scanf("%d", &anoAtual);

    if (anoBase < anoAtual) {
        while (anoProximo < anoAtual) {
            anoProximo += 76;
            cont++;
        }
    } else {
        while (anoProximo > anoAtual) {
            anoProximo -= 76;
            cont++;
        }
    }

    if (anoProximo == anoAtual) {
        anoProximo += 76;
    } else if (anoProximo < anoAtual) {
        anoProximo += 76;
    }

    if (anoAtual < 1460) {
        anoProximo--;
    }

    printf("%d", anoProximo);
    return 0;
}
