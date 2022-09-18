#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, c[505][505];
    long long ans;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
            for (int j = 0; j < 2 * n; j++)
                cin >> c[i][j];
        for (int i = n; i < 2 * n; i++)
            for (int j = n; j < 2 * n; j++)
                ans += c[i][j];
        ans += min(min(min(c[n - 1][n], c[n][n - 1]), min(c[2 * n - 1][n - 1], c[n - 1][2 * n - 1])),
                   min(min(c[0][n], c[n][0]), min(c[2 * n - 1][0], c[0][2 * n - 1])));
        cout << ans << endl;
    }

    return 0;
}
