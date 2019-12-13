#include <iostream>
using namespace std;

main () {
    int numero, fatorial, resultado=1;

        cin >> numero;
        for (fatorial = 1; fatorial <= numero; fatorial++) {
            resultado = resultado * fatorial;
        }
        
        cout << resultado;
}
