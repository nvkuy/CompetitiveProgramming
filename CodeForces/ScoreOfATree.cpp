#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long mod = 1e9 + 7;
vector<vector<int>> c;
vector<int> f;
long long ans;

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

void dfs(int u, int par) {
    for (int v : c[u]) {
        if (v == par) continue;
        dfs(v, u);
        f[u] = max(f[u], f[v] + 1);
    }
    ans += f[u] + 1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        c.clear();
        c.resize(n + 1);
        f.assign(n + 1, 0);
        ans = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(1, 0);
        ans %= mod;
        ans *= power(2, n - 1);
        ans %= mod;
        cout << ans << endl;
    }

    return 0;
}
