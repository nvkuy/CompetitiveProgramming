#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, er;
    cin >> k >> er;
    vector<vector<int>> c(k + 1, vector<int>(k + 1, -2e9));
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            cin >> c[i][j];

    int n, mod = 1e9 + 7;
    cin >> n;
    vector<int> trans(n);
    for (int i = 1; i < n; i++)
        cin >> trans[i];
    
    vector<int> pf(k + 2, 1), f(k + 2);
    for (int i = 1; i < n; i++) {
        fill(f.begin(), f.end(), 0);
        for (int j = 1; j <= k; j++) {
            int l = lower_bound(c[j].begin() + 1, c[j].end(), trans[i] - er) - c[j].begin();
            int r = upper_bound(c[j].begin() + 1, c[j].end(), trans[i] + er) - c[j].begin();
            r--;
            if (l > r) continue;
            f[l] = (f[l] + pf[j]) % mod;
            f[r + 1] = (f[r + 1] + mod - pf[j]) % mod;
        }
        for (int j = 1; j <= k; j++)
            f[j] = (f[j - 1] + f[j]) % mod;
        pf = f;
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (ans + f[i]) % mod;
    cout << ans << endl;

    return 0;
}
