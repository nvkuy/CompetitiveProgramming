#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ans;
vector<vector<int>> c;
vector<int> vis;
vector<vector<int>> dd;

void dfs(int u, int root) {
    if (dd[root][ans] > dd[root][u])
        ans = u;
    vis[u] = true;
    for (int i = 0; i < c[u].size(); i++) {
        if (!vis[c[u][i]])
            dfs(c[u][i], root);
    }
    vis[u] = false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ai;
    cin >> n;
    dd.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ai;
            dd[i][ai] = j;
        }
    }
    c.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dd[i][i] <= dd[i][j] || dd[j][i] >= dd[j][j])
                continue;
            c[i].push_back(j);
            c[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = i;
        dfs(i, i);
        cout << ans << endl;
    }

    return 0;
}
