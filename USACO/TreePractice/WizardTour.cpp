#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<vector<int>> c;
vector<int> vis;
set<pair<int, int>> used;

void savePath(int u1, int u2, int u3) {
    used.insert({u1, u2});
    used.insert({u2, u1});
    used.insert({u2, u3});
    used.insert({u3, u2});
    ans.push_back({u1, u2, u3});
}

void dfs(int u, int par = 0) {

    vis[u] = 1;

    vector<int> free;
    for (int v : c[u]) {
        if (v == par) continue;
        if (!vis[v])
            dfs(v, u);
        if (used.count({u, v}) == 0)
            free.push_back(v);
    }
    
    for (int i = 0; i + 1 < free.size(); i += 2)
        savePath(free[i], u, free[i + 1]);
    if ((free.size() & 1) && (par != 0))
        savePath(par, u, free.back());

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    vis.assign(n + 1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);

    cout << ans.size() << endl;
    for (auto p : ans) cout << p[0] << ' ' << p[1] << ' ' << p[2] << endl;

    return 0;
}