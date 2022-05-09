#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ans;
    cin >> n;
    vector<long long> a(n), b(n), ps;
    vector<vector<long long>> f(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ps.push_back(0);
    for (int i = 0; i < n; i++)
        ps.push_back(ps.back() + a[i] * b[i]);
    ans = ps[n];
    for (int i = 0; i < n; i++)
        f[i][i] = a[i] * b[i];
    for (int i = 1; i < n; i++) {
        f[i - 1][i] = a[i - 1] * b[i] + a[i] * b[i - 1];
        ans = max(ans, ps[n] - (ps[i + 1] - ps[i - 1]) + f[i - 1][i]);
    }
    for (int len = 2; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            f[i][j] = a[i] * b[j] + a[j] * b[i] + f[i + 1][j - 1];
            //cout << i << '|' << j << ':' << f[i][j] << endl;
            //cout << j << ':' << ps[j + 1] << endl;
            ans = max(ans, ps[n] - (ps[j + 1] - ps[i]) + f[i][j]);
        }
    }
    cout << ans;

    return 0;
}
