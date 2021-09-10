//2019055078_Ω≈√§øµ

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, a, b;
int done[1001];
int wh[1001];
int clr[1001];
vector<int>arr;
vector<int>e[1001];
int T = 0;
int check = 0;

void visit(int a) {
    wh[a] = 1;
    clr[a] = 1;

    T++;
    for (int i = 0; i < e[a].size(); i++) {
        int next = e[a][i];
        if (wh[next] == 0) {
            visit(next);
        }
        if (clr[next] == 1) {
            check = 1;
        }
    }
    wh[a] = 1;
    clr[a] = 2;

    T++;
    done[a] = T;
    arr.push_back(a);
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        e[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        sort(e[i].begin(), e[i].end());
        clr[i] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        if (wh[i] == 0) 
            visit(i);
    }

    if (check == 1) cout << 0 << endl;

    else cout << 1 << endl;
    for (int i = arr.size() - 1; i >= 0; i--) 
        cout << arr[i] << " ";
   
}