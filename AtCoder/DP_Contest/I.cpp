#include <bits/stdc++.h>
using namespace std;

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

    // debugLocal();

    int n;
    cin >> n;
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<vector<double>> f(n + 1, vector<double>(n + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j] * p[i];
            if (j > 0)
                f[i][j] += (f[i - 1][j - 1] * (1.0 - p[i]));
        }
    }
    double ans = 0;
    for (int i = 0; i <= n / 2; i++)
        ans += f[n][i];
    cout << setprecision(11) << fixed;
    cout << ans << endl;

    return 0;
}