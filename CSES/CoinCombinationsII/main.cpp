#include <bits/stdc++.h>

using namespace std;

int f[101][1000001];

int main()
{
    int n, x, m = 1e9 + 7, c[101];
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        f[i][0] = 1;
    }
    memset(f, 0, (x + 1) * sizeof *f[0]);
    f[0][0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            f[j][i] = f[j - 1][i];
            if (c[j] <= i)
                f[j][i] = (f[j][i] + f[j][i - c[j]]) % m;
        }
    }
    printf("%d\n", f[n][x]);

    return 0;
}
