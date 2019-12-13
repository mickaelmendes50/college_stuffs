#include <iostream>

using namespace std;

int nota_2, nota_5, nota_10, nota_20, nota_50, nota_100;

int caixaATM(int a, int b, int c, int d, int e, int f, int valor) {
    int combinacao = 0, total = (a*100) + (b*50) + (c*20) + (d*10) + (e*5) + (f*2);

    if (total == valor) {
        combinacao++;
    }
    f++;

    if (f == nota_2 + 1) {
        f = 0;
        e++;
    }

    if (e == nota_5 + 1) {
        e = 0;
        d++;
    }

    if (d == nota_10 + 1) {
        d = 0;
        c++;
    }

    if (c == nota_20 + 1) {
        c = 0;
        b++;
    }

    if (b == nota_50 + 1) {
        b = 0;
        a++;
    }

    if (a == nota_100 + 1) {
        return combinacao;
    }
    return combinacao + caixaATM(a, b, c, d, e, f, valor);
}

int main() {
    int valor;
    cin >> valor;
    cin >> nota_2 >> nota_5 >> nota_10 >> nota_20 >> nota_50 >> nota_100;

    cout << caixaATM(0, 0, 0, 0, 0, 0, valor) << endl;

    return 0;
}