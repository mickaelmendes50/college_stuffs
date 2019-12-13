#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>

using namespace std;

int insertion_sort(vector<int> &vet) {
    int cont = 0, i, j = 1;
    while(j < vet.size()) {
        int tmp = vet[j];
        i = j - 1;

        while ((i >= 0) && (vet[i] > tmp)) {
            vet[i+1] = vet[i];
            i--;

            cont++;
        }
        vet[i+1] = tmp;
        j++;

        cont++;
    }
    return cont;
}

int selection_sort(vector<int> &vet) { 
    int i, j, min, aux, cont = 0;
    for (i = 0; i < vet.size()-1; i++) {
        min = i;
        for (j = (i+1); j < vet.size(); j++) {
            if(vet[j] < vet[min]) 
                min = j;
        }
        if (vet[i] != vet[min]) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;

            cont++;
        }
    }
    return cont;
}

int main() {
    int n, i;
    cin >> n;

    vector<int> vetI;
    vector<int> vetS;

    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vetI.push_back(tmp);
        vetS.push_back(tmp);
    }

    //cout << insertion_sort(vetI) << endl;
    //cout << selection_sort(vetS) << endl;

    cout << insertion_sort(vetI) - selection_sort(vetS);

    return 0;
}