#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long s, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n);
        s = 0LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % (((n + 1) * n) / 2) > 0) {
            cout << "NO\n";
            continue;
        }
        s /= (((n + 1) * n) / 2);
        vector<long long> ans(n);
        bool iok = true;
        for (int i = 0; i < n; i++) {
            ans[(i + 1) % n] = ((a[(i + 1) % n] - a[i]) - s);
            if (ans[(i + 1) % n] % n == 0)
                ans[(i + 1) % n] /= (-n);
            else {
                iok = false;
                break;
            }
            if (ans[(i + 1) % n] <= 0) {
                iok = false;
                break;
            }
        }
        if (!iok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
