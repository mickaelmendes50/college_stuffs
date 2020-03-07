/* 
Especificar protótipos de funções para:
a) Criação do Array (com tamanho inicial);
b) Inserção de elemento no Array;
c) Ajuste de tamanho do array;
d) Exibição de todo o conteúdo armazenado no array;
e) Destruição do array.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*vector<int> criaArray() {
    vector<int> vet;
    return vet;
}*/

void insereElemento(vector<int> vet) {
    int tmp; 
    cin >> tmp;
    vet.push_back(tmp);
}

void exibirArray(vector<int> vet) {
    for (int i = 0; i < vet.size(); i++) {
        cout << vet[i];
    }
}

int main() {
    vector<int> vet;
    insereElemento(vet);
    exibirArray(vet);
    vet.clear();

    return 0;
}