#include <stdio.h>

main () {
    int v;
    printf("Escolha um curso: \n 1 - Ciências da Computação \n 2 - Sistemas de Informação \n 3 - Engenharia de Software");
    scanf("%d", &v);

    switch (v) {
        case 1:
        printf("Ciências da Computação");
        break;
        case 2:
        printf("Sistemas de Informação");
        break;
        case 3:
        printf("Engenharia de Software");
        break;
        default:
        printf("Curso inválido");
    }
}
