#include <bits/stdc++.h>

using namespace std;

bool dd[100001];
int team[100001];
vector<vector<int>> c;

bool dfs(int u) {
    for (int i = 0; i < c[u].size(); i++) {
        if (!dd[c[u][i]]) {
            dd[c[u][i]] = true;
            team[c[u][i]] = 3 - team[u];
            bool iok = dfs(c[u][i]);
            if (!iok)
                return false;
        } else {
            if (team[c[u][i]] == team[u])
                return false;
        }
    }
    return true;
}

int main()
{
    int m, u, v, n;
    cin >> n >> m;
    c.resize(n + 1);
    memset(dd, false, (n + 1) * sizeof *dd);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    bool iok;
    for (int i = 1; i <= n; i++) {
        if (!dd[i]) {
            dd[i] = true;
            team[i] = 1;
            iok = dfs(i);
            if (!iok)
                break;
        }
    }
    if (!iok) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cout << team[i] << ' ';

    return 0;
}
