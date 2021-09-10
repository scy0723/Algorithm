// 2019055078_Ω≈√§øµ
#include<stdio.h>
#include<iostream>

int N;
int arr[30000];
using namespace std;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = N - 1; i >= 0; i--) {
        cout << arr[i] << "\n";
    }
}