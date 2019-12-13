#include <stdio.h>

main () {
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    if (dia <= 31) {

        if (mes <= 12) {
            if (ano <= 2036 && ano >= 1900) {

                if ((ano%4 == 0 && ano%100 != 0) || (ano%100 == 0 && ano%400 ==0)) {

                    switch (mes) {
                        case 2:
                            if (dia > 29) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 4:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 6:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 9:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 11:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        default:
                        printf("%d/%d/%d", dia, mes, ano);
                    }

                } else {

                    switch (mes) {
                        case 2:
                            if (dia > 28) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 4:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 6:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 9:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        case 11:
                            if (dia > 30) {
                                printf("DATA INVALIDA");
                            } else {
                                printf("%d/%d/%d", dia, mes, ano);
                            }
                        break;

                        default:
                        printf("%d/%d/%d", dia, mes, ano);
                    };
                }

            } else {
                printf("DATA FORA DO INTERVALO ESTIPULADO");
            }

        } else {
            printf("DATA INVALIDA");
        }

    } else {
        printf("DATA INVALIDA");
    }
}
