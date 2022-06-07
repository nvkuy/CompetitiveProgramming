#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    reverse(a.begin(), a.end());
    vector<vector<int>> f(n, vector<int>(m + 1, 1e5));
    f[0][a[0]] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = a[i]; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                int op = j - a[i];
                if (k - op >= 0 && k - op <= j)
                    f[i][j] = min(f[i][j], f[i - 1][k - op] + op);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    int ans = 1e5;
    for (int i = 0; i <= m; i++)
        ans = min(ans, f[n - 1][i]);
    cout << ans;

    return 0;
}
