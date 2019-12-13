#include <bits/stdc++.h>

using namespace std;

void binario(int n) {
    // Quando n/2 der zero, n é igual a 1, então já pode parar de chamar a função
    if (n/2 != 0) {
        binario(n/2);
    }
    cout << n%2;
}

int main() {
    int i; // variaveis da estrutura de repeticao
    int t;
    cin >> t;

    for (i = 0; i < t; i++) {
        int n;
        cin >> n;
        binario(n);
        cout << endl;
    }

    return 0;
}