#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int> &vet) {
    int i, j, cont = 0;
    for(i = 0; i < vet.size(); i++){
        for(j = 0; j < vet.size()-1; j++){
            if(vet[j] > vet[j+1]){
                int tmp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = tmp;
            }
        }
    }
}