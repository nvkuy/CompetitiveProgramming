#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    int l = 1, r = n, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        bool iok = false;
        vector<int> greater(n + 1, 0);
        int max_diff = -1e9;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= m)
                greater[i]++;
            greater[i] += greater[i - 1];
            if (i < k) continue;
            else max_diff = max(max_diff, (i - k) - 2 * greater[i - k]);
            if (2 * greater[i] - i + max_diff > 0) {
                iok = true;
                break;
            }
        }
        if (iok)
            l = m;
        else
            r = m - 1;
    }
    cout << l << endl;

    return 0;
}