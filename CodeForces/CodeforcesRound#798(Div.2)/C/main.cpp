#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<pair<int, int>> f;

void dfs(int u, int par) {
    vector<int> child;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        child.push_back(v);
        f[u].first += f[v].first;
    }
    if (child.size() == 1)
        f[u].second = f[child[0]].first - 1;
    if (child.size() == 2)
        f[u].second = max(f[child[0]].first - 1 + f[child[1]].second, f[child[1]].first - 1 + f[child[0]].second);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear(); c.resize(n + 1);
        f.assign(n + 1, {1, 0});
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(1, 0);
        cout << f[1].second << endl;
    }

    return 0;
}
