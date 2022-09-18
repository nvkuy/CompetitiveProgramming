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

    int t, n, m, u, v, cake;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cake = m;
        vector<int> a(n + 1);
        vector<vector<int>> c(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        while (m--) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        int ans = (cake % 2 == 0 ? 0 : 1e9);
        for (int i = 1; i <= n; i++) {
            //cout << "@" << c[i].size() << endl;
            if ((cake - c[i].size()) % 2 == 0) {
                ans = min(ans, a[i]);
                continue;
            }
            for (int j : c[i]) {
                if ((cake - c[j].size()) % 2 == 1)
                    ans = min(ans, a[i] + a[j]);
            }
        }
        // cout << "ANS: ";
        cout << ans << endl;
    }

    return 0;
}