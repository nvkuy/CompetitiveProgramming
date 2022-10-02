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

    int n, m, a, b, inf = 1e9;
    cin >> m >> n;
    vector<vector<long long>> c(n + 1, vector<long long>(m + 1, 0)), ps = c;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == -1)
                c[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + c[i][j];
    long long ans = 1e18;
    for (int i = 1; i + b - 1 <= n; i++) {
        for (int j = 1; j + a - 1 <= m; j++) {
            int x = i + b - 1, y = j + a - 1;
            long long tans = ps[x][y] - ps[x - b][y] - ps[x][y - a] + ps[x - b][y - a];
            ans = min(ans, tans);
        }
    }
    cout << ans << endl;

    return 0;
}
