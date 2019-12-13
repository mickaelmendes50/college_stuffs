#include <bits/stdc++.h>
 
using namespace std;
 
int quantCasos, tamMatriz, numCasas, quantPresos, achou;
 
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
                if(minimapa[i][j] == 'D') {
                    for(int l = j - numCasas; l <= j + numCasas; l++) {
                        achou = 0;
                        if(l >= 0 && l < tamMatriz && minimapa[i][l] == 'L') {
                            minimapa[i][l]='M';
                            achou++;
                            quantPresos++;    
                            break;
                        }
                    }
                    if (achou == 0) {
                        for(int l = i - numCasas; l <= i + numCasas; l++) {
                            if(l >= 0 && l < tamMatriz && minimapa[l][j] == 'L') {
                                minimapa[i][j]='M';
                                achou++;
                                quantPresos++;    
                                break;
                            }
                        }                       
                    }
                }
            }
        }
        cout << quantPresos << endl;
    }
    return 0;
}
