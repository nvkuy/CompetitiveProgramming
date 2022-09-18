#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        int ma = -1, j = n - 1, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[j] == ma)
                break;
            if (a[i] > a[j]) {
                j = i;
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
