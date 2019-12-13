#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int i, j; // Variaveis das estruturas de repetição
    long int n, k;
    cin >> n >> k;

    if (1 <= n && n <= 1000) {
        if (1 <= k && k <= n) {

            vector<long int> notas;
            for (i = 0; i < n; i++) {
                long int tmp;
                cin >> tmp;
                notas.push_back(tmp);
            }

            // Ordenação das notas
            for (i = 0; i < notas.size(); i++) {
                for(j = 0; j < notas.size(); j++) {
                    if (notas[i] > notas[j]) {
                        long int tmp = notas[i];
                        notas[i] = notas[j];
                        notas[j] = tmp;
                    }
                }
            }

            // Enquanto as ultimas notas forem iguais, altere a quantidade de aprovados
            while (notas[k-1] == notas[k]) {
                k++;
            }

            cout << k;
        }
    }

    return 0;
}