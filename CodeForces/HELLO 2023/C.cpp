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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        long long cs = 0;
        multiset<int> s;
        for (int i = m - 1; i > 0; i--) {
            if (a[i] > 0)
                s.insert(a[i]);
            cs += a[i];
            if (cs > 0) {
                auto it = s.end(); it--;
                cs -= (2 * (*it));
                s.erase(it);
                ans++;
            }
        }
        cs = 0;
        s.clear();
        for (int i = m; i < n; i++) {
            if (a[i] < 0)
                s.insert(a[i]);
            cs += a[i];
            if (cs < 0) {
                auto it = s.begin();
                cs -= (2 * (*it));
                s.erase(it);
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
