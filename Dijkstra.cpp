//2019055078_Ω≈√§øµ

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int maximum = INT_MAX;
priority_queue < pair < int, int > > pq;
vector < pair < int, int > > e[300000];
vector < int > d(5000, maximum);
int N, M;


void Dijkstra(int x) {
    d[x] = 0;
    pq.push({ 0,x });
    while (!pq.empty()) {
        int a = -pq.top().first;
        int now = pq.top().second;

        pq.pop();
        for (int i = 0; i < e[now].size(); i++) {
            int next = e[now][i].first;
            int n_cost = e[now][i].second;

            if (d[next] > d[now] + n_cost) {
                d[next] = d[now] + n_cost;
                pq.push({ -d[next] , next });
            }
        }
    }
}
int main() {
    cin >> N >> M;

    d[1] = 0;
    for (int i = 1; i <= M; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        e[a].push_back({ b,weight });
    }

    Dijkstra(1);

    int num = 0;

    for (int i = 1; i <= N; i++) {
        if (d[i] != maximum) {
            num = max(num, d[i]);
        }
    }
    cout << num;
}