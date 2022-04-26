#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test_input.txt", "r", stdin);
    //freopen("test_output.txt", "w", stdout);

    int n, m, u, v, q;
    long long cost;
    cin >> n >> m >> q;
    vector<vector<long long>> c(n + 1, vector<long long>(n + 1, 1e17));
    while (m--) {
        cin >> u >> v >> cost;
        c[u][v] = min(c[u][v], cost);
        c[v][u] = min(c[v][u], cost);
    }
    for (int i = 1; i <= n; i++)
        c[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    while (q--) {
        cin >> u >> v;
        cout << (c[u][v] < 1e17 ? c[u][v] : -1LL) << endl;
    }

    return 0;
}
