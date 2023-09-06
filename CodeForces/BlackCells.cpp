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
        multiset<int> s1, s2;
        long long cur_sum = 0, ans = 1e18;
        for (int i = 0; i < n; i++) {
            int seg = r[i] - l[i] + 1;
            cur_sum += seg;
            s2.insert(seg);
            if (s1.size() > 0 && *s1.rbegin() > *s2.begin()) {
                cur_sum += (*s1.rbegin() - *s2.begin());
                auto it = s1.end();
                it--;
                s2.insert(*it);
                s1.erase(it);
                it = s2.begin();
                s1.insert(*it);
                s2.erase(it);
            }
            while (true) {
                if (s2.size() == 0) break;
                auto it = s2.begin();
                if (cur_sum - *it >= k && *it <= 2) {
                    cur_sum -= *it;
                    s1.insert(*it);
                    s2.erase(it);
                } else break;
            }
            if (cur_sum >= k) {
                long long dont_need = min(cur_sum - k, seg - 1LL);
                long long real_end = r[i] - dont_need;
                ans = min(ans, real_end + 2LL * (int)s2.size());
            }
        }
        if (ans >= 1e17) ans = -1;
        cout << ans << endl;
    }

    return 0;
}
