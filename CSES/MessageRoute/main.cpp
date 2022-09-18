#include <bits/stdc++.h>

int dd[100001];

using namespace std;

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> c(n + 1);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    memset(dd, -1, (n + 1) * sizeof *dd);
    dd[1] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < c[u].size(); i++) {
            if (dd[c[u][i]] == -1) {
                dd[c[u][i]] = u;
                q.push(c[u][i]);
            }
            if (dd[n] > 0)
                break;
        }
        if (dd[n] > 0)
            break;
    }
    if (dd[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    u = n;
    while (u != 0) {
        ans.push_back(u);
        u = dd[u];
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';

    return 0;
}
