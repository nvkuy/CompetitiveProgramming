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

vector<vector<int>> c;
vector<int> vis, order;

void dfs(int u) {

    vis[u] = 1;
    for (int v : c[u]) {
        if (!vis[v])
            dfs(v);
    }
    order.push_back(u);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        c.clear();
        c.resize(n + 1);
        vis.assign(n + 1, 0);
        order.clear();
        vector<pair<int, int>> dfs_order;
        for (int i = 1; i <= n; i++) {
            int ai;
            cin >> ai;
            c[ai].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            int ci;
            cin >> ci;
            dfs_order.push_back({ci, i});
        }
        sort(dfs_order.begin(), dfs_order.end());
        for (auto p : dfs_order) {
            if (!vis[p.second])
                dfs(p.second);
        }
        for (int v : order)
            cout << v << ' ';
        cout << endl;
    }

    return 0;
}
