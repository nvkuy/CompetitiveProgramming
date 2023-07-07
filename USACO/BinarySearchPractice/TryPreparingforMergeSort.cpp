#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.size() == 0 || ans.back().back() >= a[i]) {
            ans.push_back({a[i]});
            continue;
        }
        int l = 0, r = ans.size() - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (ans[m].back() < a[i])
                r = m;
            else
                l = m + 1;
        }
        ans[r].push_back(a[i]);
    }
    for (auto a : ans) {
        for (auto ai : a)
            cout << ai << ' ';
        cout << endl;
    }

    return 0;
}