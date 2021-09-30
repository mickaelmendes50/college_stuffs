#include <stdio.h>

int main(int argc, char const *argv[]) {

    float salario = 10, soma_salarios = 0, media_salarios;
    float salarios[50];
    int filhos[50], soma_filhos = 0, media_filhos, contador = 0, salario_baixo = 0;

    for (int i = 0; salario > 0; i++) {
        printf("Informe o salario: ");
        scanf("%f", &salario);
        salarios[i] = salario;
        soma_salarios += salario;

        if (salario <= 100 && salario != 0) {
            salario_baixo++;
        }
        
        if (salario > 0) {
            printf("informe o número de filhos: ");
            scanf("%d", &filhos[i]);
            soma_filhos += filhos[i];
            contador++;
        }
    }

    media_salarios = soma_salarios/contador;
    media_filhos = soma_filhos/contador;

    printf("Média dos salários = %.2f\n", media_salarios);
    printf("Média de filhos = %d\n", media_filhos);

    // ordenar o vetor do maior pro menor
    for (int i = 0; i < contador-1; i++) {
        for (int j = 0; j < contador-i-1; j++) {
            if (salarios[j] < salarios[j+1]) {
                int tmp = salarios[j];
                salarios[j] = salarios[j+1];
                salarios[j+1] = tmp;
            }
        }
    }

    // imprime o vetor
    //for (int i = 0; i < contador; i++) {
    //    printf(" %.2f ", salarios[i]);
    //}
    printf("Maior salário = %.2f\n", salarios[0]);

    int percentual = (salario_baixo*100)/contador;
    printf("Percentual = %d\n", percentual);

    return 0;
}

/*
inicio
    real salario <- 10, soma_salarios <- 0, media_salarios;
    real salarios[50];
    inteiro filhos[50], soma_filhos <- 0, media_filhos, contador <- 0, salario_baixo <- 0;

    para (inteiro i <- 0; salario > 0; i++) faça {
        escreva("Informe o salario: ");
        leia(salario);
        salarios[i] <- salario;
        soma_salarios <- soma_salarios + salario;

        se (salario <= 100 && salario != 0) então {
            salario_baixo <- salario_baixo + 1;
        }
        
        se (salario > 0) então {
            escreva("informe o número de filhos: ");
            leia(filhos[i]);
            soma_filhos <- soma_filhos + filhos[i];
            contador <- contador + 1;
        }
    }

    media_salarios <- soma_salarios/contador;
    media_filhos <- soma_filhos/contador;

    escreva("Média dos salários =", media_salarios);
    escreva("Média de filhos =", media_filhos);

    // ordena o vetor do maior pro menor
    para (inteiro i <- 0; i < contador-1; i++) faça {
        para (inteiro j <- 0; j < contador-i-1; j++) faça {
            se (salarios[j] < salarios[j+1]) então {
                inteiro tmp <- salarios[j];
                salarios[j] <- salarios[j+1];
                salarios[j+1] <- tmp;
            }
        }
    }

    escreva("Maior salário = ", salarios[0]);

    inteiro percentual <- (salario_baixo*100)/contador;
    escreva("Percentual = ", percentual);
fim
*/