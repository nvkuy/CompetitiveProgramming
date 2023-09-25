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
        vector<int> a(n), ans(k + 1, 0);
        vector<vector<int>> color_pos(k + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            color_pos[a[i]].push_back(i);
        }
        int cur_l = 1e9, cur_r = -1e9;
        for (int i = k; i > 0; i--) {
            if (color_pos[i].size() == 0) continue;
            for (int pos : color_pos[i]) {
                cur_l = min(cur_l, pos);
                cur_r = max(cur_r, pos);
            }
            ans[i] = (cur_r - cur_l + 1) * 2;
        }
        for (int i = 1; i <= k; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
