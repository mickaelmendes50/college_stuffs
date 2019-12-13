#include <stdio.h>

int main () {
    char operacao;
    int overflow, n1, n2, result;
    //puts("Capacidade maxima");
    scanf("%d", &overflow);
    //puts("Digite dois numeros");
    scanf("%d %c %d", &n1, &operacao, &n2);
    /*puts("Escolha uma operação\n 1 -> soma\n 2 -> multiplicacao");
    scanf("%d", &operacao);*/

    switch (operacao) {
    case '+':
        result = n1 + n2;
        break;
    case 'x':
        result = n1 * n2;
        break;
    default:
        puts("Operacao invalida");
        break;
    }
    if (result > overflow) {
        puts("overflow");
    } else {
        puts("no overflow");
    }
    
    return 0;
}