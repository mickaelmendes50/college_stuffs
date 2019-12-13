#include <bits/stdc++.h>
 
using namespace std;
 
int quantCasos, tamMatriz, numCasas, quantPresos;
 
int main() {
    cin >> quantCasos;
    while (quantCasos--) {
        quantPresos = 0;
        cin >> tamMatriz >> numCasas;
        char minimapa[tamMatriz][tamMatriz];
        for (int i = 0; i < tamMatriz; i++) {
            for (int j = 0; j < tamMatriz; j++) {
                scanf(" %c", &minimapa[i][j]);
            }
        }
        for(int i = 0; i < tamMatriz; i++) {
            for(int j = 0; j < tamMatriz; j++) {
                if(minimapa[i][j] == 'P') {
                    for(int l = j - numCasas; l <= j + numCasas; l++) {
                        if(l >= 0 && l < tamMatriz && minimapa[i][l] == 'L') {
                            minimapa[i][l]='M';
                            quantPresos++;    
                            break;
                        }
                    }
                }
            }
        }
            cout << quantPresos << endl;
    }
    return 1;
}