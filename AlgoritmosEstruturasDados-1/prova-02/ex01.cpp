#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string.h>
 
using namespace std;
 
int main() {
    int t, i, j;
    cin >> t;
 
    vector<int> numeros;
    for (i = 0; i < t; i++) {
        int tmp1 = 0, tmp2;
        do {
            cin >> tmp2;
            if (tmp2 != tmp1) {
                numeros.push_back(tmp2);
                tmp1 = tmp2;
            }
        } while (tmp2 != -1);
        numeros.pop_back();
 
        for (j = 0; j < numeros.size(); j++) {
            cout << numeros[j] << " ";
        }
        numeros.clear();
        cout << endl;
    }
}