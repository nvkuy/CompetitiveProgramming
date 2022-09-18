#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k, s, t, x, mod = 998244353, u, v;
    cin >> n >> m >> k >> s >> t >> x;
    vector<pair<int, int>> f(n + 1), pf(n + 1, {0, 0});
    vector<vector<int>> c(n + 1);
    pf[s] = {1, 0};
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    while (k--) {
        fill(f.begin(), f.end(), make_pair(0, 0));
        for (int u = 1; u <= n; u++) {
            for (int i = 0; i < c[u].size(); i++) {
                int v = c[u][i];
                if (v == x) {
                    f[v].second = (f[v].second + pf[u].first) % mod;
                    f[v].first = (f[v].first + pf[u].second) % mod;
                } else {
                    f[v].second = (f[v].second + pf[u].second) % mod;
                    f[v].first = (f[v].first + pf[u].first) % mod;
                }
            }
        }
        pf = f;
    }
    cout << pf[t].first;

    return 0;
}
