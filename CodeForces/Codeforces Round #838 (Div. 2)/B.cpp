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

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> a, ans;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            a.push_back({tmp, i});
        }
        int p2 = 1;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            while (p2 < a[i].first)
                p2 *= 2;
            ans.push_back({a[i].second, p2 - a[i].first});
        }
        cout << ans.size() << endl;
        for (auto p : ans)
            cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
