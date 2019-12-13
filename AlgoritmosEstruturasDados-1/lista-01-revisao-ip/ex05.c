#include <stdio.h>

int main () {
    char aux[500];
    int num, quant, tetrade[500], i, x, k;
    //puts("Quantos numeros?");
    scanf("%d", &quant);

    for (i = 0; i < quant; i++) {
        //puts("Digite um numero");
        scanf("%d", &num);
        int cont = 0;

        do {
            tetrade[cont] = num%4;
            num = num/4;
            cont++;
        } while (num > 0);

        for (k = 0; k < cont; k++) {
            switch(tetrade[k]) {
                case 0:
                    aux[k] = 'A';
                break;
                case 1:
                    aux[k] = 'C';
                break;
                case 2:
                    aux[k] = 'G';
                break;
                case 3:
                    aux[k] = 'T';
                break;
            } 
        }
        for (x = cont; x > 0; x--) {
            printf("%c", aux[x-1]);
        }
        printf("\n");
    }
    return 0;
}