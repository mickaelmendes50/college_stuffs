#include <bits/stdc++.h>

using namespace std;

pair <int, int> vet[10002];

int gcd(int n, int d) {
    if (d == 0)
        return n;
    else
        return gcd(d, n % d);
}

int main() {
    int infinity;
    cin >> infinity;

    int d, n, posicao = 1, stop = -1;
    for (d = 1; d > 0; d++) {
        for (n = 0; n <= d; n++) {
            if (gcd(d, n) == 1) {
                vet[posicao++] = {n,d};
            }
            if (posicao == 10001) {
                stop = 0;
                break;
            }
        }
        if (stop == 0) {
            break;
        }
    }
    while (infinity != 0) {
        printf("%d/%d\n", vet[infinity].first, vet[infinity].second);
        cin >> infinity;
    }

    return 0;
}
