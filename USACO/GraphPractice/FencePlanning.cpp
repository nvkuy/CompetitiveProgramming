#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("fenceplan.in", "r"))
        return;
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
}

vector<vector<int>> c;
vector<int> dd, cc;

void dfs(int u) {
    dd[u] = 1;
    cc.push_back(u);
    for (int v : c[u]) 
        if (!dd[v]) dfs(v);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m;
    cin >> n >> m;
    c.resize(n);
    dd.assign(n, 0);
    vector<pair<int, int>> cor(n);
    for (int i = 0; i < n; i++)
        cin >> cor[i].first >> cor[i].second;
    while (m--) {
        int a, b;
        cin >> a >> b;
        c[a - 1].push_back(b - 1);
        c[b - 1].push_back(a - 1);
    }
    int ans = 2e9;
    for (int i = 0; i < n; i++) {
        if (!dd[i]) {
            cc.clear();
            dfs(i);
            int x1 = 1e9, y1 = 1e9, x2 = -1e9, y2 = -1e9;
            for (int u : cc) {
                x1 = min(x1, cor[u].first);
                x2 = max(x2, cor[u].first);
                y1 = min(y1, cor[u].second);
                y2 = max(y2, cor[u].second);
            }
            ans = min(ans, 2 * (x2 - x1 + y2 - y1));
        }
    }
    cout << ans << endl;
    
    return 0;
}
