#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    int t, i, j;
    cin >> t;
    for (i = 0; i < t; i++) {
        string r, d;
        vector<string> rua, direcao, inverso;

        do {
            cin >> d >> r;
            rua.push_back(r);
            direcao.push_back(d);
        } while (r != "ESCOLA");

        rua.pop_back();
        rua.insert(rua.begin(), "CASA");

        for (j = 0; j < direcao.size(); j++) {
            if (direcao[j].compare("DIREITA") == 0) {
                inverso.push_back("ESQUERDA");
            } else {
                inverso.push_back("DIREITA");
            }
            //cout << inverso[j] << endl;
        }

        for (j = rua.size()-1; j >= 0; j--) {
            if (rua[j].compare("CASA") == 0) {
                cout << "Vire a " << inverso[j] << " na sua " << rua[j] << "." << endl;
            } else {
                cout << "Vire a " << inverso[j] << " na rua " << rua[j] << "." << endl;
            }
        }
    }

    return 0;
}