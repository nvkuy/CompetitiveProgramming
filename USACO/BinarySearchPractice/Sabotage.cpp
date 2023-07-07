#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("sabotage.in", "r")) {
        freopen("sabotage.in", "r", stdin);
        freopen("sabotage.out", "w", stdout);
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    double ss = 0;
    for (int i = 0; i < n; i++) ss += a[i];
    double l = 0, r = 1e12, m, dt = 1e-6;
    while (r - l > dt) {
        m = (l + r) / 2;
        bool iok = true;
        double best = a[1] - m, cur = 0;
        for (int i = 1; i + 1 < n; i++) {
            if (cur < 0)
                cur = 0;
            cur += (a[i] - m);
            best = max(best, cur);
        }
        if (ss - (m * n) > best)
            iok = false;
        if (iok)
            r = m;
        else
            l = m + dt;
    }
    cout << setprecision(3) << fixed;
    cout << r << endl;

    return 0;
}