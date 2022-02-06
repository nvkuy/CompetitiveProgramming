#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> d(n);
        long long ans = 0LL, s = 0LL;
        for (int i = 0; i < n; i++)
            cin >> d[i];
        sort(d.begin(), d.end());
        for (long long i = 1; i < n; i++) {
            ans += (d[i] - d[i - 1]);
            ans -= ((d[i] * (i - 1)) - s);
            ans -= d[i];
            s += d[i];
        }
        cout << ans << endl;
    }

    return 0;
}
