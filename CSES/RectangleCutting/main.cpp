#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, f[505][505];
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                f[i][j] = 0;
                continue;
            }
            if (i == 1 || j == 1) {
                f[i][j] = max(i, j) - 1;
                continue;
            }
            f[i][j] = 1e9 + 7;
            for (int k = 1; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[i][j - k] + 1);
            for (int k = 1; k < i; k++)
                f[i][j] = min(f[i][j], f[k][j] + f[i - k][j] + 1);
        }
    }
    /*
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    */
    cout << f[a][b];

    return 0;
}
