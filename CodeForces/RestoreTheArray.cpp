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
        vector<int> a(n - 1), ans;
        for (int i = 0; i + 1 < n; i++) cin >> a[i];
        for (int i = 0; i + 1 < n; i++) {
            if (i == ans.size()) {
                ans.push_back(a[i]);
                if (i + 2 < n && a[i + 1] > a[i])
                    ans.push_back(0);
                continue;
            }
            assert(ans.back() <= a[i]);
            if (ans.back() != a[i]) {
                ans.push_back(a[i]);
                continue;
            }
            if (i + 2 < n && a[i + 1] > a[i])
                ans.push_back(0);
        }
        if (ans.size() < n)
            ans.push_back(0);
        assert(ans.size() == n);
        for (auto num : ans) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
