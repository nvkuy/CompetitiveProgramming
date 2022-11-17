#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
vector<vector<int>> c;
vector<pair<long long, long long>> f;

void dfs(int u, int par) {
    if (c[u].size() <= 1 && u != par) {
        f[u] = {1, 1};
        return;
    }
    long long fc = 1, wc = 1;
    for (int v : c[u]) {
        if (v == par)
            continue;
        dfs(v, u);
        fc *= (f[v].first + f[v].second);
        fc %= mod;
        wc *= f[v].first;
        wc %= mod;
    }
    f[u] = {fc, wc};
}

int main() {

    int u, v, n;
    cin >> n;
    c.resize(n);
    f.assign(n, {0, 0});
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dfs(0, 0);
    cout << (f[0].first + f[0].second) % mod << endl;

    return 0;
}