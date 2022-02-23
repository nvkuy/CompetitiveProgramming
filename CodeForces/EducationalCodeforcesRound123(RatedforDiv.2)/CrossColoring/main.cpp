#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long ans, k, mod = 998244353;
    int t, n, m, q, x, y, c;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> q;
        vector<pair<int, int>> qr;
        vector<bool> ddr(n + 1, false), ddc(m + 1, false);
        while (q--) {
            cin >> x >> y;
            qr.push_back(make_pair(x, y));
        }
        c = 0;
        for (int i = qr.size() - 1; i >= 0; i--) {
            if ((!ddr[qr[i].first]) || (!ddc[qr[i].second]))
                c++;
            ddr[qr[i].first] = ddc[qr[i].second] = true;
        }
        ans = 1LL;
        while (c--)
            ans = (ans * k) % mod;
        cout << ans << endl;
    }

    return 0;
}
