#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n + 1), b(n + 1), psa(n + 1, 0), psb(n + 1, 0);
        long long ans = 0LL;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += (n - 1) * (a[i] * a[i]);
            psa[i] = psa[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            ans += (n - 1) * (b[i] * b[i]);
            psb[i] = psb[i - 1] + b[i];
        }
        vector<vector<long long>> f(n + 1, vector<long long>(2, 0));
        for (int i = 1; i <= n; i++) {
            long long pre_min = min(f[i - 1][0], f[i - 1][1]);
            long long ps1 = psa[n] - psa[i], ps2 = psb[n] - psb[i];
            f[i][0] = b[i] * ps1 + a[i] * ps2 + pre_min;
            f[i][1] = a[i] * ps1 + b[i] * ps2 + pre_min;
        }
        ans += min(f[n][0], f[n][1]);
        cout << ans << endl;
    }

    return 0;
}
