#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), tmpb(n);
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> tmpb[i];
        for (int i = 0; i < n; i++) {
            if (b.size() == 0 || tmpb[i] > b.back().first)
                b.push_back({tmpb[i], i});
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            int l = 0, r = b.size() - 1, m;
            while (l < r) {
                m = (l + r) / 2;
                if (b[m].first > a[i])
                    r = m;
                else
                    l = m + 1;
            }
            ans = min(ans, i + b[l].second);
        }
        cout << ans << endl;
    }

    return 0;
}
