#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, ans = 0, mt, t;
    cin >> n >> k;
    vector<int> a(n), f(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        f[i] = f[i - 1];
        if (t != 1)
            f[i] += a[i - 1];
    }
    ans -= f[n];
    mt = 0;
    for (int i = 1; i + k - 1 <= n; i++)
        mt = max(mt, f[i + k - 1] - f[i - 1]);
    cout << ans + mt;

    return 0;
}
