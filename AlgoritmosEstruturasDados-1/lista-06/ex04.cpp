#include <iostream>
#include <bits/stdc++.h>
#include <vector>

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

int main() {
    int t, i, j, k, l;
    cin >> t;

    vector<int> cores;
    vector<int> cores_ord;
    for (i = 0; i < t; i++) {
        int n, c;
        cin >> n >> c;

        for (j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            cores.push_back(tmp);
        }

        //cout << "adicionou todas as cores" << endl;

        int m;
        cin >> m;
        //cout << "pegou a quantidade de fotos" << endl;
        for (j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            a = a-1;
            b = b-1;
            //cout << "pegou intervalo de anoes" << endl;

            while (a <= b) {
                cores_ord.push_back(cores[a]);
                a++;
            }

            for (int p = 0; p < cores_ord.size(); p++) {
                cout << cores_ord[p] << " ";
            }

            int cont = 0;
            bubble_sort(cores_ord);
            for (k = 0; k < cores_ord.size(); k++) {
                for (l = c; l > 0; l--) {
                    if (cores_ord[k] == l) {
                        cont++;
                    }
                }
            }

            cout << "cont: " << cont;

            if (cont > (cores_ord.size())/2) {
                cout << "bonita " << cores_ord[0] << endl;
            } else {
                cout << "feia" << endl;
            }

            cores_ord.clear();
        }
    }

    return 0;
}