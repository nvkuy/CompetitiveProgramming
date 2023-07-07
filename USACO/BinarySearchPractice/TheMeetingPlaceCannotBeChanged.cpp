#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << setprecision(9) << fixed;
    int n;
    cin >> n;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    long double l = 0, r = 1e9 + 7, m, eps = 1e-9;
    while (r - l > eps) {
        m = (l + r) / 2;
        pair<long double, long double> meet_range = {-1e18, 1e18};
        for (int i = 0; i < n; i++) {
            meet_range.first = max(meet_range.first, x[i] - m * v[i]);
            meet_range.second = min(meet_range.second, x[i] + m * v[i]);
        }
        if (meet_range.second - meet_range.first > eps)
            r = m;
        else
            l = m + eps;
    }
    cout << r << endl;

    return 0;
}