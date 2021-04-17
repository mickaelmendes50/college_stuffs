// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x) {
            if (arr[mid+1] == x) {
                return mid;
            } else if (arr[mid-1] == x) {
                return mid-1;
            }
        }

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int main(void) {
	int arr[] = { 2, 3, 4, 4, 10, 40, 40, 55 };
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
