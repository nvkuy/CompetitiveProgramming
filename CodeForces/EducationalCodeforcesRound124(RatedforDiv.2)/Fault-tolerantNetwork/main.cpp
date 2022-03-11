#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        long long ans, m1 = 1e9 + 7, m2 = 1e9 + 7, m3 = 1e9 + 7, m4 = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            m1 = min(m1, abs(a[i] - b[0]));
            m2 = min(m2, abs(a[i] - b[n - 1]));
            m3 = min(m3, abs(b[i] - a[0]));
            m4 = min(m4, abs(b[i] - a[n - 1]));
        }
        ans = m1 + m2 + m3 + m4;
        ans = min(ans, abs(a[0] - b[0]) + m2 + m4);
        ans = min(ans, abs(a[n - 1] - b[n - 1]) + m1 + m3);
        ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
        ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
        ans = min(ans, abs(a[0] - b[n - 1]) + m1 + m4);
        ans = min(ans, abs(a[n - 1] - b[0]) + m2 + m3);

        cout << ans << endl;
    }

    return 0;
}
