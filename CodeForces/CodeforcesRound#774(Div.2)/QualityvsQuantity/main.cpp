#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        long long s = 0LL, ms = 0LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < (n / 2) - (n % 2 == 0); i++)
            ms += a[i];
        if (n % 2 == 0)
            s -= a[n / 2 - 1];
        //cout << s << ' ' << ms << endl;
        cout << (((s - ms) < ms) ? "YES" : "NO") << endl;
    }

    return 0;
}
