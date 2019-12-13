#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    string n;
    vector<string> nomes;
    //nomes.push_back("vovo");
    do {
        cin >> n;
        nomes.push_back(n);
    } while (n != "FIM");

    nomes.pop_back();
    //cout << nomes.size();
    
    int i, j, cont = 0, x = nomes.size();
    string remover, sentido;
    for (i = 0; i < x; i++) {
        cin >> remover >> sentido;

        if (sentido.compare("horario") == 0) {
            for (j = 0; j < 2; j++) {
                if (nomes[j].compare(remover) == 0) {
                    //cout << endl << "Removido " << nomes[j];
                    nomes.erase(nomes.begin()+j);
                    cont++;
                    //cout << cont;
                }
            }
        } else {
            for (j = nomes.size()-1; j > nomes.size()-3; j--) {
                if (nomes[j].compare(remover) == 0) {
                    //cout << endl << "Removido " << nomes[j];
                    nomes.erase(nomes.begin()+j);
                    cont++;
                    //cout << cont;
                }
            }
        }
    }
    cout << cont;

    return 0;
}