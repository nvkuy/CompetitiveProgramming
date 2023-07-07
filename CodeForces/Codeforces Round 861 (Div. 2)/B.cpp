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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                cin >> c[i][j];
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            vector<long long> ps(n + 1, 0), tmp(n + 1, 0);
            for (int j = 0; j < n; j++)
                tmp[j] = c[j][i];
            sort(tmp.begin(), tmp.end());
            for (int j = 1; j <= n; j++)
                ps[j] = ps[j - 1] + tmp[j];
            for (long long j = 1; j <= n; j++) {
                ans += (ps[n] - ps[j] - 1LL * (n - j) * tmp[j]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
