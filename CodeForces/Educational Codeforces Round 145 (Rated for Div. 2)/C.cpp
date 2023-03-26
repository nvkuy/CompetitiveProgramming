#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans(n, -1000);
        int cur_pos_sub_arr = 0;
        for (int i = 0; i < n; i++) {
            if (cur_pos_sub_arr + i + 1 > k) {
                int denta = cur_pos_sub_arr + i - k;
                ans[i] = -2 * denta - 1;
                break;
            }
            ans[i] = 2;
            cur_pos_sub_arr += (i + 1);
        }
        for (int ai : ans) cout << ai << ' ';
        cout << endl;
    }

    return 0;
}
