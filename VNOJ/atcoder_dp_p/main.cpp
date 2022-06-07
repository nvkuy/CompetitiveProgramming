#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long mod = 1e9 + 7;
vector<vector<int>> c;
vector<pair<long long, long long>> f;

void dfs(int u, int par) {
    f[u].first = f[u].second = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        f[u].first = (f[u].first * f[v].second) % mod;
        f[u].second = (f[u].second * (f[v].first + f[v].second)) % mod;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, u, v;
    cin >> n;
    c.resize(n + 1);
    f.assign(n + 1, {0, 0});
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dfs(1, 0);
    cout << (f[1].first + f[1].second) % mod;

    return 0;
}
