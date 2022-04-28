#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k, f[55][3025], mod = 998244353, ans = 0;
    cin >> n >> m >> k;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= k; s++) {
            f[i][s] = 0;
            for (int j = 1; j <= min(s, m); j++)
                f[i][s] = (f[i][s] + f[i - 1][s - j]) % mod;
        }
    }
    for (int i = 0; i <= k; i++) {
        ans = (ans + f[n][i]) % mod;
        //cout << f[n][i] << ' ';
    }
    //cout << endl;
    cout << ans;

    return 0;
}
