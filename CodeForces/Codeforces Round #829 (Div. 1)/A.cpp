#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> ans;
        vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        int p = 0;
        while (p < n) {
            if (p + 1 >= n || s == 0) {
                ans.push_back({p, p});
                p++;
                continue;
            }
            if (s < 0) {
                if (a[p + 1] == -1) {
                    ans.push_back({p, p + 1});
                    p += 2;
                    s += 2;
                } else {
                    ans.push_back({p, p});
                    p++;
                }
            } else {
                if (a[p + 1] == 1) {
                    ans.push_back({p, p + 1});
                    p += 2;
                    s -= 2;
                } else {
                    ans.push_back({p, p});
                    p++;
                }
            }
        }
        if (s != 0) {
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << endl;
        for (auto &p : ans)
            cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }

    return 0;
}