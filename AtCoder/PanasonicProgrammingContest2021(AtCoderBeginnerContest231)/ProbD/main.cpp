#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
bool ans;
vector<int> dd;

void dfs(int u, int co) {
    dd[u] = co;
    co++;
    if (!ans)
        return;
    for (int i = 0; i < c[u].size(); i++) {
        if (dd[c[u][i]] == -1)
            dfs(c[u][i], co);
        else {
            if (dd[u] - dd[c[u][i]] > 1) {
                ans = false;
                return;
            }
        }
    }
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    c.resize(n + 1);
    dd.assign(n + 1, -1);
    ans = true;
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
        if (c[u].size() > 2 || c[v].size() > 2)
            ans = false;
    }
    for (int i = 1; i <= n; i++) {
        if (!ans)
            break;
        if (dd[i] == -1)
            dfs(i, 1);
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}
