#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isPrime(int num) {
    int i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

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

int main() {
    int n, i;
    cin >> n;

    vector<int> vet;
    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vet.push_back(tmp);
    }

    bubble_sort(vet);

    int primo[5000];
    int cont = 0;
    for (i = 0; i < 5000; i++){
        if(isPrime(i)) {
            primo[cont] = i;
            cont++;
        }
    }
    
    for (i = 0; i < vet.size(); i++) {
        cout << primo[vet[i]+1] << " ";
    }

    return 0;
}