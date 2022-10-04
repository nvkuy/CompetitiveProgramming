#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const long long INF = 1e18;
vector<vector<pair<int, long long>>> c;
vector<long long> dis;

void dijkstra(int st, int n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dis.assign(n + 1, INF);
    dis[st] = 0;
    pq.push(make_pair(0, st));

    while (pq.size()) {
        int u = pq.top().second;
        long long du = pq.top().first;
        pq.pop();
        if (du != dis[u])
            continue;

        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i].first;
            long long uv = c[u][i].second;
            if (dis[v] > du + uv) {
                dis[v] = du + uv;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m, u, v, w;
    cin >> n >> m;
    c.resize(2 * n + 1);
    while (m--) {
        cin >> u >> v >> w;
        c[u].push_back({v, w});
        c[v + n].push_back({u + n, w});
    }
    for (int i = 1; i <= n; i++)
        c[i].push_back({i + n, 0});

    dijkstra(1, 2 * n);

    for (int i = n + 2; i <= 2 * n; i++) 
        cout << (dis[i] >= INF ? -1 : dis[i]) << ' ';
    cout << endl;

    return 0;
}
