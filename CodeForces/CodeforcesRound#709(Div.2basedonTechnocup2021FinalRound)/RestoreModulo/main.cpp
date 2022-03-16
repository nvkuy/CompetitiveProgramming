#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        vector<pair<int, int>> inc, dec;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n < 3) {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i < n; i++) {
            int dt = a[i] - a[i - 1];
            if (dt < 0)
                dec.push_back(make_pair(i - 1, i));
            else
                inc.push_back(make_pair(i - 1, i));
        }
        if (dec.size() == n - 1) {
            int ans = 0, dt = a[dec[0].first] - a[dec[0].second];
            for (int i = 1; i < dec.size(); i++) {
                if (a[dec[i].first] - a[dec[i].second] != dt) {
                    ans = -1;
                    break;
                }
            }
            cout << ans << endl;
            continue;
        }
        if (inc.size() == n - 1) {
            int ans = 0, dt = a[inc[0].first] - a[inc[0].second];
            for (int i = 1; i < inc.size(); i++) {
                if (a[inc[i].first] - a[inc[i].second] != dt) {
                    ans = -1;
                    break;
                }
            }
            cout << ans << endl;
            continue;
        }
        int c = a[inc[0].second] - a[inc[0].first], m = a[dec[0].first] - a[dec[0].second] + c, ai = a[0] % m;
        bool icr = ai == a[0];
        for (int i = 1; i < n; i++) {
            if (!icr)
                break;
            ai = (ai + c) % m;
            if (ai != a[i])
                icr = false;
        }
        if (!icr) {
            cout << "-1\n";
            continue;
        }
        cout << m << ' ' << c << endl;
    }

    return 0;
}
