#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void selection_sort(vector<int> &vet) { 
    int i, j, min, aux;
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
        }
    }
}