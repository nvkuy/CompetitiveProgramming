#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string type;
vector<vector<int>> c;
vector<pair<int, int>> f;
vector<bool> ans;

void dfs(int u, int par) {
    if (type[u - 1] == 'B')
        f[u].first = 1;
    else
        f[u].second = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        f[u].first += f[v].first;
        f[u].second += f[v].second;
    }
    ans[u] = (f[u].first == f[u].second);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, u;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear(), c.resize(n + 1), f.assign(n + 1, {0, 0}), ans.assign(n + 1, false);
        for (int i = 2; i <= n; i++) {
            cin >> u;
            c[u].push_back(i);
            c[i].push_back(u);
        }
        cin.ignore();
        getline(cin, type);
        dfs(1, 0);
        int bst = 0;
        for (int i = 1; i <= n; i++)
            bst += ans[i];
        cout << bst << endl;
    }

    return 0;
}
