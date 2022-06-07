#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<int> d, a, needEdge;
vector<vector<int>> c;

void dfs(int u, int par) {
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u);
        if (needEdge[v] >= 0)
            needEdge[u] += (needEdge[v] + 1);
    }
    if (needEdge[u] == 0 && a[u] == 0)
        needEdge[u] = -1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, k, u, v, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x >> y;
        a.assign(n + 1, 0);
        d.assign(n + 1, 0);
        needEdge.assign(n + 1, 0);
        c.clear();
        c.resize(n + 1);
        a[y] = a[x] = 1;
        while (k--) {
            cin >> u;
            a[u] = 1;
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(x, 0);
        cout << (needEdge[x] * 2 - d[y]) << endl;
    }

    return 0;
}
