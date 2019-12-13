#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int n, i;
    cin >> n;

    vector<int> identificadores;
    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        identificadores.push_back(tmp);
    }

    int s, j;
    cin >> s;

    vector<int> evasao;
    for (i = 0; i < s; i++) {
        int tmp;
        cin >> tmp;
        evasao.push_back(tmp);
    }

    for (i = 0; i < evasao.size(); i++) {
        for (j = 0; j < identificadores.size(); j++) {
            if(evasao[i] == identificadores[j]) {
                identificadores.erase(identificadores.begin()+j);
            }
        }
    }

    for (j = 0; j < identificadores.size(); j++) {
        cout << identificadores[j] << " ";
    }

    return 0;
}