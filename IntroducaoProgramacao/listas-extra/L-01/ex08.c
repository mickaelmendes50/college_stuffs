#include <stdio.h>

int main(int argc, char const *argv[]) {

    // Entrada dos valores
    int nasc, atual;
    printf("Ano de nascimento: ");
    scanf("%d", &nasc);
    printf("Ano atual: ");
    scanf("%d", &atual);

    // Calcula a idade em anos
    int anos = atual - nasc;
    printf("Idade em anos: %d\n", anos);

    // Calcula a idade em meses
    int meses = anos * 12;
    printf("Idade em meses: %d\n", meses);

    // Calcula a idade em semanas
    int semanas = 52 * anos;
    printf("Idade em semanas: %d\n", semanas);

    return 0;
}
