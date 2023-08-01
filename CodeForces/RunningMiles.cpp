#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), l(n), r(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) l[i] = a[i] - i;
        for (int i = n - 1; i >= 0; i--) r[i] = a[i] - (n - i - 1);
        vector<int> ll(n, -1), rr(n, -1);
        int cur = 0;
        for (int i = 1; i < n; i++) {
            ll[i] = cur;
            if (r[cur] < r[i]) cur = i;
        }
        cur = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            rr[i] = cur;
            if (l[cur] < l[i]) cur = i;
        }
        int ans = -1e9;
        for (int i = 1; i + 1 < n; i++) {
            int opt_l = ll[i], opt_r = rr[i];
            ans = max(ans, a[opt_l] + a[opt_r] + a[i] - (opt_r - opt_l));
        }
        cout << ans << endl;
    }

    return 0;
}
