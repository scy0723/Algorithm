//2019055078_Ω≈√§øµ
#include<iostream>
#include<stdio.h>
using namespace std;

int N, M;
int arr[1001];
int a, b, cnt = 0;

int Find(int a) {
    if (arr[a] == a)
        return a;
    return arr[a] = Find(arr[a]);
}
void Union(int a, int b) {
    int para = Find(a);
    int parb = Find(b);
    if (para != parb) {
        arr[para] = parb;
    }
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i] == i) 
            cnt++;
    }
    cout << cnt;
}