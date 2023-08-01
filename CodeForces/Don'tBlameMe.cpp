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

    int t, mod = 1e9 + 7;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> pf(1 << 6, 0), f(1 << 6);
        pf[(1 << 6) - 1] = 1;
        for (int i = 0; i < n; i++) {
            f = pf;
            for (int pre_mask = 0; pre_mask < (1 << 6); pre_mask++) {
                f[pre_mask & a[i]] += pf[pre_mask];
                f[pre_mask & a[i]] %= mod;
            }
            pf = f;
        }
        f[(1 << 6) - 1] += (mod - 1);
        f[(1 << 6) - 1] %= mod;

        int ans = 0;
        for (int i = 0; i < (1 << 6); i++) {
            if (__builtin_popcount(i) == k) {
                ans += f[i];
                ans %= mod;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
