#include <stdio.h>
#include <string.h>

struct turma {
    int matricula;
    int dia;
    int mes;
    int ano;
    int dataNas;
    char nome[200];
}dadosAlunos[];

struct datas {
    int dataNasc;
}dataNascimento[];

int ComparaDataNasc (int num, struct turma *dadosAlunos, struct datas *dataNascimento) {
    if (dadosAlunos[num].dataNas >= dataNascimento[num-1].dataNasc) {
        return 1;
    } else {
        return 0;
    }
}

int OrdenaAlunos (int alunos, int *vet) {
    int c = 0;
    for (int k = 1; k <= alunos; k++) {
        if (ComparaDataNasc(k, dadosAlunos, dataNascimento) == 1) {
            vet[c] = k;
            c++;
        }
    }
    for (int j = 0; j < alunos; j++) {
        printf("Matric.: %d ", dadosAlunos[vet[j]].matricula);
        //printf("Nome: %s ", dadosAlunos[vet[j]].nome);
        printf("Data Nas.: %d/", dadosAlunos[vet[j]].dia);
        printf("%d/", dadosAlunos[vet[j]].mes);
        printf("%d\n", dadosAlunos[vet[j]].ano);
    }
}

int main () {
    int nAlunos, vet[50];
    scanf("%d", &nAlunos);

    for (int i = 0; i < nAlunos; i++) {
        scanf("%d", &dadosAlunos[i].matricula);
        scanf("%d", &dadosAlunos[i].dia);
        scanf("%d", &dadosAlunos[i].mes);
        scanf("%d", &dadosAlunos[i].ano);
        //scanf("%[^\n]s", dadosAlunos[i].nome);

        dataNascimento[i].dataNasc = (dadosAlunos[i].dia * 1000000) + (dadosAlunos[i].mes * 10000) + (dadosAlunos[i].ano);
        dadosAlunos[i].dataNas = (dadosAlunos[i].dia * 1000000) + (dadosAlunos[i].mes * 10000) + (dadosAlunos[i].ano);
    }
    OrdenaAlunos(nAlunos, vet);
    return 0;
}
