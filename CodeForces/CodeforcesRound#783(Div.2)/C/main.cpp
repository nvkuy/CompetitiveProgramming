#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0)
            a[i] *= -1;
    }
    long long ans = 1e18, tans;
    for (int i = 0; i < n; i++) {
        vector<long long> b(n, 0);
        tans = 0;
        for (int j = i - 1; j >= 0; j--) {
            long long tmp = ((b[j] - b[j + 1]) / a[j]) + 1;
            tans += tmp;
            b[j] -= (tmp * a[j]);
        }
        for (int j = i + 1; j < n; j++) {
            long long tmp = ((b[j] - b[j - 1]) / a[j]) + 1;
            tans += tmp;
            b[j] -= (tmp * a[j]);
        }
        ans = min(ans, tans);
    }
    cout << ans;

    return 0;
}
