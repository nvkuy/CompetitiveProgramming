#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, d, mina, cm, pmin, ans;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        vector<int> a(n), delt(n);
        mina = 1e9 + 7, cm = 0, pmin = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0)
                delt[i] = a[i] - a[i - 1];
            else
                delt[i] = a[0];
            mina = min(mina, delt[i]);
        }
        for (int i = 0; i < n; i++) {
            if (delt[i] == mina) {
                cm++;
                if (i == 0 || cm <= 1)
                    continue;
                if (delt[i - 1] != mina)
                    cm++;
                else
                    pmin = i - 1;
            }
        }
        if (cm > 2) {
            cout << mina << endl;
            continue;
        }
        if (pmin == -1) {
            for (int i = 0; i < n; i++) {
                if (delt[i] == mina) {
                    pmin = i;
                    break;
                }
            }
        }
        ans = mina;
        for (int i = 1; i < n; i++) {
            int l = i, r = i - 1;
            if (l == pmin)
                l--;
            if (r == pmin)
                r++;
            delt[i] = a[r] - a[l];
            ans = max(ans, (delt[i] - 1) / 2);
        }
        int i = n - 1;
        if (i == pmin)
            i--;
        ans = max(ans, d - a[i] - 1);

        cout << ans << endl;
    }

    return 0;
}
