#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        if ((n + m) % 2 == 0) {
            cout << "NO" << endl;
            continue;
        }
        vector<vector<pair<int, int>>> f(n, vector<pair<int, int>>(m, {1e9, -1e9}));
        f[0][0] = {a[0][0], a[0][0]};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    f[i][j].first = min(f[i][j].first, f[i - 1][j].first + a[i][j]);
                    f[i][j].second = max(f[i][j].second, f[i - 1][j].second + a[i][j]);
                }
                if (j > 0) {
                    f[i][j].first = min(f[i][j].first, f[i][j - 1].first + a[i][j]);
                    f[i][j].second = max(f[i][j].second, f[i][j - 1].second + a[i][j]);
                }
            }
        }
        cout << ((f[n - 1][m - 1].first <= 0 && f[n - 1][m - 1].second >= 0) ? "YES" : "NO") << endl;
    }

    return 0;
}
