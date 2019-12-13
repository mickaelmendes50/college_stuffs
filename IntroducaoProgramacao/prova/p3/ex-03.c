#include <stdio.h>

int SeparaDigitos (int numero) {
    int a, b, c;
        c = numero%10;
        numero = numero/10;

        b = numero%10;
        numero = numero/10;

        a = numero;
        numero = (c*100)+(b*10)+(a);
        return numero;
}

int inverte (int valor) {
    int z = 0;
    z = SeparaDigitos(valor);
    return z;
}

main () {
    int t1, t2, vezes;
    scanf("%d", &vezes);
    for (int i = 0; i < vezes; i++) {
        scanf("%d %d", &t1, &t2);
        if (inverte(t1) > inverte(t2)) {
            printf("%d\n", inverte(t1));
        } else {
            printf("%d\n", inverte(t2));
        }
    }
}
