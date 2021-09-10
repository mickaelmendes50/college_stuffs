#include <stdio.h>

int main(int argc, char const *argv[]) {
    float diaria = 160;

    // Entradas
    char nome[25];
    int num_diarias;
    printf("Insira seu nome: ");
    scanf("%s", nome);
    printf("Insira o número de diárias: ");
    scanf("%d", &num_diarias);

    // Calcula a taxa
    float total;
    if (num_diarias > 10) {
        total = diaria*num_diarias + 15.5 * num_diarias;
    } else if (num_diarias == 10) {
        total = diaria*num_diarias + 16 * num_diarias;
    } else {
        total = diaria*num_diarias + 18 * num_diarias;
    }    

    printf("Nome: %s\nTotal da conta: %.2f\n", nome, total);

    return 0;
}
