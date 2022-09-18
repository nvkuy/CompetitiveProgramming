#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> f(n + 1, 0), maxl(n + 1);
        for (int i = 1; i <= n; i++)
            f[i] = f[i - 1] + a[i - 1];
        for (int l = 0; l <= n; l++) {
            int ml = -1e9;
            for (int i = 0; i <= n - l; i++)
                ml = max(ml, f[i + l] - f[i]);
            maxl[l] = ml;
            //cout << maxl[l] << ' ';
        }
        //cout << endl;
        int ml = 0, ans;
        for (int k = 0; k <= n; k++) {
            ans = ml;
            for (int l = k; l <= n; l++)
                ans = max(ans, maxl[l] + (k * x));
            ml = max(ml, ans);
            cout << ans << ' ';
        }
        cout << endl;
    }

    return 0;
}
