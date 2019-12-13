#include <stdio.h>

main () {
    int num, a, b, c, d;
    char uni = ' ', dez = ' ', cent = ' ', uniM = ' ';
    scanf("%d", &num);

    if ((num > 999) && (num <= 9999)) {
        a = num%10;
        num = num/10;
        if (a != 1) uni = 's';
        b = num%10;
        num = num/10;
        if (b != 1) dez = 's';
        c = num%10;
        num = num/10;
        if (c != 1) cent = 's';
        d = num%10;
        num = num/10;
        if (d != 1) uniM = 's';
        printf("(quarta ordem) %d = %d unidade%c de milhar + %d centena%c + %d dezena%c + %d unidade%c = %d000 + %d00 + %d0 + %d", num, d, uniM, c, cent, b, dez, a, uni, d, c, b, a);

    } else if ((num > 99) && (num <= 999)) {
        a = num%10;
        num = num/10;
        if (a != 1) uni = 's';
        b = num%10;
        num = num/10;
        if (b != 1) dez = 's';
        c = num%10;
        num = num/10;
        if (c != 1) cent = 's';
        printf("(terceira ordem) %d = %d centena%c + %d dezena%c + %d unidade%c = %d00 + %d0 + %d", num, c, cent, b, dez, a, uni, c , b , a);

    } else if ((num > 9) && (num <= 99)) {
        a = num%10;
        num = num/10;
        if (a != 1) uni = 's';
        b = num%10;
        num = num/10;
        if (b != 1) dez = 's';
        printf("(segunda ordem) %d = %d dezena%c + %d unidade%c = %d0 + %d", num, b, dez, a, uni, b, a);

    } else if ((num > 0) && (num <= 9)) {
        if (num != 1) uni = 's';
        printf("(primeira ordem) %d = %d unidade%c = %d", num, num, uni, num);

    } else {
        printf("Numero invalido!");
    }
}
