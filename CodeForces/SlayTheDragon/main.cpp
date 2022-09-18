#include <bits/stdc++.h>

using namespace std;

long long n, a[200002], s, m;

int main()
{
    scanf("%lld", &n);
    s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s += a[i];
    }
    sort(a, a + n);
    scanf("%lld", &m);
    long long j, c, x, y;
    while (m--) {
        scanf("%lld %lld", &x, &y);
        j = lower_bound(a, a + n, x) - a;
        c = 0;
        if (j >= n)
            c = x - a[n - 1] + max(0LL, y - s + a[n - 1]);
        else {
            c = max((x - a[j]), 0LL) + max(0LL, y - s + a[j]);
            if (j - 1 >= 0)
                c = min(c, (x - a[j - 1]) + max(0LL, y - s + a[j - 1]));
        }
        printf("%lld\n", c);
    }

    return 0;
}
