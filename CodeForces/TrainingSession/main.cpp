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
        vector<long long> a(n), b(n), cnta(n + 1, 0), cntb(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            cnta[a[i]]++, cntb[b[i]]++;
        }
        long long ans = (n * (n - 1LL) * (n - 2LL)) / 6LL;
        for (int i = 0; i < n; i++)
            ans -= ((cnta[a[i]] - 1LL) * (cntb[b[i]] - 1LL));
        cout << ans << endl;
    }

    return 0;
}
