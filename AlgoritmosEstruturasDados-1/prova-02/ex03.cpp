#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string.h>
 
using namespace std;
 
int main() {
    vector<int> c;
    vector<int> p;
    int tmp1, tmp2;
    int i, j;
 
    do {
        cin >> tmp1 >> tmp2;
        c.push_back(tmp1);
        p.push_back(tmp2);
    } while (tmp1 != -1 || tmp2 != -1);
    c.pop_back();
    p.pop_back();
 
    for (i = 0; i < c.size(); i++) {
        for (j = 0; j < c.size()-1; j++) {
            if (p[j] > p[j+1]) {
                int tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
 
                tmp = c[j];
                c[j] = c[j+1];
                c[j+1] = tmp;
            }
        }
    }
 
    for (i = 0; i < c.size(); i++) {
        for (j = 0; j < c.size()-1; j++) {
            if (p[j] == p[j+1]) {
                if (c[j] > c[j+1]) {
                    int tmp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = tmp;
 
                    tmp = c[j];
                    c[j] = c[j+1];
                    c[j+1] = tmp;
                }
            }
        }
    }
 
    for (i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
}