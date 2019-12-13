#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isPrimo(int num) {
    int divisor = num-1;
    while (num%divisor != 0) {
        divisor--;
    }
    if (divisor == 1)
        return true;
    return false;
}

int main() {
    int num_casos;
    cin >> num_casos;

    vector<int> entradas;
    for (int i = 0; i < num_casos; i++) {
        int tmp;
        cin >> tmp;
        entradas.push_back(tmp);
    }

    // Ordenação dos dados de entrada
    for (int i = 0; i < entradas.size(); i++) {
        for(int j = 0; j < entradas.size(); j++) {
            if (entradas[i] < entradas[j]) {
                int tmp = entradas[i];
                entradas[i] = entradas[j];
                entradas[j] = tmp;
            }
        }
    }

    int num = 2;
    vector<int> saidas;
    for (int i = 0; i < entradas[num_casos-1]; i++) {
        while (!(isPrimo(num))) {
            num++;
        }
        //cout << num << " é primo" << endl;
        saidas.push_back(num);
        num++;
    }

    int soma = 0;
    for (int i = 0; i < entradas.size(); i++) {
        cout << saidas[entradas[i]-1] << " ";
        soma += saidas[entradas[i]-1];
    }
    cout << endl << soma;

    return 0;
}