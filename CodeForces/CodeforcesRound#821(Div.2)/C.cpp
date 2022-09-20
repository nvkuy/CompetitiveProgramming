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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<pair<int, int>> ans;
        if (a[0] != a[n - 1]) {
            ans.push_back({0, n - 1});
            if ((a[0] + a[n - 1]) % 2 == 1)
                a[n - 1] = a[0];
            else
                a[0] = a[n - 1];
        }
        for (int i = 1; i + 1 < n; i++) {
            if ((a[0] + a[i]) % 2 == 1) {
                ans.push_back({0, i});
                a[i] = a[0];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == a[0])
                continue;
            ans.push_back({i, i + 1});
            a[i] = a[i + 1];
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }

    return 0;
}