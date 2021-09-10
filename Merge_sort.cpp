//2019055078_½ÅÃ¤¿µ

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector <int> v;
int arr[100001];

void Merge(int start, int mid, int end) {
    int s = start;
    int m = mid + 1;
    int i = start;
    while (s <= mid && m <= end) {
        if (v[s] <= v[m]) {
            arr[i] = v[s];
            s++;
        }
        else {
            arr[i] = v[m];
            m++;
        }
        i++;
    }
    if (s > mid) {
        for (int j = m; j <= end; j++) {
            arr[i] = v[j];
            i++;
        }
    }
    else {
        for (int j = s; j <= mid; j++) {
            arr[i] = v[j];
            i++;
        }
    }
    for (int j = start; j <= end; j++) {
        v[j] = arr[j];
    }
}

void Divide(int start, int end) {
    int mid = (start + end) / 2;
    if (start < end) {
        Divide(start, mid);
        Divide(mid + 1, end);
        Merge(start, mid, end);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    Divide(0, N - 1);
    for (int i = N - 1; i >= 0; i--) {
        cout << arr[i] << "\n";
    }
}