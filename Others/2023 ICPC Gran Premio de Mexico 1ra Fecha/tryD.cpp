#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            cin >> k;
            auto it = lower_bound(a.begin(), a.end(), k);
            if (it != a.end() && *it == k) continue;
            it = upper_bound(a.begin(), a.end(), k);
            if (it == a.end())
                a.push_back(k);
            else
                *it = k;
        } else {
            int x, y;
            cin >> x >> y;
            int l = lower_bound(a.begin(), a.end(), x) - a.begin();
            int r = upper_bound(a.begin(), a.end(), y) - a.begin();
            int ans = r - l;
            cout << ans << endl;
        }
    }

    return 0;
}
