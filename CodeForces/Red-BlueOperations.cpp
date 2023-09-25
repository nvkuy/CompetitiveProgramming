#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int n, q;
    // cin >> n >> q;
    // map<int, int> cnt;
    // for (int i = 0; i < n; i++) {
    //     int ai;
    //     cin >> ai;
    //     cnt[ai]++;
    // }

    // while (q--) {
    //     int k, ans = -1e9;
    //     cin >> k;
    //     if (k < cnt.begin()->second) { // can it lift all min?
    //         ans = cnt.begin()->first;
    //         goto PrintAns;
    //     }
    //     k -= cnt.begin()->second;
    //     if (k % 2) { // if lift all min and remain even => can use all remain operation on any element
    //         ans = cnt.begin()->first + 1;
    //         goto PrintAns;
    //     }
    //     if (cnt.size() == 1) { // otherwise it need to lift something else => can't only have one type element
    //         ans = cnt.begin()->first;
    //         goto PrintAns;
    //     }
    //     ans = cnt.begin()->first + 1; // lift something else => ok
    //     PrintAns:
    //         cout << ans << ' ';
    // }
    // cout << endl;

    // int n, q;
    // cin >> n >> q;
    // vector<pair<int, int>> a;
    // vector<int> f(n + 1, 0);
    // int init_max = 0;
    // for (int i = 0; i < n; i++) {
    //     int ai;
    //     cin >> ai;
    //     a.push_back({ai, i + 1});
    //     init_max = max(init_max, ai);
    // }
    // sort(a.begin(), a.end());
    // multiset<int> init;
    // for (int i = 0; i < n; i++) init.insert(a[i].first);
    // f[0] = *init.begin();
    // for (int i = 1; i <= n; i++) {
    //     init.erase(init.lower_bound(a[i - 1].first));
    //     init.insert(a[i - 1].first + a[i - 1].second);
    //     f[i] = *init.begin();
    // }

    // while (q--) {
    //     int k;
    //     cin >> k;
    //     if (k <= n) {
    //         cout << f[k] << ' ';
    //         continue;
    //     }
    //     int rm = (k - n) % 2;
    //     if (!rm) {
    //         cout << f[n] << ' ';
    //         continue;
    //     }
    //     cout << min(init_max, f[n]) << ' ';
    // }
    // cout << endl;

    return 0;
}
