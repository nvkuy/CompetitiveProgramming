#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int inf = 1e9 + 7;
vector<vector<int>> c;
vector<int> f, vis;

void dfs(int u) {

    vis[u] = 1;
    int res = inf;
    if (c[u].size() > 0) res = 0;
    for (int v : c[u]) {
        if (!vis[v]) dfs(v);
        res = min(inf, res + f[v]);
    }
    f[u] = min(f[u], res);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        c.clear();
        c.resize(n + 1);
        f.assign(n + 1, inf);
        vis.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> f[i];
        while (k--) {
            int tmp;
            cin >> tmp;
            f[tmp] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int u;
                cin >> u;
                c[i].push_back(u);
            }
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i]) dfs(i);

        for (int i = 1; i <= n; i++) cout << f[i] << ' ';
        cout << endl;

    }

    return 0;
}
