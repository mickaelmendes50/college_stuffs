#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int soma(int array[], int n) {
    if (n == 0) {
        return 0;
    }
    return array[n-1] + soma(array, n-1);
}

int main() {
    int array[5];
    for (int i = 0; i < 5; i++) {
        cin >> array[i];
    }
    cout << soma(array, 5) << endl;

    return 0;
}