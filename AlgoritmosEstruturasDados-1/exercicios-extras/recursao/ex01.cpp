#include <bits/stdc++.h>

using namespace std;

int potencia(int x, int n) {
    if (n == 0) {
        x = 1;
        return x;
    }
    return x * potencia(x, n-1);
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << potencia(x, n) << endl;

    return 0;
}