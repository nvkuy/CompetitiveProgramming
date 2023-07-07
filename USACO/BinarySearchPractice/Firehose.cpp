#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;

    sort(a.begin(), a.end());
    int end_point = 0;
    for (int i = 1; i < n; i++) {
        if (a[end_point + 1] - a[end_point] < a[i] - a[i - 1])
            end_point = i - 1;
    }
    long long mod = 1e6;
    if (n > 1 && (mod + a[0] - a[n - 1]) < a[end_point + 1] - a[end_point]) {
        vector<long long> tmp;
        for (int i = end_point + 1; i < n; i++)
            tmp.push_back(a[i]);
        for (int i = 0; i <= end_point; i++)
            tmp.push_back(a[i] + mod);
        a = tmp;
    }

    long long l = 0, r = 1e9, m;
    while (l < r) {
        m = (l + r) / 2;
        long long cur_pos = a[0] + 2 * m, rm = k - 1;
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] <= cur_pos) continue;
            if (rm == 0) {
                iok = false;
                break;
            }
            cur_pos = a[i] + 2 * m;
            rm--;
        }
        if (iok)
            r = m;
        else
            l = m + 1;
    }
    cout << r << endl;

    return 0;
}