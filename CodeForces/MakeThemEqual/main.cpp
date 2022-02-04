#include <bits/stdc++.h>

using namespace std;

int cost[1001], b[1001], f[1000001];

int main()
{
    int t, n, k, ai;
    memset(cost, 0x3f, sizeof(cost));
    cost[1] = 0;
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + (i / j) < 1001)
                cost[i + (i / j)] = min(cost[i + (i / j)], cost[i] + 1);
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        memset(f, 0, (k + 1) * sizeof *f);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            b[i] = cost[b[i]];
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ai);
            for (int j = k; j >= b[i]; j--)
                f[j] = max(f[j], f[j - b[i]] + ai);
        }
        printf("%d\n", f[k]);
    }

    return 0;
}
