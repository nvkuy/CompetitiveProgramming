#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, n, m, u, v;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> c(n + 1, n);
        while (m--) {
            cin >> u >> v;
            if (u > v) swap(u, v);
            c[u] = min(c[u], v - 1);
        }
        for (int i = n - 1; i > 0; i--)
            c[i] = min(c[i], c[i + 1]);
        long long ans = 0;
        for (int i = 1; i <= n; i++) ans += (c[i] - i + 1);
        cout << ans << endl;
    }

    return 0;
}