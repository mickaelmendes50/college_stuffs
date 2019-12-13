#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    int total_elementos, i;
    cin >> total_elementos;

    vector<double> vetor;
    for (i = 0; i < total_elementos; i++) {
        double tmp;
        cin >> tmp;
        vetor.push_back(tmp);
    }

    double produto_inicial = 1;
    for (i = 0; i < vetor.size(); i++) {
        produto_inicial *= vetor[i];
    }

    int x = 1;
    while(pow(x, vetor.size()) <= produto_inicial) {
        x++;
    }

    cout << x;

    return 0;
}