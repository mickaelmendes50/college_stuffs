#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int quant_vogal(string palavra) {
    int quant = 0, j;

    for (j = 0; j < palavra.length(); j++) {
        if (toupper(palavra[j]) == 'A' || toupper(palavra[j]) == 'E' ||
            toupper(palavra[j]) == 'I' || toupper(palavra[j]) == 'O' ||
            toupper(palavra[j]) == 'U') {
            quant++;
        }
    }

    return quant;
}

int main() {
    int casos, i;
    cin >> casos;
    getchar();

    string palavra;
    for (i = 0; i < casos; i++) {
        getline(cin, palavra);
        cout << quant_vogal(palavra) << "\n";
    }

    return 0;
}
