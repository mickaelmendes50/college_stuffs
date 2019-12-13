#include <stdio.h>

main () {
    int num, operacao, a, b, c;
    scanf("%d", &num);

    c = num % 10;
    num = num / 10;

    b = num % 10;
    num = num / 10;

    a = num;

    operacao = (a+(b*3)+(c*5))%7;

    printf("O NOVO NUMERO E = %d%d%d%d", a, b, c, operacao);
}

