#include <bits/stdc++.h>
using namespace std;

long long cal(int num_ticket, int a, int x, int b, int y, vector<int> &p) {
    vector<int> contribute(num_ticket, 0);
    for (int i = 0; i < num_ticket; i++) {
        int j = i + 1;
        if (j % a == 0) contribute[i] += x;
        if (j % b == 0) contribute[i] += y;
    }
    sort(contribute.begin(), contribute.end(), greater<int>());
    long long res = 0;
    for (int i = 0; i < num_ticket; i++)
        res += ((p[i] / 100) * contribute[i]);
    return res;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y, a, b, k;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        sort(p.begin(), p.end(), greater<int>());
        cin >> x >> a >> y >> b >> k;
        if (cal(n, a, x, b, y, p) < k) {
            cout << -1 << endl;
            continue;
        }
        int l = 0, r = n, m;
        while (l < r) {
            m = (l + r) / 2;
            if (cal(m, a, x, b, y, p) >= k)
                r = m;
            else
                l = m + 1;
        }
        cout << r << endl;
    }

    return 0;
}