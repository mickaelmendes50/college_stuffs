#include <iostream>
using namespace std;

main () {
    int idade, maior, qtde, contador = 0;
    cout << "Informe a quantidade de idades \n";
    cin >> qtde;
    cout << "Informe a idade \n";
    cin >> idade;
    maior = idade;

    while (contador < qtde-1) {
        cout << "Informe a idade \n";
        cin >> idade;
        contador++;

        if (idade > maior) {
            maior = idade;
        }
    }

    cout << maior;
}
