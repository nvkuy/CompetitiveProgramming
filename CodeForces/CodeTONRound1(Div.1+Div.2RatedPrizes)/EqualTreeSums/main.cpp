#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> ans;

void dfs(int u, int color, int par) {
    ans[u] = c[u].size() * color;
    for (int i = 0; i < c[u].size(); i++)
        if (c[u][i] != par)
            dfs(c[u][i], -color, u);
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
        ans.resize(n + 1);
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(1, 1, 0);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
