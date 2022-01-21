#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, a[101];
    bool dd[101], ic;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dd, false, sizeof(dd));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            while (a[i] > n)
                a[i] /= 2;
        }
        sort(a, a + n);
        ic = true;
        for (int i = 0; i < n; i++) {
            if (dd[a[i]]) {
                while (dd[a[i]] & a[i] > 0)
                    a[i] /= 2;
                if (a[i] <= 0) {
                    ic = false;
                    break;
                }
            }
            dd[a[i]] = true;
        }
        cout << (ic ? "YES\n" : "NO\n");
    }

    return 0;
}
