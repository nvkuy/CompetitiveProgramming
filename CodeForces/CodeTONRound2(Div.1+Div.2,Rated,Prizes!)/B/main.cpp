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

    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0, cmax = a[0], cmin = a[0];
        for (int i = 0; i < n; i++) {
            cmax = max(cmax, a[i]);
            cmin = min(cmin, a[i]);
            if (cmax - cmin > 2 * x) {
                ans++;
                cmax = cmin = a[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
