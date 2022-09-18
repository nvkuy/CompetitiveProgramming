#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        if (a[0] == a[n - 1]) {
            cout << "-1\n";
            continue;
        }
        ans = 1;
        for (int i = 2e6; i >= 1; i--) {
            bool iok = true;
            for (int j = 0; j < n; j++) {
                if ((a[j] - a[0]) % i > 0) {
                    iok = false;
                    break;
                }
            }
            if (iok) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
