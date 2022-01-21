#include <bits/stdc++.h>

using namespace std;

int c[101], f[1000001];

int main()
{
    int n, x, m = 1e9 + 7;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    //sort(c, c + n);
    memset(f, 0, (x + 1) * sizeof *f);
    f[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j] <= i)
                f[i] = (f[i] + f[i - c[j]]) % m;
        }
        //cout << f[i] << endl;
    }
    printf("%d", f[x]);

    return 0;
}
