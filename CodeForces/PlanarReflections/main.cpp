#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k, mod = 1e9 + 7;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<vector<int>>> f(k + 1, vector<vector<int>>(n + 2, vector<int>(2, 0)));
        for (int i = 0; i <= n + 1; i++)
            f[1][i][0] = f[1][i][1] = 1;
        for (int i = 1; i <= k; i++)
            f[i][0][1] = f[i][n + 1][0] = 1;
        for (int i = 2; i <= k; i++) {
            for (int j = 1; j <= n; j++)
                f[i][j][0] = (f[i][j - 1][0] + f[i - 1][j - 1][1]) % mod;
            for (int j = n; j >= 1; j--)
                f[i][j][1] = (f[i][j + 1][1] + f[i - 1][j + 1][0]) % mod;
        }
        if (k > 1)
            f[k][n][0] = (f[k][n][0] + 1) % mod;
        cout << f[k][n][0] << endl;
    }

    return 0;
}
