//2019055078_Ω≈√§øµ

#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

int* Count(int *n, int k, int num) {
    int* B = new int[num];
    int* C = new int[k + 1];
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    for (int j = 1; j <= num; j++) {

        C[n[j - 1]] = C[n[j - 1]] + 1;
    }
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }
    return C;
}

int main() {
    int num, range, query;
    int found;
    int* q = new int[200000];
    int* n = new int[100000];
    scanf("%d %d %d", &num, &range, &query);

    for (int i = 0; i < query;i++) {
        cin >> q[i * 2] >> q[(i * 2) + 1];
    }
    for (int i = 0; i < num;i++) {
        cin >> n[i];
    }
    int* C = Count(n, range, num);

    for (int i = 0; i < query;i++) {
        found = C[q[(i * 2) + 1]] - C[q[i * 2] - 1];
        cout << found << endl;
    }

}