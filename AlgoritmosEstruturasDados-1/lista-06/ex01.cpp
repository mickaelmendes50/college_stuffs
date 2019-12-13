#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int n, i;
    cin >> n;

    vector<int> minuto;
    vector<int> critico;
    for (i = 0; i < n; i++) {
        int h, m, c;
        cin >> h >> m >> c;
        
        m += (h*60);
        c += m; 

        minuto.push_back(m);
        critico.push_back(c);
    }
    
    int tempo_atual = minuto[0];
    int mortos = 0;
    for (i = 1; i < minuto.size(); i++) {
        tempo_atual += 30;
        if (tempo_atual > critico[i]) {
            //tempo_atual -= 30;
            mortos++;
        }
    }

    cout << mortos << endl;

    return 0;
}