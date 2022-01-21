#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test_input.txt", "r", stdin);
    int n, m, mod = 1e9 + 7, ai;
    cin >> n >> m;
    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, 0LL));
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        if (ai > 0) {
            if (i == 1) {
                f[i][ai] = 1;
                continue;
            }
            f[i][ai] = f[i - 1][ai];
            if (ai > 1)
                f[i][ai] += f[i - 1][ai - 1];
            if (ai < m)
                f[i][ai] += f[i - 1][ai + 1];
            f[i][ai] = f[i][ai] % mod;
        } else {
            if (i == 1) {
                for (int j = 1; j <= m; j++)
                    f[i][j] = 1;
                continue;
            }
            f[i][1] = (f[i - 1][1] + f[i - 1][2]) % mod;
            f[i][m] = (f[i - 1][m] + f[i - 1][m - 1]) % mod;
            for (int j = 2; j < m; j++)
                f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1] + f[i - 1][j]) % mod;
        }
    }
    long long ans = 0LL;
    for (int i = 1; i <= m; i++) {
        ans += f[n][i];
        //cout << f[n][i] << ' ';
    }
    //cout << endl;
    cout << ans % mod << endl;

    return 0;
}
