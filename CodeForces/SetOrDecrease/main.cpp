#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    long long n, k, s, x, ans;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<long long> a(n);
        s = 0LL, ans = 1e18 + 12;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        sort(a.begin(), a.end());
        if (n == 1)
            ans = min(ans, max(s - k, 0LL));
        s -= k;
        if (s <= 0)
            ans = 0LL;
        for (long long i = n; i > 1; i--) {
            s += (a[0] - a[i - 1]);
            x = (s + ((s % (n - i + 2) > 0) * (n - i + 2))) / (n - i + 2);
            if (x >= 0)
                ans = min(ans, x + (n - i + 1));
        }
        cout << ans << endl;
    }

    return 0;
}
