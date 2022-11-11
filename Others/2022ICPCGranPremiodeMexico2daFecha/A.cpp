#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int inf = 1e8;
vector<vector<pair<int, int>>> c;
vector<int> dd, f;

void dfs(int u) {
    dd[u] = 1;
    int tans = 0;
    for (auto p : c[u]) {
        if (dd[p.first] == 0)
            dfs(p.first);
        tans = min(inf, tans + f[p.first] + p.second);
    }
    f[u] = tans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m, cc;
    int u, v, cost;
    cin >> n >> m >> cc;
    f.assign(n + 1, inf);
    dd.assign(n + 1, 0);
    c.resize(n + 1);
    while (m--) {
        cin >> u >> v >> cost;
        c[v].push_back({u, cost});
    }
    dd[1] = f[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (dd[i] == 0)
            dfs(i);
    }
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << ' ';
    // cout << endl;
    long long mod = 1e9 + 7;
    vector<long long> dp(cc + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (f[i] > cc)
            continue;
        for (int j = 1; j <= cc; j++)
            if (j - f[i] >= 0)
                dp[j] = (dp[j] + dp[j - f[i]]) % mod;
    }
    long long ans = 0;
    for (int i = 1; i <= cc; i++) {
        ans = (ans + dp[i]) % mod;
        // cout << dp[i] << ' ';
    }
    // cout << endl;
    cout << ans << endl;

    return 0;
}
