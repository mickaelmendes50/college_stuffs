
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int comparaValor(int num, int adv) {
    if (num == adv) {
        return 0;
    } else if (num > adv) {
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char const *argv[]) {

    // Gera um numero entre 1 e 100
    srand(time(NULL));
    int num = 0;
    while (num == 0) {
        num = rand()%101;
    }

    // Criando processo filho
    pid_t pid = fork();

    if (pid < 0) {
        perror("Erro ao criar processo filho");
    } else if (pid == 0) {
        int adv;

        // Gerando um numero aleatorio enquanto ele
        // nao for igual ao gerado pelo processo pai
        do {
            adv = rand()%100;
        } while (comparaValor(num, adv) != 0);
        printf("O numero é %d\n", adv);
    }
    return 0;
}
