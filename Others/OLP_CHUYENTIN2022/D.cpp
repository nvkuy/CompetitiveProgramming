#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, q, INF = 1e9;
    cin >> n >> m >> q;
    vector<vector<int>> c(n + 1, vector<int>(n + 1, INF)), dp;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        c[u][v] = min(c[u][v], w);
    }
    dp = c;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    while (q--) {
        cin >> u >> w;
        int ans = dp[1][u];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i][j] != INF) {
                    int s1 = dp[1][i], s2 = dp[j][u];
                    // if (i == 1) s1 = 0;
                    // if (j == u) s2 = 0;
                    ans = min(ans, s1 + s2 + w);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}