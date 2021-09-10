//2019055078_Ω≈√§øµ

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

int main() {
    int n, m;
    int num = 0;
    cin >> n >> m;
    
    int* arr1 = new int[n];
    int* arr2 = new int[m];

    for (int i = 0; i < n;i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m;i++) {
        cin >> arr2[i];
    }

    for (int i = 0;i < n;i++) {
        int temp = arr1[i];
        for (int j = 0; j < m;j++) {
            if (temp == arr2[j]) {
                num++;
            }
        }
    }
    cout << num;
}