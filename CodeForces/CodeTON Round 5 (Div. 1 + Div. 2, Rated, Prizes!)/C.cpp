#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

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
        vector<int> a(n + 1, 0);
        vector<vector<pair<int, int>>> best(n + 1, vector<pair<int, int>>(2, {1e9, 0}));
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            pair<int, int> pre_best_free = best[a[i]][0];
            pair<int, int> pre_best_not_free = best[a[i]][1];
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            if (i - f[i][0] < best[a[i]][0].first)
                best[a[i]][0] = {i - f[i][0], i};
            if (pre_best_free.second == 0 && pre_best_not_free.second == 0) {
                f[i][1] = -1e9;
                continue;
            }
            int ans1 = -1e9, ans2 = -1e9;
            if (pre_best_free.second != 0)
                ans1 = i - pre_best_free.second + 1 + f[pre_best_free.second][0];
            if (pre_best_not_free.second != 0)
                ans2 = i - pre_best_not_free.second + max(f[pre_best_not_free.second - 1][0], f[pre_best_not_free.second - 1][1]);
            f[i][1] = max(ans1, ans2);
            if (i - f[i][1] < best[a[i]][1].first)
                best[a[i]][1] = {i - f[i][1], (f[i][1] == ans1 ? pre_best_free.second : pre_best_not_free.second)};
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }

    return 0;
}
