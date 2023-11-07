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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> s(n), a(55);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            s[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> s[i][j];
                a[s[i][j]].push_back(i);
            }
        }
        int ans = 0;
        for (int i = 0; i <= 50; i++) {
            if (a[i].size() == 0) continue;
            vector<int> rm(n, 1);
            for (int id : a[i])
                rm[id] = 0;
            set<int> tans;
            for (int i = 0; i < n; i++) {
                if (!rm[i]) continue;
                for (int num : s[i])
                    tans.insert(num);
            }
            ans = max(ans, (int)tans.size());
        }
        cout << ans << endl;
    }

    return 0;
}
