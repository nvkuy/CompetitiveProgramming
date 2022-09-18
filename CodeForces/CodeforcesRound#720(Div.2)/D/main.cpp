#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> freeLeaf;
vector<pair<pair<int, int>, pair<int, int>>> ans;

void dfs(int u, int par) {

    vector<int> child;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        child.push_back(v);
        dfs(v, u);
    }
    if (child.empty()) {
        freeLeaf[u] = u;
        return;
    }
    freeLeaf[u] = freeLeaf[child[0]];
    while (child.size() > 1 + (par == 0)) {
        int v = child.back();
        child.pop_back();
        ans.push_back({{u, v}, {v, freeLeaf[u]}});
        freeLeaf[u] = freeLeaf[v];
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        freeLeaf.resize(n + 1);
        ans.clear();
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
            sort(c[i].begin(), c[i].end());
        dfs(1, 0);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second.first << ' ' << ans[i].second.second << endl;
    }

    return 0;
}
