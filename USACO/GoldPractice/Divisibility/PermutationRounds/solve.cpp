#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD = 1e9 + 7;

int dfs(int u, vector<bool> &vis, vector<int> &p) {

    int res = 1;
    vis[u] = 1;
    
    int v = p[u];
    if (!vis[v]) res += dfs(v, vis, p);

    return res;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> prime_pow(n + 1, 0);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int cyc_len = dfs(i, vis, a);
        
        for (int j = 2; j * j <= cyc_len; j++) {
            if (cyc_len % j == 0) {
                int p_cnt = 0;
                while (cyc_len % j == 0) {
                    p_cnt++;
                    cyc_len /= j;
                }
                prime_pow[j] = max(prime_pow[j], p_cnt);
            }
        }
        if (cyc_len > 1) prime_pow[cyc_len] = max(prime_pow[cyc_len], 1);

    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        while (prime_pow[i]--) ans = (1LL * ans * i) % MOD;
    }

    cout << ans << endl;

    return 0;
}
