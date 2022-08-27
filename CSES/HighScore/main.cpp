#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
    Edge(int uu, int vv, long long we) {
        u = uu;
        v = vv;
        w = we;
    }
};

int n;
vector<Edge> edges;
vector<long long> dist;
vector<int> trace;

void bellmanFord(int s) {

    dist.assign(n, INF);
    trace.assign(n, -1);

    dist[s] = 0;
    for(int T = 1; T < n; T++) {
        for (auto e : edges) {
            int u = e.u;
            int v = e.v;
            long long w = e.w;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = max(dist[u] + w, -INF);
                trace[v] = u;
            }
        }
    }
}

void negativeINFPath() {
    for(int T = 0; T < n; T++){
        for (auto e : edges) {
            int u = e.u;
            int v = e.v;
            long long w = e.w;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = -INF;
                trace[v] = u;
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test_input.txt", "r", stdin);
    int m, a, b, x;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> x;
        edges.push_back(Edge(a - 1, b - 1, -x));
    }
    bellmanFord(0);
    negativeINFPath();
    if (dist[n - 1] == -INF)
        dist[n - 1] = 1;
    cout << -dist[n - 1];

    return 0;
}
