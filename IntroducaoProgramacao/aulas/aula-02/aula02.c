#include <stdio.h>

main () {
    int idade, data, ano, mesAtual, mesSeu;

    printf("Qual ano você nasceu? \n");
    scanf("%d", &data);
    printf("Qual mes você nasceu? (numero) \n");
    scanf("%d", &mesSeu);
    printf("Qual o ano atual? \n");
    scanf("%d", &ano);
    printf("Qual o mes atual? (numero) \n");
    scanf("%d", &mesAtual);
    idade = (ano - data);

    if (mesAtual < mesSeu) {
        idade--;
    }

    printf("Você tem %d anos", idade);
}
