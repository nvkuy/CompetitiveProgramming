#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n), f(33, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            bitset<33> bs(a[i]);
            for (int j = 0; j <= 30; j++)
                f[j] += (!bs[j]);
        }
        long long ans = 0;
        for (int i = 30; i >= 0; i--) {
            if (k >= f[i]) {
                k -= f[i];
                ans += (1LL << i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
