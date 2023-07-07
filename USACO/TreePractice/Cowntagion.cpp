#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
int cost = 0;

void dfs(int u, int par) {
    int need = 0, child = c[u].size() - (par != 0);
    while ((1 << need) <= child)
        need++;
    cost += (need + child);
    for (int v : c[u])
        if (v != par) dfs(v, u);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    dfs(1, 0);

    cout << cost << endl;

    return 0;
}