#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void insertionSort(float arr[], int n)
{
    int i, j;
    float key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    float vet[n] = {2.3,1.1,1.555,0.1,0.9};

    insertionSort(vet, n);
    printArray(vet, n);

    return 0;
}
