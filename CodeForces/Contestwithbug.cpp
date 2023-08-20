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

    int n, k, mod = 24 * 60;
    cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int solve = 0, rm = k;
    sort(a.begin(), a.end());
    for (auto p : a) {
        if (rm < p) break;
        rm -= p;
        solve++;
    }

    int ans = mod - 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (bit_cnt(mask) != solve) continue;
        vector<int> problems;
        int need_time = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                problems.push_back(i);
                need_time += a[i];
            }
        }
        if (need_time > k) continue;
        do {
            int pen = 0, cur = 0;
            for (int i = 0; i < problems.size(); i++) {
                cur += a[problems[i]];
                pen += cur;
                pen %= mod;
            }
            ans = min(ans, pen);
        } while (next_permutation(problems.begin(), problems.end()));
    }
    cout << solve << ' ' << ans << endl;

    return 0;
}
