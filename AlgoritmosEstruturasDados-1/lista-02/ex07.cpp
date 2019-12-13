#include <iostream>
#include <vector>

using namespace std;

int n, m;
int familias[10000];

vector<int> parentes[10000];

void familiaDeTroia(int x) {
    int i;
	for (i = 0; i < (int)parentes[x].size(); i++) {
		
		int v = parentes[x][i];
		
		if (familias[v] == -1) {
			familias[v] = familias[x];
			familiaDeTroia(v);
		}
	}
}

int main() {
	int i;
	cin >> n >> m;

	for (i = 1; i <= n; i++) {
        familias[i] = -1;
    }
	for (i = 1; i <= m; i++) {

		int a, b;
		cin >> a >> b;

		parentes[a].push_back(b);
		parentes[b].push_back(a);
	}
	
	int numero_familia = 0;

	for (int i = 1; i <= n; i++) {

		if (familias[i] == -1) {
			numero_familia++;
			familias[i] = numero_familia;
			familiaDeTroia(i);
		}
	}
	
	cout << numero_familia << "\n";
	return 0;
}