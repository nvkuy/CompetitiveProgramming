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
        vector<int> a(n), pos(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int cur_mex = 0, cur_l = n, cur_r = -1;
        int i = 0;
        long long ans = 0;
        while (true) {
            if (i == n) break;
            cur_l = min(cur_l, pos[i]);
            cur_r = max(cur_r, pos[i]);
            while (i < n && cur_l <= pos[i] && cur_r >= pos[i]) {
                i++;
                cur_mex++;
            }
            if (i == n) {
                ans++;
                continue;
            }
            int next_pos = pos[i], sp1 = cur_l - next_pos - 1, sp2 = n - cur_r - 1, tsp = 2 * cur_mex - (cur_r - cur_l + 1);
            if (next_pos > cur_r)
                sp1 = next_pos - cur_r - 1, sp2 = cur_l;
            if (tsp < 0) continue;
            // cout << sp1 << ' ' << sp2 << ' ' << tsp << endl;
            for (int j = 0; j <= min(sp1, tsp); j++) ans += min(sp2 + 1, tsp - j + 1);
        }
        cout << ans << endl;
    }

    return 0;
}
