#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long mod = 1e9 + 7;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int c = (1 << 30) - 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c &= a[i];
        }
        sort(a.begin(), a.end());
        if (c != a[0]) {
            cout << "0\n";
            continue;
        }
        c = 1;
        for (int i = 1; i < n; i++)
            if (a[i] == a[0])
                c++;
            else
                break;
        if (c < 2) {
            cout << "0\n";
            continue;
        }
        long long ans = 1LL;
        for (long long i = 1; i <= c; i++)
            ans = (ans * i) % mod;
        for (long long i = (c - 2 + 1); i <= (n - 2); i++)
            ans = (ans * i) % mod;
        cout << ans << endl;
    }

    return 0;
}
