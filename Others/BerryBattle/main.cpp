#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
vector<int> h;

void getHeight(int u, int par) {
    for (int v : c[u]) {
        if (v == par)
            continue;
        h[v] = h[u] + 1;
        getHeight(v, u);
    }
}

void getAns(int u, int par, vector<int> &dfs_time) {
    dfs_time.push_back(u);
    for (int v : c[u]) {
        if (v == par)
            continue;
        getAns(v, u, dfs_time);
    }
}

int main()
{

    int n, u, v;
    cin >> n;
    c.resize(n + 1);
    h.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (c[i].size() == 1)
            root = i;
    }
    getHeight(root, -1);
    int max_height = 0;
    for (int i = 1; i <= n; i++) {
        max_height = max(max_height, h[i]);
    }
    if (max_height <= 2) {
        cout << "NO" << endl;
        return 0;
    }
    u = v = -1;
    for (int i = 1; i <= n; i++) {
        for (int j : c[i]) {
            if (c[i].size() > 1 && c[j].size() > 1) {
                u = i;
                v = j;
            }
        }
    }
    vector<int> dfs1, dfs2;
    getAns(u, v, dfs1);
    getAns(v, u, dfs2);
    cout << "YES" << endl;
    cout << dfs1.back() << ' '; dfs1.pop_back();
    cout << dfs2[0] << ' '; dfs2.erase(dfs2.begin());
    cout << dfs2.back() << ' '; dfs2.pop_back();
    cout << dfs1[0] << ' '; dfs1.erase(dfs1.begin());
    for (int u : dfs1)
        cout << u << ' ';
    for (int v : dfs2)
        cout << v << ' ';
    cout << endl;

    return 0;
}
