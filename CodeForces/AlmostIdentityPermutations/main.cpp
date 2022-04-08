#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<long long>> f(n + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        f[i][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i - 1][j - 1];
            if (i >= j)
            f[i][j] += (f[i - 1][j] * (i - j));
        }
    }
    long long ans = 0;
    for (int i = n - k; i <= n; i++)
        ans += f[n][i];
    cout << ans;

    return 0;
}
