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
        if (a.back() != 0) {
            cout << "NO" << endl;
            continue;
        }
        int one_cnt = 0;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 0) {
                one_cnt = 0;
                continue;
            }
            one_cnt++;
            if (i == 0 || a[i - 1] == 0) ans[i] = one_cnt;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        for (auto num : ans) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
