#include <bits/stdc++.h>

using namespace std;

int n, x, c[101], f[1000001][101];

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        f[0][i] = 0;
    }
    f[0][0] = 0;
    for (int i = 1; i <= x; i++)
        f[i][0] = 1e9 + 7;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i][j - 1];
            if (i >= c[j])
                f[i][j] = min(f[i][j], f[i - c[j]][j] + 1);
            //cout << f[i][j] << ' ';
        }
        //cout << '\n';
    }
    if (f[x][n] == 1e9 + 7)
        f[x][n] = -1;
    cout << f[x][n];

    return 0;
}
