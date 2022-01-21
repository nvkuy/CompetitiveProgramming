#include <bits/stdc++.h>

using namespace std;

long long t, n, ai, ans, ddd[200002], dda[200002];

int main()
{

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        memset(ddd, 0, sizeof(ddd));
        memset(dda, 0, sizeof(dda));
        ans = 0;
        for (long long i = 0; i < n; i++) {
            scanf("%lld", &ai);
            if (ai - i < 0) {
                ans += dda[i - ai];
                dda[i - ai]++;
                continue;
            }
            ans += ddd[ai - i];
            ddd[ai - i]++;
            //cout << i << "|" << ai << "|" << ans << endl;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
