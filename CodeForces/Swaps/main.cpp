#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, v, ans, f[100001], a[200002];
    cin >> t;
    while (t--) {
        cin >> n;
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            cin >> v;
            a[v] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> v;
            a[v] = i;
        }
        ans = 1e8;
        for (int i = 2; i <= (2 * n); i += 2) {
            if (i <= 2)
                f[i / 2] = a[i - 1];
            else
                f[i / 2] = min(f[(i / 2) - 1], a[i - 1]);
            ans = min(ans, f[i / 2] + a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
