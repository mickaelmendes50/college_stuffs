#include <bits/stdc++.h>
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x) {
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
            if (arr[m+1] == x) {
                return m;
            } else if (arr[m-1] == x) {
                return m-1;
            } else 
                break;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}

int main(void) {
	int arr[] = { 2, 3, 4, 10, 40, 40, 55 };
	//int x = 40;
	int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        int result = binarySearch(arr, 0, n - 1, arr[i]);
        if (result != -1) {
            cout << "Elemento " << arr[i] << ", posição: " << result << endl;
            break;
        }
    }

	return 0;
}
