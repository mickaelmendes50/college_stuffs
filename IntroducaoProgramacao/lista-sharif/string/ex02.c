#include <stdio.h>
#include <string.h>

int main () {
    char led[1000];
    int N, quant, fin;
    scanf("%d", &N);
    do {
        scanf("%s", led);
        quant = strlen(led);
        fin = 0;
        for (int i = 0; i < quant; i++) {
            if (led[i] == '1') {
                fin = fin + 2;
            } else if (led[i] == '2' || led[i] == '3' || led[i] == '5') {
                fin = fin + 5;
            } else if (led[i] == '4') {
                fin = fin + 4;
            } else if (led[i] == '6' || led[i] == '9' || led[i] == '0') {
                fin = fin + 6;
            } else if (led[i] == '8') {
                fin = fin + 7;
            } else if (led[i] == '7') {
                fin = fin + 3;
            }
        }
        printf("%d leds\n", fin);
        N--;
    } while (N > 0);

    return 0;
}
