#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        if (n == 4 && k == 3) {
            printf("-1\n");
            continue;
        }
        vector<bool> dd(n, false);
        if (k == n - 1) {
            dd[n - 2] = dd[n - 1] = true;
            printf("%d %d\n", n - 2, n - 1);
            dd[0] = dd[2] = true;
            printf("%d %d\n", 0, 2);
            dd[n - 3] = dd[1] = true;
            printf("%d %d\n", 1, n - 3);
        }
        if (k > 0 && k < n - 1) {
            dd[k] = dd[n - 1] = true;
            printf("%d %d\n", k, n - 1);
            dd[0] = dd[n - 1 - k] = true;
            printf("%d %d\n", 0, n - 1 - k);
        }
        for (int i = 0; i < n; i++) {
            if (!dd[i]) {
                printf("%d %d\n", i, n - i - 1);
                dd[i] = dd[n - i - 1] = true;
            }
        }
    }

    return 0;
}
