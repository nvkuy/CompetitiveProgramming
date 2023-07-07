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

struct edge {
    int to, wisdom, cost;
};

const long long INF = 1e18;
int n;
vector<vector<edge>> c;
vector<long long> dis;

void dijkstra(int st, int wisdom) {
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

        for (edge e : c[u]) {
            if (e.wisdom > wisdom)
                continue;
            int v = e.to;
            long long uv = e.cost;
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

    // debugLocal();
    int t;
    cin >> t;
    while (t--) {
        int m, k;
        cin >> n >> m >> k;
        c.clear();
        c.resize(n + 1);
        while (m--) {
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            c[u].push_back({v, b, a});
            c[v].push_back({u, b, a});
        }
        int ll = 0, rr = 1e9 + 7;
        while (ll < rr) {
            int mm = (ll + rr) / 2;
            dijkstra(1, mm);
            if (dis[n] < k)
                rr = mm;
            else
                ll = mm + 1;
        }
        if (rr > 1e9)
            rr = -1;
        cout << rr << endl;
    }

    return 0;
}
