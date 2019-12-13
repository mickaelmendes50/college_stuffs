#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int n, i, j;
    cin >> n;

    vector<int> pares;
    vector<int> impares;

    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp%2 == 0) {
            pares.push_back(tmp);
        } else {
            impares.push_back(tmp);
        }
    }

    for (i = 0; i < pares.size(); i++) {
        for(j = 0; j < pares.size(); j++) {
            if (pares[i] < pares[j]) {
                long int tmp = pares[i];
                pares[i] = pares[j];
                pares[j] = tmp;
            }
        }
    }

    for (i = 0; i < impares.size(); i++) {
        for(j = 0; j < impares.size(); j++) {
            if (impares[i] > impares[j]) {
                long int tmp = impares[i];
                impares[i] = impares[j];
                impares[j] = tmp;
            }
        }
    }

    for (j = 0; j < pares.size(); j++) {
        cout << pares[j] << " ";
    }
    cout << endl;
    for (j = 0; j < impares.size(); j++) {
        cout << impares[j] << " ";
    }    

    return 0;
}