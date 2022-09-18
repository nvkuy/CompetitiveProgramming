#include <bits/stdc++.h>

using namespace std;

int a[200002], dd[400004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dd, -1, (2 * n + 2) * sizeof *dd);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dd[a[i]] = i;
        }
        long long co = 0LL;
        for (int i = 1; i <= n; i++) {
            int j = 1;
            while (j * a[i] <= 2 * n) {
                if ((a[i] * j == i + dd[j]) && (i < dd[j]))
                    co++;
                j++;
            }
        }
        cout << co << endl;
    }

    return 0;
}
