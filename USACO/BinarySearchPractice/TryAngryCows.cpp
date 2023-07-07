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
    vector<int> needR(n), needL(n);
    needL[0] = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        int tmp = max(needL[i - 1], a[i] - a[i - 1]);
        while (a[i] - a[j] > tmp) j++;
        needL[i] = max(tmp, needL[j] + 1);
    }
    reverse(a.begin(), a.end());
    needR[0] = 0;
    j = 0;
    for (int i = 1; i < n; i++) {
        int tmp = max(needR[i - 1], a[i - 1] - a[i]);
        while (a[j] - a[i] > tmp) j++;
        needR[i] = max(tmp, needR[j] + 1);
    }
    reverse(a.begin(), a.end());
    reverse(needR.begin(), needR.end());
    double l = 0, r = 1e9 + 7, m, eps = 1e-2;
    while (r - l > eps) {
        m = (l + r) / 2;
        bool iok = false;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && a[j + 1] - a[i] < 2 * m + eps) j++;
            if (max(needL[i], needR[j]) + 1 < m + eps) {
                iok = true;
                break;
            }
        }
        if (iok)
            r = m;
        else
            l = m + eps;
    }
    cout << r << endl;

    return 0;
}