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

int n, rm;
vector<Edge> edges, original;
vector<long long> dist;
vector<int> trace;

void bellmanFord(int s) {

    dist[s] = 0;

    vector<int> used(edges.size(), 0);

    for(int T = 1; T < rm; T++) {
        for (int i = 0; i < edges.size(); i++) {
            Edge e = edges[i];
            int u = e.u;
            int v = e.v;
            long long w = e.w;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = max(dist[u] + w, -INF);
                trace[v] = u;
                used[i] = true;
            }
        }
    }

    vector<Edge> nes;
    for (int i = 0; i < edges.size(); i++)
        if (used[i] == 0) nes.push_back(edges[i]);
    edges = nes;
    rm = 0;
    for (int i = 0; i < n; i++)
        if (dist[i] == INF) rm++;

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

vector<int> findNegativeCycle() {
    int negStart = -1;
    for (auto e : original) {
        int u = e.u;
        int v = e.v;
        long long w = e.w;
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            dist[v] = -INF;
            trace[v] = u;
            negStart = v;
        }
    }

    if (negStart == -1) return vector<int>(0);

    vector<int> negCycle;
    int u = negStart;
    for (int i = 0; i < n; i++)
        u = trace[u];
    negCycle = vector<int>(1, u);
    for (int v = trace[u]; v != u; v = trace[v])
        negCycle.push_back(v);
    negCycle.push_back(u);
    reverse(negCycle.begin(), negCycle.end());

    return negCycle;
}

vector<int> trace_path(int st, int u) {

    if (u != st && trace[u] == -1) return vector<int>(0);
    vector<int> path;
    while (u != -1) {
        path.push_back(u);
        u = trace[u];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, a, b, c;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        edges.push_back(Edge(a - 1, b - 1, c));
    }
    rm = n;
    dist.assign(n, INF);
    trace.assign(n, -1);
    vector<int> ans;
    original = edges;
    for (int i = 0; i < n; i++) {
        if (ans.size() > 0)
            break;
        if (dist[i] == INF) bellmanFord(i), ans = findNegativeCycle();
    }
    if (ans.size() == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << ' ';

    return 0;
}
