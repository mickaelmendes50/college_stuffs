#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> aux;
    for (int i = 0; i < n; i++) {
        int position = 0;
        aux.clear();
        // Pegar os valores de uma linha
        for (int j = 0; j < n; j++) {
            aux.push_back(mat[i][j]);
        }
        // Ordenar os valores da linha
        for(int k = 0; k < aux.size(); k++) {
            if (aux[i] < aux[k]) {
                int tmp = aux[i];
                aux[i] = aux[k];
                aux[k] = tmp;
                position = k+1; // Salvar a posição inicial do maior valor
                if (aux[i] == aux[i+1])
                    position = 0;
            }
        }
        cout << aux[i] << " " << position << endl;
    }

    return 0;
}