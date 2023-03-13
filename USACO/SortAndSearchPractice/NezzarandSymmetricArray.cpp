#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<long long, int> cnt;
        for (int i = 0; i < 2 * n; i++) {
            long long di;
            cin >> di;
            cnt[di]++;
        }
        bool iok = cnt.size() == n;
        vector<long long> a;
        long long pre_sum = 0, pos = 1;
        for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
            auto p = *it;
            if (!iok) break;
            if (p.second != 2) iok = false;
            long long tmp = p.first + 2 * pre_sum;
            long long tt = 2 * pos - 2 * n - 2;
            if (tmp % tt > 0) iok = false;
            a.push_back(tmp / tt);
            pos++;
            pre_sum += a.back();
        }
        for (int i = 0; i < a.size(); i++) {
            if (!iok) break;
            if (i > 0 && a[i] <= a[i - 1]) iok = false;
            if (a[i] >= 0) iok = false;
        }
        cout << (iok ? "YES" : "NO") << endl;
        // if (!iok) continue;
        // for (int num : a)
        //     cout << num << ' ';
        // cout << endl;
    }

    return 0;
}