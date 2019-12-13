#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j;
    cin >> n;

    int vetor[n];
    for (i = 1; i <= n; i++) {
        cin >> vetor[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (vetor[i] < vetor[j]) {
                long int tmp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = tmp;
            }
        }
    }

    int l, k;
    cin >> l >> k;
    cout << vetor[l]+vetor[k];

    return 0;
}