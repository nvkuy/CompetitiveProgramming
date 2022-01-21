#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, l, r, a[101], k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &l, &r, &k);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (k >= a[i]) {
                if (a[i] > r)
                    break;
                if (a[i] < l)
                    continue;
                k -= a[i];
                ans++;
            } else
                break;
        }
        printf("%d\n", ans);
    }

    return 0;
}
