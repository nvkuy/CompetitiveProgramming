#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, k, wsi, ws, d[505], a[505], f[505][505];
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    d[n] = l, a[n] = -1e9 - 7;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0) {
                f[i][j] = 0;
                //cout << f[i][j] << ' ';
                continue;
            }
            f[i][j] = f[i - 1][j] + ((d[i] - d[i - 1]) * a[i - 1]);
            for (int k = 1; k <= min(i - 1, j); k++)
                f[i][j] = min(f[i][j], f[i - k][j - k] + ((d[i] - d[i - k]) * a[i - k - 1]));
            //cout << f[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << f[n][k];

    return 0;
}
