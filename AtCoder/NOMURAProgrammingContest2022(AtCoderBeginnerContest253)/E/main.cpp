#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, m, k, mod = 998244353;
    cin >> n >> m >> k;
    vector<long long> ps(m + 1), pf(m + 1, 0), f(m + 1);
    fill(pf.begin() + 1, pf.end(), 1);
    for (int i = 1; i < n; i++) {
        fill(ps.begin(), ps.end(), 0);
        fill(f.begin(), f.end(), 0);
        for (int j = 1; j <= m; j++)
            ps[j] = (ps[j - 1] + pf[j]) % mod;
        for (int j = 1; j <= m; j++) {
            if (j + k <= m)
                f[j] = (f[j] + ps[m] - ps[j + k - 1] + mod) % mod;
            if (j - k > 0)
                f[j] = (f[j] + ps[j - k]) % mod;
            if (k == 0)
                f[j] = (f[j] - pf[j] + mod) % mod;
        }
        pf = f;
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + pf[i]) % mod;
    cout << ans;

    return 0;
}
