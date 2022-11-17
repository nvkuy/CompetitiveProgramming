#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long mod = 1e9 + 7, n, k;
    cin >> n >> k;
    vector<long long> pf(k + 1, 0), f, a(n + 1, 0), ps;
    pf[k] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f.assign(k + 1, 0);
        ps = f;
        ps[0] = pf[0];
        for (int j = 1; j <= k; j++)
            ps[j] = (ps[j - 1] + pf[j]) % mod;
        f[0] = ps[min(k, a[i])];
        for (int j = 1; j <= k; j++) {
            int r = min(k, j + a[i]);
            f[j] = (ps[r] - ps[j - 1] + mod) % mod;
        }
        pf = f;
    }
    cout << f[0] << endl;

    return 0;
}