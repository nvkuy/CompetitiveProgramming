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

struct Node {
    long long val, id;
    bool operator < (const Node &n) const {
        if (val == n.val) return id > n.id;
        return val < n.val;
    }
};

vector<set<Node>> child;
vector<long long> par, sum_val, val, node_cnt;
vector<vector<int>> c;

void dfs(int u, int parent) {
    sum_val[u] += val[u];
    node_cnt[u]++;
    par[u] = parent;
    for (int v : c[u]) {
        if (v != parent) {
            dfs(v, u);
            sum_val[u] += sum_val[v];
            node_cnt[u] += node_cnt[v];
            child[u].insert({node_cnt[v], v});
        }
    }
    // cout << "@u: " << u << endl;
    // for (auto p : child[u]) {
    //     cout << p.val << ' ' << p.id << endl;
    // }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    child.resize(n + 1);
    par.assign(n + 1, 0);
    sum_val.assign(n + 1, 0);
    val.resize(n + 1);
    node_cnt.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    
    dfs(1, 0);

    while (m--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            // cout << "@x: " << x << ' ' << child[x].size() << endl;
            cout << sum_val[x] << endl;
            continue;
        }
        if (child[x].size() == 0) continue;
        int heavy_child = child[x].rbegin()->id, par_x = par[x];
        // cout << "@x: " << x << " @heavy: " << heavy_child << endl;
        child[par_x].erase(child[par_x].lower_bound({node_cnt[x], x}));
        child[x].erase(child[x].lower_bound({node_cnt[heavy_child], heavy_child}));
        sum_val[x] -= sum_val[heavy_child];
        node_cnt[x] -= node_cnt[heavy_child];
        par[heavy_child] = par_x;
        par[x] = heavy_child;
        child[heavy_child].insert({node_cnt[x], x});
        sum_val[heavy_child] += sum_val[x];
        node_cnt[heavy_child] += node_cnt[x];
        child[par_x].insert({node_cnt[heavy_child], heavy_child});
    }

    return 0;
}
