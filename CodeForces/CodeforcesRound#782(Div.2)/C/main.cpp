#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n, a, b, ai;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        vector<long long> ps(n + 1), arr(n + 1);
        ps[0] = arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            ps[i] = ps[i - 1] + arr[i];
        }
        long long ans = 2e18;
        for (int i = 0; i <= n; i++) {
            long long s1 = arr[i] * (a + b), s2 = (ps[n] - ps[i] - (n - i) * arr[i]) * b;
            ans = min(ans, s1 + s2);
            //cout << s1 << '|' << s2 << '|' << ans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
