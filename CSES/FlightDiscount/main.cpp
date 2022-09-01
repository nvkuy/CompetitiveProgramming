#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Edge {
    int from, to, cost;
};

int n;
const long long INF = 1e18;

void dijkstra(int st, vector<long long> &dis, vector<vector<pair<int, long long>>> &c) {
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

    int u, v, cost, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<long long> dis1, dis2;
    vector<vector<pair<int, long long>>> c1, c2;
    c1.resize(n + 1); c2.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> cost;
        c1[u].push_back({v, cost});
        c2[v].push_back({u, cost});
        edges[i] = {u, v, cost};
    }
    dijkstra(1, dis1, c1);
    dijkstra(n, dis2, c2);
    long long ans = INF;
    for (int i = 0; i < m; i++) {
        u = edges[i].from, v = edges[i].to, cost = edges[i].cost;
        ans = min(ans, dis1[u] + (cost / 2) + dis2[v]);
    }
    cout << ans;

    return 0;
}
