#include <bits/stdc++.h>

using namespace std;

int n;
bool dd[100001];
vector<vector<int>> c;

void dfs(int u) {
    dd[u] = true;
    for (int i = 0; i < c[u].size(); i++) {
        if (!dd[c[u][i]])
            dfs(c[u][i]);
    }
}

int main()
{
    int m, u, v;
    cin >> n >> m;
    c.resize(n + 1);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    memset(dd, false, (n + 1) * sizeof *dd);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!dd[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ' ' << ans[i + 1] << endl;

    return 0;
}
