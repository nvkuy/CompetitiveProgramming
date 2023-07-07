#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("mootube.in", "r"))
        return;
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
}

vector<vector<pair<int, int>>> c;
vector<int> rel;

void dfs(int u, int par) {
    for (auto p : c[u]) {
        if (p.first != par) {
            rel[p.first] = min(rel[u], p.second);
            dfs(p.first, u);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q;
    cin >> n >> q;
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, r;
        cin >> u >> v >> r;
        c[u].push_back({v, r});
        c[v].push_back({u, r});
    }
    while (q--) {
        int u, k;
        cin >> k >> u;
        rel.assign(n + 1, 1e9 + 7);
        dfs(u, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (i != u) ans += rel[i] >= k;
        cout << ans << endl;
    }

    return 0;
}
