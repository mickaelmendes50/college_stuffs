#include <stdio.h>
#include <string.h>

int main () {
    char frase[1000];
    int N, quant, cons=0, vog=0, esp=0;
    scanf("%d", &N);
    do {
        quant = 0;
        scanf("%s", frase);
        quant = strlen(frase);
        for (int i = 0; i < quant; i++) {
            if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' || frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U') {
                vog++;
            } else if (frase[i] == ' ') {
                esp++;
            } else {
                cons++;
            }
        }
        printf("Letras = %d\nConsoantes = %d\nVogais = %d\n", quant-esp, cons, vog);
        N--;
    } while (N > 0);

    return 0;
}

