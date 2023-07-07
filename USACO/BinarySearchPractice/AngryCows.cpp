#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("angry.in", "r")) {
        freopen("angry.in", "r", stdin);
        freopen("angry.out", "w", stdout);
    }

    cout << setprecision(1) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    double l = 0, r = 1e9 + 7, m, dt = 1e-2;
    while (r - l > dt) {
        m = (l + r) / 2;
        int ll = 0, rr = n - 1, mm;
        while (ll < rr) {
            mm = (ll + rr + 1) / 2;
            int p1 = mm, p2 = p1;
            double r = m - 1;
            while (true) {
                if (p1 == 0) break;
                if (a[p1] > a[p2]) {
                    p1--;
                    continue;
                }
                if (r + dt < 1) break;
                double next_pos = a[p2] - r;
                if (p2 > 0 && a[p2 - 1] < next_pos + dt) break;
                while (p2 > 0 && a[p2 - 1] > next_pos + dt) p2--;
                r--;
            }
            if (p1 > 0)
                rr = mm - 1;
            else
                ll = mm;
        }
        double ra = m - 1;
        int p1 = ll, p2 = ll;
        while (p2 + 1 < n && a[p2 + 1] < a[ll] + 2.0 * m + dt) p2++;
        p1 = p2;
        while (true) {
            if (p1 == n - 1) break;
            if (a[p1] < a[p2]) {
                p1++;
                continue;
            }
            if (ra + dt < 1) break;
            double next_pos = a[p2] + ra;
            if (p2 + 1 < n && a[p2 + 1] + dt > next_pos) break;
            while (p2 + 1 < n && a[p2 + 1] + dt < next_pos) p2++;
            ra--;
        }
        if (p1 == n - 1)
            r = m;
        else
            l = m + dt;
    }
    cout << r << endl;

    return 0;
}