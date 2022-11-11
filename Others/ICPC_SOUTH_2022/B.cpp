#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<vector<int>> c;
vector<int> dd;
int n;

void dfs(int u, int w) {
    dd[u] = 1;
    for (int v = 0; v < n; v++) {
        if (dd[v] == 0 && c[u][v] >= w)
            dfs(v, w);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int m, q, u, v, w;
    cin >> n >> m >> q;
    c.assign(n, vector<int>(n, -1));
    vector<pair<int, int>> road;
    while (m--) {
        cin >> u >> v >> w;
        u--, v--;
        c[u][v] = w;
        road.push_back({u, v});
    }
    char type;
    while (q--) {
        cin >> type;
        if (type == 'S') {
            cin >> u >> v >> w;
            u--, v--;
            dd.assign(n, 0);
            dfs(u, w);
            cout << ((dd[v] == 1) ? "YES" : "NO") << endl;
        } else {
            cin >> u >> w;
            u--;
            pair<int, int> tmp = road[u];
            c[tmp.first][tmp.second] = w;
        }
    }

    return 0;
}
