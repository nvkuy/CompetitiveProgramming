#include <bits/stdc++.h>

using namespace std;

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

vector<int> findNegativeCycle() {
    int negStart = -1;
    for (auto e : edges) {
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
    for (int v = trace[u]; v != u; v = trace[u])
        negCycle.push_back(v);
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

    int m, s, u, v, w;
    cin >> n >> m >> s;
    while (m--) {
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    bellmanFord(s);
    negativeINFPath();
    for (int i = 0; i < n; i++) {
        if (dist[i] > 1e17)
            cout << "Impossible";
        else if (dist[i] < -1e17)
            cout << "-Infinity";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
