#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up, rangeLCA;
vector<int> depth;

void buildBL(int u, int par) {
    up[u][0] = par;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        depth[v] = depth[u] + 1;
        buildBL(v, u);
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

    int n, q, a, b;
    cin >> n >> q;
    c.resize(n + 1);
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(max_h));
    rangeLCA.assign(n + 1, vector<int>(max_h + 1));
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        c[b].push_back(a);
        c[a].push_back(b);
    }
    buildBL(1, 1);
    for (int i = 1; i <= n; i++)
        rangeLCA[i][0] = i;
    for (int j = 1; j <= max_h; j++) {
        for (int i = 1; i <= n; i++) {
            a = i;
            b = a + (1 << (j - 1));
            if (b + (1 << (j - 1)) - 1 > n)
                break;
            rangeLCA[i][j] = getLCA(rangeLCA[a][j - 1], rangeLCA[b][j - 1]);
        }
    }
    while (q--) {
        cin >> a >> b;
        int lca = a, p = a;
        for (int i = max_h; i >= 0; i--) {
            if (p + (1 << i) - 1 <= b) {
                lca = getLCA(lca, rangeLCA[p][i]);
                p += (1 << i);
            }
        }
        cout << lca << endl;
    }

    return 0;
}
