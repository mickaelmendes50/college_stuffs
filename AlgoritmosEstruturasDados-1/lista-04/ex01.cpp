#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int bubble_sort(vector<int> &vet) {
    int i, j, cont = 0;
    for(i = 0; i < vet.size(); i++){
        for(j = 0; j < vet.size()-1; j++){
            if(vet[j] > vet[j+1]){
                int tmp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = tmp;

                cont++;
            }
        }
    }
    return cont;
} 

int main() {
    int n, i, j;
    cin >> n;

    for (i = 0; i < n; i++) {
        int l;
        cin >> l;

        vector<int> vagoes;
        for (j = 0; j < l; j++) {
            int tmp;
            cin >> tmp; 
            vagoes.push_back(tmp);
        }

        cout << bubble_sort(vagoes) << endl;
    }

    return 0;
}