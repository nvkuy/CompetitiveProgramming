#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n, ans, rs = 2e4 + 3;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n + 1), b(n + 1), ps(n + 1);
        vector<vector<long long>> f(n + 1, vector<long long>(rs + 1, 1e12));
        ps[0] = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += (n - 1) * (a[i] * a[i]);
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            ans += (n - 1) * (b[i] * b[i]);
        }
        //cout << ans << endl;
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + a[i] + b[i];
        f[n][a[n]] = f[n][b[n]] = 0;
        for (int i = n - 1; i > 0; i--) {
            long long s = ps[n] - ps[i];
            for (int j = 0; j < (rs / 2); j++) {
                f[i][b[i] + j] = min(f[i][b[i] + j], f[i + 1][j] + b[i] * j * 2 + (s - j) * a[i] * 2);
                f[i][a[i] + j] = min(f[i][a[i] + j], f[i + 1][j] + a[i] * j * 2 + (s - j) * b[i] * 2);
            }
            /*
            vector<long long> tmp = f[i];
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < 6; j++)
                cout << tmp[j] << ' ';
            cout << endl;
            */
        }
        sort(f[1].begin(), f[1].end());
        ans += f[1][0];
        cout << ans << endl;
    }

    return 0;
}
