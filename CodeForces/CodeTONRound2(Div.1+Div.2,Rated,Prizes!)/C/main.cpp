#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, rm;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> d;
        for (int i = 0; i + 1 < m; i++) {
            rm = a[i + 1] - a[i] - 1;
            if (rm == 0)
                continue;
            d.push_back(rm);
        }
        rm = n - (a[m - 1] - a[0] + 1);
        d.push_back(rm);
        sort(d.begin(), d.end(), greater<int>());
        int ans = 0, day = 0;
        for (int i = 0; i < d.size(); i++) {
            if (d[i] - 2 * day <= 0)
                break;
            d[i] -= (2 * day);
            ans++;
            day++;
            d[i] -= 2;
            if (d[i] > 0) {
                ans += d[i];
                day++;
            }
        }
        cout << n - ans << endl;
    }

    return 0;
}
