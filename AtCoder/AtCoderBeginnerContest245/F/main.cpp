#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> dd, canGoCyc;

void dfs(int u) {
    dd[u] = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (canGoCyc[v] == 1 || dd[v] == 1)
            canGoCyc[u] = 1;
        else {
            if (dd[v] == 0)
                dfs(v);
            if (canGoCyc[v])
                canGoCyc[u] = 1;
        }
    }
    dd[u] = 2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    c.resize(n + 1);
    dd.assign(n + 1, 0);
    canGoCyc.assign(n + 1, 0);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dd[i] == 0)
            dfs(i);
        if (canGoCyc[i])
            ans++;
    }
    cout << ans;

    return 0;
}
