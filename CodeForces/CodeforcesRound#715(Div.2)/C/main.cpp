#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    vector<vector<long long>> f(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        f[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            f[i][j] = min(f[i][j - 1], f[i + 1][j]) + a[j] - a[i];
        }
    }
    cout << f[0][n - 1];

    return 0;
}
