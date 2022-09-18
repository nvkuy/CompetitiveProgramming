#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, c;
    long long ans, a[17];
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0, c = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            while (a[i] % 2 == 0) {
                c++;
                a[i] /= 2;
            }
        }
        sort(a, a + n);
        while (c > 0) {
            a[n - 1] *= 2;
            c--;
        }
        for (int i = 0; i < n; i++)
            ans += a[i];
        cout << ans << endl;
    }

    return 0;
}
