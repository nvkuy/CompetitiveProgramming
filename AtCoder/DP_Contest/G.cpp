#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<vector<int>> c;
vector<int> f, dd;

void dfs(int u) {
    dd[u] = 1;
    for (int v : c[u]) {
        if (!dd[v])
            dfs(v);
        f[u] = max(f[u], f[v] + 1);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // debugLocal();

    int n, m, u, v;
    cin >> n >> m;
    c.resize(n + 1);
    f.assign(n + 1, 0);
    dd.assign(n + 1, 0);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (dd[i] == 0)
            dfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;

    return 0;
}