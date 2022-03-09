#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, d, mina, cm, pmin, ans;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        vector<int> a(n);
        deque<int> delt;
        mina = 1e9 + 7, cm = 0, pmin;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0) {
                delt.push_back(a[i] - a[i - 1]);
                mina = min(mina, delt[i - 1]);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (delt[i] == mina) {
                cm++;
                if (i == 0 || cm <= 1)
                    continue;
                if (delt[i - 1] != mina)
                    cm++;
                else
                    pmin = i;
            }
        }
        if (cm > 2) {
            cout << mina << endl;
            continue;
        }
        ans = mina;
        for (int i = 0; i < n - 1; i++)
            ans = max(ans, delt[i] / 2);
        cout << ans << endl;
    }

    return 0;
}
