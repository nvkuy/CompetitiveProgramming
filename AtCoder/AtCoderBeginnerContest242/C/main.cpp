#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, mod = 998244353, ans = 0;
    cin >> n;
    vector<vector<long long>> f(n + 1, vector<long long>(10, 0));
    for (int i = 1; i < 10; i++)
        f[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 10; j++) {
            f[i][j] = f[i - 1][j];
            if (j - 1 > 0)
                f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mod;
            if (j + 1 < 10)
                f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
        }
    }
    for (int i = 1; i < 10; i++)
        ans = (ans + f[n][i]) % mod;
    cout << ans;

    return 0;
}
