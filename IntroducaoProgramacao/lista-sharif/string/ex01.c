#include <stdio.h>
#include <string.h>

int main () {
    char n1[50], n2[50], last[50];
    int quant, num1, num2, i, j;
    scanf("%d", &quant);
    do {
        scanf("%s", &n1);
        scanf("%s", &n2);
        num1 = strlen(n1);
        num2 = strlen(n2);
        for (i = 0; i < num1; i++) {
            for (j = 0; j < num2; j+=2) {
                last[j] = n1[i];
                last[j+1] = n2[i];
            }
        }
        for (; i < num1; i++, j++) {
            last[j] = n1[i];
        }
        for (; i < num2; i++, j++) {
            last[j] = n2[i];
        }
        last[j] = '\0';
        puts(last);
        quant--;
    } while (quant > 0);

    return 0;
}
