#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans++;
                if (i == n - 2)
                    a[i + 1] = a[i];
                else
                    a[i + 1] = max(a[i], a[i + 2]);
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }

    return 0;
}
