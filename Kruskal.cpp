//2019055078_Ω≈√§øµ
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int N, M;
int arr[1001];
int a, b, c;

vector <pair <int,pair <int,int > > > pq;
vector <pair <int,pair <int,int > > >  vec;
vector < int > check;

int find(int n) {
    if (arr[n] == n)
        return n;
    else
        return arr[n] = find(arr[n]);
}
int union_(int a, int b) {
    int para = find(a);
    int parb = find(b);

    if (para != parb) {
        arr[para] = parb;
        return 1;
    }
    else return 0;
}
void kruscal() {
    int a, b, w;
    for (int i = 0; i < M; i++) {
        a = pq[i].second.first;
        b = pq[i].second.second;
        w = pq[i].first;
        int n = union_(a, b);
        if (n == 1) {
            vec.push_back({ w,{a,b} });
        }
        if (vec.size() == N - 1) return;
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a < b) 
            pq.push_back({ c,{a,b} });       
        else 
            pq.push_back({ c,{b,a} });      
    }

    sort(pq.begin(), pq.end());
    kruscal();
    printf("%d\n", vec.size());
    for (int i = 0; i < (int)vec.size(); i++) {
        printf("%d ", vec[i].second.first);
        printf("%d ", vec[i].second.second);
        printf("%d\n", vec[i].first);
    }
    return 0;
}