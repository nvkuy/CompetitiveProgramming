#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n), dd(2 * n, 0);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<pair<int, int>> ans;
        int pre = 2 * n - 1;
        for (int i = 2 * n - 2; i >= 0; i--) {
            if (dd[i] != 0) continue;
            for (int j = 0; j < i; j++) {
                if (dd[j] == 0 && a[i] + a[j] == a[pre]) {
                    ans.push_back({a[i], a[j]});
                    dd[i] = dd[j] = 1;
                    pre = i;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        int x = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            if (dd[i] == 0) {
                ans.push_back({a[i], a[2 * n - 1]});
                x = a[i] + a[2 * n - 1];
                break;
            }
        }
        if (ans.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        reverse(ans.begin(), ans.end());
        cout << x << endl;
        for (auto p : ans)
            cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
