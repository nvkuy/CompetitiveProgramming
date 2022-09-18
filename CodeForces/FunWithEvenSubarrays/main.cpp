#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = n - 2, c = 1;
        while (i >= 0) {
            if (a[i] != a[i + 1])
                break;
            i--;
            c++;
        }
        int ans = 0;
        reverse(a.begin(), a.end());
        while (c < n) {
            for (int i = c; i < min(2 * c, n); i++) {
                if (a[i] != a[0]) {
                    ans++;
                    break;
                }
            }
            c *= 2;
            while (c < n) {
                if (a[c] != a[0])
                    break;
                c++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
