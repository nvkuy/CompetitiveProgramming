#include <bits/stdc++.h>

using namespace std;

bool check(int wi, int ai, int bi, int ci) {
    if (wi == 1)
        return (ai == bi && ai == ci && bi == ci);
    if (wi == 2) {
        if (ai == bi)
            return (2 * ai > ci);
        if (bi == ci)
            return (2 * bi > ai);
        if (ci == ai)
            return (2 * ai > bi);
    }
    if (wi == 3)
        return ((ai + bi > ci) && (ai + ci > bi) && (bi + ci > ai));
}

int main()
{

    int t, w, n, a[1001], b[1001], c[1001], ans;
    scanf("%d", &t);
    while (t--) {
        cin >> n >> w;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (w, a[i], b[i], c[i])
                        ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
