#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("factory.in", "r"))
        return;
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
}

vector<vector<int>> c;
vector<int> f;

void dfs(int u, int par) {
    f[u]++;
    for (int v : c[u]) {
        if (v == par)
            continue;
        if (f[v] == 0)
            dfs(v, u);
        f[u] += f[v];
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    c.resize(n + 1);
    f.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (f[i] == 0) dfs(i, 0);
    for (int i = 1; i <= n; i++) {
        if (f[i] == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
