#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Edge {
    int toNode;
    long long cost;
    Edge(int to, long long c) {
        toNode = to;
        cost = c;
    }
};

const int max_h = 15;
vector<vector<Edge>> c;
vector<vector<int>> up;
vector<long long> depth, dis;

void buildBL(int u, int par) {
    up[u][0] = par;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (Edge e : c[u]) {
        if (e.toNode == par)
            continue;
        depth[e.toNode] = depth[u] + 1;
        dis[e.toNode] = dis[u] + e.cost;
        buildBL(e.toNode, u);
    }
}

int upByK(int u, int k) {
    bitset<max_h> bs(k);
    for (int i = 0; i < max_h; i++) {
        if (bs[i])
            u = up[u][i];
    }
    return u;
}

int getLCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int depth_diff = depth[u] - depth[v];
    u = upByK(u, depth_diff);
    for (int i = max_h - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    if (u != v)
        u = up[u][0];
    return u;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b, k, t;
    string type;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        depth.assign(n + 1, 0LL);
        dis.assign(n + 1, 0LL);
        up.assign(n + 1, vector<int>(max_h));
        for (int i = 1; i < n; i++) {
            cin >> a >> b >> k;
            c[a].push_back(Edge(b, k));
            c[b].push_back(Edge(a, k));
        }
        buildBL(1, 1);
        while (true) {
            cin >> type;
            if (type == "DONE")
                break;
            if (type == "DIST") {
                cin >> a >> b;
                k = getLCA(a, b);
                cout << -2LL * dis[k] + dis[a] + dis[b] << endl;
            } else {
                cin >> a >> b >> k;
                int lca = getLCA(a, b);
                int d1 = depth[a] - depth[lca], d2 = depth[b] - depth[lca];
                if (d1 + d2 + 1 < k) {
                    cout << b << endl;
                    continue;
                }
                if (d1 + 1 >= k) {
                    a = upByK(a, k - 1);
                    cout << a << endl;
                    continue;
                }
                k -= (d1 + 1);
                d2 -= k;
                b = upByK(b, d2);
                cout << b << endl;
            }
        }
    }

    return 0;
}
