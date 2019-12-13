#include <iostream>
#include <bits/stdc++.h>
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
        }
        vet[i+1] = tmp;
        j++;
    }
    return cont;
}