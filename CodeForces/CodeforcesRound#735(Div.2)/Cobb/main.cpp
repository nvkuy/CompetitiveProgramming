#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long ans = -1e18, tmp;
        for (long long i = max(n - 202, 1LL); i <= n; i++) {
            for (long long j = i + 1; j <= n; j++) {
                tmp = (a[i] | a[j]);
                ans = max(ans, i * j - k * tmp);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
