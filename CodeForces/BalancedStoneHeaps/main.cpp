#include <bits/stdc++.h>

using namespace std;

int n, h[200002], sh[200002];

bool check(int mh) {
    memset(sh, 0, n * sizeof *sh);
    int d;
    for (int i = n - 1; i >= 2; i--) {
        if (h[i] + sh[i] < mh)
            return false;
        d = (min((h[i] - mh + sh[i]), h[i])) / 3;
        sh[i - 1] += d;
        sh[i - 2] += (2 * d);
    }
    return ((h[0] + sh[0] >= mh) && (h[1] + sh[1] >= mh));
}

int main()
{

    int t, hma;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &h[i]);
            hma = max(hma, h[i]);
        }
        int lo = 0, hi = hma + 1, mi;
        while (lo < hi) {
            mi = lo + (hi - lo + 1) / 2;
            if (check(mi))
                lo = mi;
            else
                hi = mi - 1;
        }
        printf("%d\n", lo);
    }

    return 0;
}
