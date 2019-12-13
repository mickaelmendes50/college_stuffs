#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    char operacao = 'Z';
    int j, i;

    vector<string> nome;
    vector<string> tel;
    vector<int> v;

    nome.push_back("Hermanoteu");
    tel.push_back("4523-2248");
    v.push_back(300);

    nome.push_back("Ooloneia");
    tel.push_back("4523-4887");
    v.push_back(299);

    while (operacao != 'F') {
        cin >> operacao;
        if (operacao == 'I') {
            string nomeTmp, telTmp;
            int vTmp;
            cin >> nomeTmp >> telTmp >> vTmp;
            
            nome.push_back(nomeTmp);
            tel.push_back(telTmp);
            v.push_back(vTmp);

        } else if (operacao == 'R') {
            string nomeTmp;
            cin >> nomeTmp;

            for (i = 0; i < nome.size(); i++) {
                if (nomeTmp.compare(nome[i]) == 0) {
                    nome.erase(nome.begin()+i);
                    tel.erase(tel.begin()+i);
                    v.erase(v.begin()+i);
                }
            }
        } else if (operacao == 'L') {
            string nomeTmp;
            cin >> nomeTmp;

            for (i = 0; i < nome.size(); i++) {
                if (nomeTmp.compare(nome[i]) == 0) {
                    v[i]++;
                }
            }
        }
    }

    for (i = 0; i < nome.size(); i++) {
        for (j = 0; j < nome.size()-1; j++) {
            if (v[j] < v[j+1]) {
                string nomeTmp, telTmp;
                int vTmp;

                nomeTmp = nome[j];
                nome[j] = nome[j+1];
                nome[j+1] = nomeTmp;

                telTmp = tel[j];
                tel[j] = tel[j+1];
                tel[j+1] = telTmp;

                vTmp = v[j];
                v[j] = v[j+1];
                v[j+1] = vTmp;
            }
        }
    }

    for (i = 0; i < nome.size(); i++) {
        cout << nome[i] << " - " << tel[i] << " " << v[i] << endl;
    }

    return 0;
}