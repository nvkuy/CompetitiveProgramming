#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<vector<int>> f(2e5 + 1, vector<int>(10));
    int t, n, m, mod = 1e9 + 7;
    for (int i = 0; i < 10; i++)
        f[0][i] = 1;
    for (int i = 1; i <= 2e5; i++) {
        for (int j = 0; j < 10; j++) {
            if (i >= 10 - j)
                f[i][j] = (f[i - 10 + j][0] + f[i - 10 + j][1]) % mod;
            else
                f[i][j] = f[i - 1][j + 1];
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = 0;
        while (n > 0) {
            ans = (ans + f[m][n % 10]) % mod;
            n /= 10;
        }
        cout << ans << endl;
    }

    return 0;
}
