#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<pair<int, int>> ans;
vector<int> vis, odd;
int timer = 1, sum_deg;

void dfs(int u, int par = 0) {

    vis[u] = timer++;
    sum_deg += c[u].size();
    for (int v : c[u]) {
        if (v == par) continue;
        if (!vis[v]) {
            dfs(v, u);
            if (odd[v]) {
                ans.push_back({v, u});
                odd[v] = 0;
            } else {
                ans.push_back({u, v});
                odd[u] ^= 1;
            }
        } else {
            if (vis[u] > vis[v]) {
                ans.push_back({v, u});
                odd[v] ^= 1;
            }
        }
    }

}

int main() {

    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    vis.assign(n + 1, 0);
    odd = vis;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    bool hasAns = true;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        sum_deg = 0;
        dfs(i);
        if ((sum_deg / 2) & 1) {
            hasAns = false;
            break;
        }
    }

    if (!hasAns) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (auto p : ans)
        cout << p.first << ' ' << p.second << endl;

    return 0;
}