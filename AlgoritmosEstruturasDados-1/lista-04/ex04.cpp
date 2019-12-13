#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

typedef struct {
    int nota;
    char nome[30];
} Aluno;

int main() {
    int n, i, j;
    cin >> n;

    Aluno aluno[n];

    for (i = 0; i < n; i++) {
        cin >> aluno[i].nome >> aluno[i].nota;
    }

    for (i = 0; i < n; i++) {
        int tmp = aluno[i].nota;
        char tmpStr[30];
        strcpy(tmpStr, aluno[i].nome);
        int cont = i;
        for (j = i+1; j < n; j++) {
            if (tmp <= aluno[j].nota) {
                if (tmp == aluno[j].nota) {
                    if ((strcmp(tmpStr, aluno[j].nome)) > 0) {
                        strcpy(tmpStr, aluno[j].nome);
                        cont = j;
                    }
                } else {
                    tmp = aluno[j].nota;
                    strcpy(tmpStr, aluno[j].nome);
                    cont = j;
                }
            }
        }
        if (cont != j) {
            aluno[cont].nota = aluno[i].nota;
            strcpy(aluno[cont].nome, aluno[i].nome);
            aluno[i].nota = tmp;
            strcpy(aluno[i].nome, tmpStr);
        }
    }

    for (i = 0; i < n; i++) {
        if (i == n-1) {
            cout << aluno[i].nome << " " << aluno[i].nota << " #reprovado(a)";
        } else {
            cout << aluno[i].nome << " " << aluno[i].nota << endl;
        }  
    }
    
    return 0;
}