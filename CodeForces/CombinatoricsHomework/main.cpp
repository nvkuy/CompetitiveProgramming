#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, m, maxp, minp;
    vector<int> a(3);
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2] >> m;
        sort(a.begin(), a.end());
        maxp = a[0] + a[1] + a[2] - 3, minp = 0;
        if (a[2] > a[0] + a[1] + 1) {
            a[2] -= (a[0] + a[1]);
            minp += (a[2] - 1);
            a[0] = 0, a[1] = 0;
        }
        if (a[0] + a[1] > a[2] + 1) {
            int tmp = a[1] - a[0];
            a[1] -= min(tmp, a[2]);
            a[2] -= min(tmp, a[2]);
            if (a[2] > 0) {
                tmp = a[2] / 2;
                a[1] -= (a[2] % 2);
                a[1] -= tmp;
                a[0] -= tmp;
            }
            minp += max(abs(a[0] - a[1]) - 1, 0);
        }
        //cout << minp << ' ' << maxp << endl;
        if (m >= minp && m <= maxp)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
