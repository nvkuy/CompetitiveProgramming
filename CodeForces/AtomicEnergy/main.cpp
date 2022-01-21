#include <bits/stdc++.h>

using namespace std;

long long inf = 1e18 + 14, f[100000003];
long long a[103], mq = 1e8;

int main()
{

    int n, q, k;
    scanf("%d %d", &n, &q);
    memset(f, 0, sizeof(f));
    a[0] = 0, f[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i] = a[i];
    }
    for (int i = n + 1; i <= mq; i++) {
        f[i] = inf;
        for (int j = 1; j <= n; j++)
            f[i] = min(f[i], (long long)(f[i - j] + a[j]));
    }
    while (q--) {
        scanf("%d", &k);
        printf("%lld\n", f[k]);
    }

    return 0;
}
