#include <stdio.h>

main () {
    int dia, mes, ano, data;
    scanf("%d", &data);

    ano = data%10000;
    data = data/10000;
    mes = data%100;
    data = data/100;
    dia = data;

    if (dia <= 31) {
        if (mes <= 12) {
            switch (mes) {
            case 1:
                printf("%d de janeiro de %d", dia, ano);
            break;

            case 2:
                if (dia > 28) {
                    printf("DATA INVALIDA");
                } else {
                    printf("%d de fevereiro de %d", dia, ano);
                }
            break;

            case 3:
                printf("%d de marco de %d", dia, ano);
            break;

            case 4:
                if (dia > 30) {
                    printf("DATA INVALIDA");
                } else {
                    printf("%d de abril de %d", dia, ano);
                }
            break;

            case 5:
                printf("%d de maio de %d", dia, ano);
            break;

            case 6:
                if (dia > 30) {
                    printf("DATA INVALIDA");
                } else {
                    printf("%d de junho de %d", dia, ano);
                }
            break;

            case 7:
                printf("%d de julho de %d", dia, ano);
            break;

            case 8:
                printf("%d de agosto de %d", dia, ano);
            break;

            case 9:
                if (dia > 30) {
                    printf("DATA INVALIDA");
                } else {
                    printf("%d de setembro de %d", dia, ano);
                }
            break;

            case 10:
                printf("%d de outubro de %d", dia, ano);
            break;

            case 11:
                if (dia > 30) {
                    printf("DATA INVALIDA");
                } else {
                    printf("%d de novembro de %d", dia, ano);
                }
            break;

            case 12:
                printf("%d de dezembro de %d", dia, ano);
            break;

            default:
            printf("%d/%d/%d", dia, mes, ano);
            }
        } else {
            printf("DATA INVALIDA");
        }
    } else {
            printf("DATA INVALIDA");
    }
}
