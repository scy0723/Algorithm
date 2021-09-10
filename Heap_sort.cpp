//2019055078_½ÅÃ¤¿µ

#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

void SWAP(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heapify(int arr[], int n, int i) {
    int biggest = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    if (L < n && arr[L] > arr[biggest])
        biggest = L;

    if (R < n && arr[R] > arr[biggest])
        biggest = R;

    if (biggest != i) {
        SWAP(&arr[i], &arr[biggest]);
        Heapify(arr, n, biggest);
    }
}

void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        SWAP(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}


void Print(int arr[], int n, int num) {
    for (int i = num - 1; i >= num - n; i--)
        cout << arr[i] << " ";
    cout << endl;
    for (int i = num - n - 1; i >= 0;i--) {
        cout << arr[i] << " ";
    }
}

int main() {
    int num, k;
    cin >> num >> k;
    int* arr = new int[100001];
    for (int i = 0; i < num;i++) {
        cin >> arr[i];
    }
    HeapSort(arr, num);
    Print(arr, k, num);
    return 0;
}