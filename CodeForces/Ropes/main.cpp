#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double l = 1e-7, r = 1e7, m, eps = 1e-7;
    while (fabs(r - l) > eps) {
        m = (l + r) / 2.0;
        long long cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += (long long)((1.0 * a[i]) / m);
        if (cnt >= k)
            l = m;
        else
            r = m - eps;
    }
    cout << setprecision(9) << fixed << l;

    return 0;
}
