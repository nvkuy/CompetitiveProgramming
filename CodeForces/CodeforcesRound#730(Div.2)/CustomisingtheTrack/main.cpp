#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n), f;
        long long s = 0LL, re = 0LL, ans = 0LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        re = s % n;
        s /= n;
        for (int i = 0; i < n; i++) {
            a[i] = s;
            if (re > 0) {
                a[i]++;
                re--;
            }
        }
        f.push_back(a[0]);
        for (int i = 1; i < n; i++)
            f.push_back(f[i - 1] + a[i]);
        for (int i = 0; i < n; i++)
            ans += ((n - i - 1) * a[i] - (f[n - 1] - f[i]));

        cout << ans << endl;
    }

    return 0;
}
