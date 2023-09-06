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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) cin >> l[i];
        for (int i = 0; i < n; i++) cin >> r[i];
        multiset<int> s;
        long long ans = 1e18, cur_sum = 0;
        for (int i = 0; i < n; i++) {
            int seg = r[i] - l[i] + 1;
            s.insert(seg);
            cur_sum += seg;
            while (true) {
                auto it = s.begin();
                if (cur_sum - *it >= k && *it < 2) {
                    cur_sum -= *it;
                    s.erase(it);
                } else break;
            }
            if (cur_sum >= k) {
                long long real_end = r[i] - min(seg - 1LL, cur_sum - k);
                ans = min(ans, real_end + (int)s.size() * 2LL);
            }
        }
        if (ans >= 1e17) ans = -1;
        cout << ans << endl;
    }

    return 0;
}
