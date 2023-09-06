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
        long long n, m, d, ans = 0, cur_sum = 0;
        cin >> n >> m >> d;
        multiset<long long> will_watch;
        for (long long day = 1; day <= n; day++) {
            long long ai;
            cin >> ai;
            will_watch.insert(ai);
            cur_sum += ai;
            while (will_watch.size() > m || (will_watch.size() > 0 && *will_watch.begin() <= 0)) {
                cur_sum -= *will_watch.begin();
                will_watch.erase(will_watch.begin());
            }
            ans = max(ans, cur_sum - d * day);
        }
        cout << ans << endl;
    }

    return 0;
}
