#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;
vector<vector<int>> c;
vector<bool> dd;

void dfs(int u) {
    dd[u] = true;
    for (int i = 0; i < c[u].size(); i++) {
        if (!dd[c[u][i]])
            dfs(c[u][i]);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int u, v;
    cin >> n >> k;
    c.resize(n + 1);
    dd.assign(n + 1, false);
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    int cc = 0;
    for (int i = 1; i <= n; i++) {
        if (!dd[i]) {
            cc++;
            dfs(i);
        }
    }
    if (cc == 1)
        cout << '-' << k - n + 1;
    else
        cout << '+' << cc - 1;

    return 0;
}
