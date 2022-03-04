#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    long long k, ans, s, rd, t1, t2;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<long long> a(n + 1);
        ans = 1e18, s = 0LL, rd = 0LL;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
        }
        sort(a.begin() + 1, a.end());
        reverse(a.begin() + 2, a.end());
        for (int i = 1; i <= n; i++) {
            rd += (a[i] - a[1]);
            t2 = i;
            t1 = (s - rd - k) / t2;
            if (t1 < 0) {
                ans = min(ans, t2 - 1);
                continue;
            }
            if ((s - rd - k) > (t1 * t2))
                t1++;
            ans = min(ans, t1 + t2 - 1);
        }
        cout << ans << endl;
    }

    return 0;
}
