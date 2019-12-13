#include <stdio.h>
#include <string.h>

struct fracoes {
    char fracao[5];
} equivalencia[];


int main () {
    int num, seq, cont;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &seq);
        printf("Caso de teste %d\n", i+1);
        for (int j = 0; j < seq; j++) {
            scanf("%s", equivalencia[j].fracao);
        }
        for (int k = 0; k < seq; k++) {
            cont = 0;
            for (int p = 1; p <= seq; p++) {
                if (strcmp(equivalencia[k].fracao, equivalencia[p].fracao) == 0) {
                    printf("%s equivalente a %s\n", equivalencia[p].fracao, equivalencia[k].fracao);
                    cont++;
                }
            }
            if (cont == 0) {
                puts("Nao ha fracoes equivalentes na sequencia");
            }
        }
    }
    return 0;
}
