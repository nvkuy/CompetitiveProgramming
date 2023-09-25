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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int tans = 0;
            vector<pair<int, int>> min_pos, ranges;
            for (int j = i; j >= 0; j--) {
                int cur_l = j, cur_r = j;
                if (min_pos.size() == 0 || min_pos.back().first >= a[j])
                    min_pos.push_back({a[j], j});
                else {
                    int l = 0, r = min_pos.size() - 1, m;
                    while (l < r) {
                        m = (l + r) / 2;
                        if (min_pos[m].first < a[j])
                            r = m;
                        else
                            l = m + 1;
                    }
                    cur_r = min_pos[r].second;
                }
                while (ranges.size() > 0 && ranges.back().first <= cur_r) {
                    cur_r = max(cur_r, ranges.back().second);
                    tans -= ranges.back().second - ranges.back().first;
                    ranges.pop_back();
                }
                tans += cur_r - cur_l;
                ranges.push_back({cur_l, cur_r});
                ans += tans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
