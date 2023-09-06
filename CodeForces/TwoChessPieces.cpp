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

const int max_h = 18;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth;
unordered_set<int> need_pass[2];
int pos[2];
vector<pair<int, int>> order;

void buildBL(int u, int par) {
    up[u][0] = par;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        depth[v] = depth[u] + 1;
        buildBL(v, u);
    }
}

int upByK(int u, int k) {
    bitset<max_h> bs(k);
    for (int i = 0; i < max_h; i++) {
        if (bs[i])
            u = up[u][i];
    }
    return u;
}

int getLCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int depth_diff = depth[u] - depth[v];
    u = upByK(u, depth_diff);
    for (int i = max_h - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    if (u != v)
        u = up[u][0];
    return u;
}

int dist(int u, int v) {
    int lca = getLCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

void build_vis_order(int u, int par) {

    if (need_pass[0].find(u) != need_pass[0].end())
        order.push_back({u, 0});
    if (need_pass[1].find(u) != need_pass[1].end())
        order.push_back({u, 1});

    for (int v : c[u]) {
        if (v != par)
            build_vis_order(v, u);
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, d, ans = 0;
    cin >> n >> d;
    c.resize(n + 1);
    up.assign(n + 1, vector<int>(max_h));
    depth.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    int m1, m2;
    cin >> m1;
    while (m1--) {
        int u;
        cin >> u;
        need_pass[0].insert(u);
    }
    cin >> m2;
    while (m2--) {
        int u;
        cin >> u;
        need_pass[1].insert(u);
    }

    buildBL(1, 0);
    build_vis_order(1, 0);
    order.push_back({1, 0});
    order.push_back({1, 1});

    pos[0] = pos[1] = 1;
    for (auto p : order) {
        int cur = p.second, other = 1 - cur;
        need_pass[cur].erase(p.first);
        ans += dist(pos[cur], p.first);
        pos[cur] = p.first;
        int need = dist(pos[cur], pos[other]) - d;
        if (need <= 0) continue;
        ans += need;
        int lca = getLCA(pos[cur], pos[other]);
        int tmp = depth[pos[other]] - depth[lca];
        if (need <= tmp) pos[other] = upByK(pos[other], need);
        else {
            need -= tmp;
            pos[other] = upByK(pos[cur], depth[pos[cur]] - depth[lca] - need);
        }
    }

    cout << ans << endl;
    
    return 0;
}
