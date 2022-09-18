#include <bits/stdc++.h>

using namespace std;

int f[1001][1001][2], a[1001][1001];
char tr[1001][1001];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j][0] = 0, f[i][j][1] = 0;
            while (a[i][j] % 2 == 0) {
                f[i][j][0]++;
                a[i][j] /= 2;
            }
            while (a[i][j] % 5 == 0) {
                f[i][j][1]++;
                a[i][j] /= 5;
            }
            if (i <= 1 && j <= 1)
                continue;
            if (i <= 1) {
                f[i][j][1] += f[i][j - 1][1];
                f[i][j][0] += f[i][j - 1][0];
                tr[i][j] = 'R';
                continue;
            }
            if (j <= 1) {
                f[i][j][1] += f[i - 1][j][1];
                f[i][j][0] += f[i - 1][j][0];
                tr[i][j] = 'D';
                continue;
            }

            if (f[i][j][1] > f[i][j][0]) {
                if (f[i - 1][j][0] > f[i][j - 1][0]) {
                    f[i][j][1] += f[i][j - 1][1];
                    f[i][j][0] += f[i][j - 1][0];
                    tr[i][j] = 'R';
                } else {
                    f[i][j][1] += f[i - 1][j][1];
                    f[i][j][0] += f[i - 1][j][0];
                    tr[i][j] = 'D';
                }
            } else {
                if (f[i - 1][j][1] > f[i][j - 1][1]) {
                    f[i][j][1] += f[i][j - 1][1];
                    f[i][j][0] += f[i][j - 1][0];
                    tr[i][j] = 'R';
                } else {
                    f[i][j][1] += f[i - 1][j][1];
                    f[i][j][0] += f[i - 1][j][0];
                    tr[i][j] = 'D';
                }
            }
        }
    }
    printf("%d\n", min(f[n][n][1], f[n][n][0]));
    int i = n, j = n;
    string ans;
    while (i > 1 || j > 1) {
        ans = tr[i][j] + ans;
        if (tr[i][j] == 'D')
            i--;
        else
            j--;
    }
    printf("%s", ans.c_str());

    return 0;
}
