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

    long long n, m, t, mod = 1e9 + 9;
    cin >> n >> m >> t;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    vector<vector<long long>> pf(n + 1, vector<long long>(m + 1, 1)), f;
    for (int i = 1; i <= t; i++) {
        f = vector<vector<long long>>(n + 1, vector<long long>(m + 1, 0));
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                f[j][k] = (f[j - 1][k] + f[j][k - 1] - f[j - 1][k - 1] + mod) % mod;
                if (a[j] > b[k])
                    f[j][k] = (f[j][k] + pf[j - 1][k - 1]) % mod;
            }
        }
        pf = f;
    }
    cout << pf[n][m] << endl;

    return 0;
}
