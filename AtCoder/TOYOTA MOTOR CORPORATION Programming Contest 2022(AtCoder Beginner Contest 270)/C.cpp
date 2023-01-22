#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> par;

void dfs(int u) {
    for (int v : c[u]) {
        if (par[v] == -1) {
            par[v] = u;
            dfs(v);
        }
    }
}

int main() {

    int n, x, y;
    cin >> n >> x >> y;
    par.assign(n + 1, -1);
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    par[y] = 0;
    dfs(y);
    vector<int> ans;
    while (x != 0) {
        ans.push_back(x);
        x = par[x];
    }
    for (int u : ans)
        cout << u << ' ';
    cout << endl;

    return 0;
}