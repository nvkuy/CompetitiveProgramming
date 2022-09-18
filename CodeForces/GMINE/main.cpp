#include <bits/stdc++.h>

using namespace std;

int a[3001], b[3001], f[3001][3001];

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    for (int i = 0; i <= n; i++)
        f[i][0] = 0;
    for (int i = 0; i <= t; i++)
        f[0][i] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i])
                f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + b[i]);
        }
    }
    int ans = f[n][t], rmm = 0;
    bool gm[3001], ic = true;
    memset(gm, false, sizeof(gm));
    int i = n, j = t;
    while (f[i][j] > 0) {
        if (f[i - 1][j - a[i]] + b[i] == f[i][j]) {
            if (j >= a[i]) {
                gm[i] = true;
                j = j - a[i];
            }
        }
        i = i - 1;
    }
    if (j == 0)
        ic = false;
    for (int i = 1; i <= n; i++) {
        if (!gm[i])
            rmm = max(rmm, b[i]);
        //else
            //cout << i << " ";
    }
    //cout << endl;

    if (ic)
        cout << ans + rmm;
    else
        cout << ans;

    return 0;
}
