#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int quant_testes;
    cin >> quant_testes;

    int a, b, c, k, i;
    for (i = 0; i < quant_testes; i++) {
        cin >> a >> b >> c >> k;

        float equacao = 0, x = 0;
        while (equacao < k) {
            equacao = (a*pow(x, 2)) + (b*x) + c;
            x++;
        }
        if (x == 0) {
            cout << x << "\n";
        } else {
            cout << x-1 << "\n";
        }
    }

    return 0;
}
