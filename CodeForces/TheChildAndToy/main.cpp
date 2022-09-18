#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, u, v;
    vector<pair<int, int>> a;
    cin >> n >> m;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> u;
        a.push_back(make_pair(u, i));
        b[i] = u;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> c(n + 1);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    int ans = 0;
    vector<bool> dd(n + 1, false);
    for (int i = a.size() - 1; i >= 0; i--) {
        pair<int, int> p = a[i];
        dd[p.second] = true;
        for (int j = 0; j < c[p.second].size(); j++)
            if (!dd[c[p.second][j]])
                ans += b[c[p.second][j]];
    }
    cout << ans;

    return 0;
}
