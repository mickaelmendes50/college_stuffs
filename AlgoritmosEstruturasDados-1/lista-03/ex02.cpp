#include <iostream>
#include <vector>

using namespace std;

int main() {
    int quant_lanchonetes, i;
    cin >> quant_lanchonetes;

    vector<int> precos;
    for (i = 0; i < quant_lanchonetes; i++) {
        int tmp;
        cin >> tmp;
        precos.push_back(tmp);
    }

    int quant_dias;
    cin >> quant_dias;

    for (i = 0; i < quant_dias; i++) {
        int moedas, cont = 0, j;
        cin >> moedas;

        for (j = 0; j < precos.size(); j++) {
            if (moedas >= precos[j]) {
                cont++;
            }
        }
        cout << cont;
        for (j = 0; j < precos.size(); j++) {
            if (moedas >= precos[j]) {
                cout << " " << j+1;
            }
        }
        cout << "\n";
    }

    return 0;
}