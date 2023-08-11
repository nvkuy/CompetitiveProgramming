#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long mod = 1e9 + 7;

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
        vector<pair<int, int>> order;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            order.push_back({a[i], i});
        }
        sort(order.begin(), order.end());
        long long l = 1e18, r = -1e18, ans = 1;
        for (int i = 0; i < n; i++) {
            long long p = order[i].second;
            if (p < l || p > r) {
                l = min(l, p);
                r = max(r, p);
            } else {
                long long rm = r - l + 1 - i;
                ans = (ans * rm) % mod;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
