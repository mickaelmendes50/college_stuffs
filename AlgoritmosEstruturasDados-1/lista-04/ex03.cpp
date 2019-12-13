#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int i, j, k, l; // variaveis do for
    int numCidades;
    cin >> numCidades;

    for (i = 0; i < numCidades; i++) {
        int quantPessoas;
        cin >> quantPessoas;

        int alturaPessoa[quantPessoas];
        for (j = 0; j < quantPessoas; j++) {
            cin >> alturaPessoa[j];
        }

        for (k = 0; k < quantPessoas; k++) {
            for(l = 0; l < quantPessoas; l++) {
                if (alturaPessoa[k] < alturaPessoa[l]) {
                    long int tmp = alturaPessoa[k];
                    alturaPessoa[k] = alturaPessoa[l];
                    alturaPessoa[l] = tmp;
                }
            }
        }

        for (j = 0; j < quantPessoas; j++) {
            cout << alturaPessoa[j] << " ";
        }
        cout << endl;
    }

    return 0;
}