#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<pair<long long, int>>> c;
int n;
vector<long long> d;

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    d.assign(n + 1, 1e18);
    d[start] = 0;
    pq.push(make_pair(0, start));

    while (pq.size()) {
        int u = pq.top().second;
        long long du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i].second;
            long long uv = c[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, u, v, cost;
    cin >> n >> m;
    c.resize(n + 1);
    while (m--) {
        cin >> u >> v >> cost;
        c[u].push_back(make_pair(cost, v));
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';

    return 0;
}
