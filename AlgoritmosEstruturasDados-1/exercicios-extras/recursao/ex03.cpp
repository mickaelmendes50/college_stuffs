#include <bits/stdc++.h>

using namespace std;

void order(int vet[], int esq, int dir) {
    if (esq >= dir) {
        return;
    }
    int aux = vet[esq];
    vet[esq] = vet[dir];
    vet[dir] = aux;
    order(vet, esq+1, dir-1);
}

int main() {
    int vet[5];
    for (int i = 0; i < 5; i++) {
        cin >> vet[i];
    }
    order(vet, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << vet[i] << endl;
    }
    return 0;
}