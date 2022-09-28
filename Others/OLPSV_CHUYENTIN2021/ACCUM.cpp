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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, x, m;
    long long mod = 1e9 + 7;
    cin >> n >> x >> m;
    vector<vector<vector<int>>> reset(x, vector<vector<int>>(m + 1, vector<int>(2, 0))), pf = reset, f = reset;
    for (int i = 0; i < x; i++)
        pf[i][0][0] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int k = 0; k <= m; k++) {
            long long pspf0 = 0, pspf1 = 0;
            long long fspf0 = 0, fspf1 = 0;
            for (int j = 0; j < x; j++) {
                fspf0 = (fspf0 + pf[j][k][0]) % mod;
                fspf1 = (fspf1 + pf[j][k][1]) % mod;
            }
            for (int j = 0; j < x; j++) {
                f[j][k][1] = pspf0;
                if (k > 0)
                    pspf0 = (pspf0 + pf[j][k - 1][0]) % mod;
                pspf1 = (pspf1 + pf[j][k][1]) % mod;
                f[j][k][0] = fspf0;
                f[j][k][0] = (long long)(mod + f[j][k][0] + fspf1 - pspf1) % mod;
            }
        }
        pf = f;
        f = reset;
    }
    long long ans = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++)
            ans = (ans + pf[i][m][0]) % mod;
        for (int j = i + 1; j < x; j++)
            ans = (ans + pf[j][m][1]) % mod;
    }
    cout << ans << endl;

    return 0;
}
