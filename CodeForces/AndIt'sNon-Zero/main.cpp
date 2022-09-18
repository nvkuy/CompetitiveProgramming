#include <bits/stdc++.h>

using namespace std;

int cnt[200002][33], p;

void itb(int n, int i) {
    if (n > 0) {
        cnt[i][30 - p] += (n % 2);
        p++;
        itb(n / 2, i);
    }
}

int main()
{
    memset(cnt[0], 0, sizeof(cnt[0]));
    for (int i = 1; i <= 2 * 1e5; i++) {
        memset(cnt[i], 0, sizeof(cnt[i]));
        p = 0;
        itb(i, i);
        for (int j = 1; j <= 30; j++)
            cnt[i][j] += cnt[i - 1][j];
    }
    int t, ans, l, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &l, &r);
        ans = -1;
        for (int i = 0; i <= 30; i++)
            ans = max(ans, cnt[r][i] - cnt[l - 1][i]);
        printf("%d\n", (r - l - ans + 1));
    }

    return 0;
}
