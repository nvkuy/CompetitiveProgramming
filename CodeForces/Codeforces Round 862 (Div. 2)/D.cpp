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

//2^max_h >= n
const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth;

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

//make long long if need
int dist(int u, int v) {
    int lca = getLCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

bool cmpDepth(int u, int v) {
    return depth[u] < depth[v];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, a, b;
    cin >> n;
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(max_h));
    buildBL(1, 1);
    a = 1;
    for (int i = 1; i <= n; i++) {
        if (depth[a] < depth[i])
            a = i;
    }
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(max_h));
    buildBL(a, a);
    b = 1;
    for (int i = 1; i <= n; i++) {
        if (depth[b] < depth[i])
            b = i;
    }
    int cur_cc = 1;
    multiset<int> rm;
    vector<int> order_depth;
    for (int i = 1; i <= n; i++) order_depth.push_back(i);
    sort(order_depth.begin(), order_depth.end(), cmpDepth);
    int j = 0;
    for (int cur_depth = 0; cur_depth < n; cur_depth++) {
        while (j < n && depth[order_depth[j]] == cur_depth) {
            rm.insert(dist(b, order_depth[j]));
            j++;
        }
        // cout << "depth = " << cur_depth << ": ";
        // for (int ai : rm)
        //     cout << ai << ' ';
        // cout << endl;
        while (rm.size() > 0 && cur_depth + 1 > *rm.begin()) {
            cur_cc++;
            rm.erase(rm.begin());
        }
        cout << min(cur_cc, n) << ' ';
    }
    cout << endl;

    return 0;
}
