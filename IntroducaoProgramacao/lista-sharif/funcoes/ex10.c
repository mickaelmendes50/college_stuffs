#include <stdio.h>

int converteEmNotasMoedas (int r) {
    int n100 = 0, n50 = 0, n10 = 0, n1 = 0;
    n100 = r/100;
    r = r-(n100*100);
    printf("NOTAS DE 100: %d\n", n100);
    n50 = r/50;
    r = r-(n50*50);
    printf("NOTAS DE 50: %d\n", n50);
    n10 = r/10;
    r = r-(n10*10);
    printf("NOTAS DE 10: %d\n", n10);
    n1 = r;
    printf("NOTAS DE 1: %d\n", n1);
}

int main() {
    int reais;
    scanf("%d", &reais);
    converteEmNotasMoedas(reais);
    return 0;
}
