#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long INF = 1e18;
int n, m;
vector<vector<pair<int, long long>>> c;
vector<long long> dis;

void dijkstra(int st, int fi, int x) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dis.assign(n + 1, INF);
    dis[st] = x;
    pq.push(make_pair(x, st));

    while (pq.size()) {
        int u = pq.top().second;
        long long du = pq.top().first;
        pq.pop();
        if (du != dis[u])
            continue;
        if (u == fi)
            return;
        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i].first;
            long long uv = c[u][i].second;
            if (dis[v] > du + uv + x) {
                dis[v] = du + uv + x;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("in", "r", stdin);

    int q, u, v, w;
    cin >> n >> m >> q;
    c.resize(n + 1);
    while (m--) {
        cin >> u >> v >> w;
        c[u].push_back({v, w});
        // c[v].push_back({u, w});
    }
    while (q--) {
        cin >> u >> v >> w;
        dijkstra(u, v, w);
        if (dis[v] >= INF)
            dis[v] = -1;
        cout << dis[v] << endl;
    }

    return 0;
}