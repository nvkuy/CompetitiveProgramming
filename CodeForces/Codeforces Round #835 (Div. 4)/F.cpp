#include <bits/stdc++.h>
using namespace std;

int main() {

    long long t, n, c, d;
    cin >> t;
    while (t--) {
        cin >> n >> c >> d;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<long long>());
        if (a[0] * d < c) {
            cout << "Impossible" << endl;
            continue;
        }
        long long tmp = 0;
        for (int i = 0; i < min(d, (long long)a.size()); i++)
            tmp += a[i];
        if (tmp >= c) {
            cout << "Infinity" << endl;
            continue;
        }
        long long l = 0, r = d, m;
        while (l < r) {
            m = (l + r + 1) / 2;
            tmp = 0;
            for (int i = 0; i < min(m + 1, (long long)a.size()); i++) {
                long long tt = (d - i) / (m + 1);
                if ((d - i) % (m + 1) > 0)
                    tt++;
                tmp += (a[i] * tt);
            }
            // cout << m << '|' << tmp << endl; 
            if (tmp >= c)
                l = m;
            else
                r = m - 1;
        }
        cout << l << endl;
    }

    return 0;
}