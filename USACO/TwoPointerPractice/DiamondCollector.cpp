#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("diamond.in", "r")) {
        freopen("diamond.in", "r", stdin);
        freopen("diamond.out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    vector<int> a(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int j = lower_bound(a.begin(), a.end(), a[i] - k) - a.begin();
        f[i] = i - j + 1;
        if (i > 0) f[i] = max(f[i], f[i - 1]);
    }
    int ans = f[n - 1];
    for (int i = 0; i < n; i++) {
        int j = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
        int tans = j - i;
        if (i > 0) tans += f[i - 1];
        ans = max(ans, tans);
    }
    cout << ans << endl;

    return 0;
}