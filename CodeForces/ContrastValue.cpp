#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (ans.size() == 0) {
                ans.push_back(a[i]);
                continue;
            }
            if (ans.back() == a[i]) continue;
            if (ans.size() == 1) ans.push_back(a[i]);
            else {
                int sz = ans.size();
                long long d1 = abs(ans[sz - 1] - ans[sz - 2]), d2 = abs(ans[sz - 1] - a[i]), d3 = abs(ans[sz - 2] - a[i]);
                if (d1 + d2 == d3)
                    ans.pop_back();
                ans.push_back(a[i]);
            }
        }
        cout << ans.size() << endl;
    }

    return 0;
}
