#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<pair<int, int>>> c;
vector<vector<double>> f;

void dfs(int u, int par) {
    if (u != 1 && c[u].size() == 1) {
        fill(f[u].begin(), f[u].end(), 1e16);
        f[u][0] = 0;
        return;
    }
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i].first;
        double edgeCost = (c[u][i].second * 1.0);
        if (v == par)
            continue;
        dfs(v, u);
        for (int i = 0; i <= 100; i++) {
            double minCost = 1e18, au = (i * 1.0) / 100.0, av;
            for (int j = 0; j <= i; j++) {
                av = (j * 1.0) / 100.0;
                minCost = min(minCost, (au - av) * edgeCost + f[v][j]);
            }
            f[u][i] += minCost;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, u, cc;
    cout << setprecision(2) << fixed;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        f.assign(n + 1, vector<double>(101, 0));
        for (int i = 2; i <= n; i++) {
            cin >> u >> cc;
            c[i].push_back({u, cc});
            c[u].push_back({i, cc});
        }
        dfs(1, 0);
        cout << f[1][100] << endl;
    }

    return 0;
}
