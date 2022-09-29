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

const int maxS = 505;

int f[maxS][maxS / 2][3], pf[maxS][maxS / 2][3], n, x, m;
int ps1[maxS], ps2[maxS], ps3[maxS], ps4[maxS];

void copyf() {
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k < 3; k++)
                pf[i][j][k] = f[i][j][k];
}

void init() {
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k < 3; k++)
                pf[i][j][k] = 0, f[i][j][k] = 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int mod = 1e9 + 7;
    cin >> n >> x >> m;
    if (n < 3 || m * 2 + 1 > n) {
        cout << 0 << endl;
        return 0;
    }

    init();
    for (int i = 1; i <= x; i++) {
        pf[i][0][0] = 1;
        pf[i][0][1] = i - 1;
        pf[i][0][2] = x - i;
    }
    for (int i = 2; i < n; i++) {
        for (int k = 0; k <= m; k++) {
            memset(ps1, 0, sizeof(ps1));
            memset(ps2, 0, sizeof(ps2));
            memset(ps3, 0, sizeof(ps3));
            memset(ps4, 0, sizeof(ps4));
            for (int j = 1; j <= x; j++) {
                ps1[j] = (ps1[j - 1] + pf[j][k][1]) % mod;
                ps2[j] = (ps2[j - 1] + pf[j][k][2]) % mod;
                if (k > 0)
                    ps3[j] = (ps3[j - 1] + pf[j][k - 1][1]) % mod;
                ps4[j] = (ps4[j - 1] + pf[j][k][0]) % mod;
            }
            for (int j = 1; j <= x; j++) {
                f[j][k][0] = (pf[j][k][0] + ((pf[j][k][1] + pf[j][k][2]) % mod)) % mod;
                f[j][k][2] = (ps2[x] - ps2[j] + mod) % mod;
                f[j][k][2] = (f[j][k][2] + ((ps4[x] - ps4[j] + mod) % mod)) % mod;
                f[j][k][2] = (f[j][k][2] + ((ps3[x] - ps3[j] + mod) % mod)) % mod;
                f[j][k][1] = (ps1[j - 1] + ps2[j - 1]) % mod;
                f[j][k][1] = (f[j][k][1] + ps4[j - 1]) % mod;
            }
        }
        copyf();
    }
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        ans = (ans + pf[i][m][0]) % mod;
        ans = (ans + pf[i][m][1]) % mod;
        ans = (ans + pf[i][m][2]) % mod;
    }
    cout << ans << endl;

    return 0;
}
