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
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<vector<int>>> reset(x + 1, vector<vector<int>>(m + 1, vector<int>(3, 0))), pf = reset, f = reset;
    for (int i = 1; i <= x; i++) {
        pf[i][0][0] = 1;
        pf[i][0][1] = i;
        pf[i][0][2] = x - i - 1;
    }
    for (int i = 2; i < n; i++) {
        for (int k = 0; k <= m; k++) {
            vector<int> ps1(x + 1, 0), ps2(x + 1, 0), ps3(x + 1, 0);
            for (int j = 1; j <= x; j++) {
                ps1[j] = (ps1[j - 1] + pf[j][k][1]) % mod;
                ps2[j] = (ps2[j - 1] + pf[j][k][2]) % mod;
                if (k > 0)
                    ps3[j] = (ps3[j - 1] + pf[j][k - 1][1]) % mod;
            }
            for (int j = 1; j <= x; j++) {
                f[j][k][0] = pf[j][k][0];
                f[j][k][2] = (pf[j][k][0] + ps2[x] - ps2[j] + mod) % mod;
                f[j][k][2] = (f[j][k][2] + ps3[x] - ps3[j] + mod) % mod;
                f[j][k][1] = (pf[j][k][0] + ps1[j - 1]) % mod;
                f[j][k][1] = (f[j][k][1] + ps1[j - 1]) % mod;
            }
        }
        pf = f;
        f = reset;
    }
    long long ans = 0;
    for (int i = 1; i <= x; i++) {
        ans = (ans + f[i][m][0]) % mod;
        ans = (ans + f[i][m][1]) % mod;
        ans = (ans + f[i][m][2]) % mod;
    }
    cout << ans << endl;

    return 0;
}
