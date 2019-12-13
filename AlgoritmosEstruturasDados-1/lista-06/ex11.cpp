#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int n, i;
    cin >> n;

    vector<int> inimigos;
    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        inimigos.push_back(tmp);
    }

    char operacao = 'Z';
    while (operacao != 'F') {
        cin >> operacao;
        if (operacao == 'I') {
            int p, e;
            cin >> p >> e;

            for (i = 0; i < inimigos.size(); i++) {
                if (e == inimigos[i]) {
                    inimigos.insert(inimigos.begin()+(i+1), p);
                    cout << "inserido " << p << endl;
                    break;
                }
            }
        } else if (operacao == 'R') {
            int p;
            cin >> p;

            for (i = 0; i < inimigos.size(); i++) {
                if (p == inimigos[i]) {
                    inimigos.erase(inimigos.begin()+i);
                    cout << "removido " << p << endl;
                    break;
                }
            }
        } else if (operacao == 'C') {
            int a, b;
            cin >> a >> b;

            int s1, s2;
            for (i = 0; i < inimigos.size(); i++) {
                if (a == inimigos[i]) {
                    s1 = i;
                    break;
                }
            }
            for (i = 0; i < inimigos.size(); i++) {
                if (b == inimigos[i]) {
                    s2 = i;
                    break;
                }
            }
            if (s1 < s2) {
                cout << "quantidade " << s2-s1-1 << endl;
            } else {
                cout << "quantidade " << s1-s2-1 << endl;
            }
        } else if (operacao == 'M') {
            for (i = 0; i < inimigos.size(); i++) {
                cout << inimigos[i] << " ";
            }
        }
    }

    cout << "fim";

    return 0;
}