#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> a, f;
vector<vector<int>> c;
int sx, nc;

void dfs(int u, int par) {
    f[u] ^= a[u];
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        if (f[v] == sx)
            continue;
        f[u] ^= f[v];
    }
    if (f[u] == sx)
        nc++;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, k, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        sx = nc = 0;
        a.resize(n + 1);
        f.assign(n + 1, 0);
        c.clear();
        c.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sx ^= a[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        if (sx == 0) {
            cout << "YES" << endl;
            continue;
        }
        if (k == 2) {
            cout << "NO" << endl;
            continue;
        }
        dfs(1, 0);
        cout << ((nc >= 3) ? "YES" : "NO") << endl;
    }

    return 0;
}
