#include <stdio.h>

main () {
    int escolha;

    printf("Escolha sua carne: \n 1 - Frango \n 2 - Porco \n 3 - Peixe \n\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1 :
            printf("Você escolheu Frango");
        break;

        case 2 :
            printf("Você escolheu Porco");
        break;

        case 3 :
            printf("Você escolheu Peixe");
        break;

        default :
            printf("Inválido");
    }
}
