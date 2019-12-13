#include <iostream>
using namespace std;

main () {
    int numero, contador;
    cin >> numero;
    contador = numero-1;

    while (numero%contador != 0) {
        contador--;
    }
    if (contador == 1) {
        cout << "é primo";
    } else {
        cout << "não é primo";
    }
}
