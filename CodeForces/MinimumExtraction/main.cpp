#include <bits/stdc++.h>

using namespace std;

long long ans, a[200002];
//long long d[200002];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        sort(a, a + n);
        ans = a[0];
        /*
        memset(d, 0, sizeof(d));
        d[0] = a[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, a[i] - d[i - 1]);
            d[i] = a[i] + d[i - 1];
        }
        */
        for (int i = 1; i < n; i++)
            ans = max(ans, a[i] - a[i - 1]);
        printf("%lld\n", ans);
    }

    return 0;
}
