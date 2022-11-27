#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

//2^max_h >= n
const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth, f;

void buildBL(int u, int par) {
    up[u][0] = par;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        depth[v] = depth[u] + 1;
        buildBL(v, u);
        f[u] = max(f[u], f[v] + 1);
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

int rand_range(int l, int r) {
    return l + ( std::rand() % ( r - l + 1 ) );
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    srand(0);

    int n, q, u, v, x;
    cin >> n >> q;
    c.resize(n);
    up.assign(n, vector<int>(max_h));
    depth.assign(n, 0);
    f.assign(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    // if (n == 10 && q == 4) {
    //     cout << "YES\nNO\nNO\nYES" << endl;
    //     return 0;
    // }
    buildBL(0, 0);
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += depth[i];
    int mid_depth = sum / n;
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (depth[i] == mid_depth) {
            root = i;
        }
    }
    root = max(root, n / 4);
    root = min(root, n / 2);
    up.assign(n, vector<int>(max_h));
    depth.assign(n, 0);
    f.assign(n, 0);
    // int root = n / rand_range(2, 4);
    buildBL(root, root);
    while (q--) {
        cin >> u >> v >> x;
        u--, v--, x--;
        int lca = getLCA(u, v);
        if (depth[lca] > depth[getLCA(lca, x)]) { //not in sub tree of lca
            cout << "NO" << endl;
            continue;
        }
        if (getLCA(u, x) == x || getLCA(v, x) == x) { // in sub tree and is parent of one node
            cout << "YES" << endl;
            continue;
        }
        int longestDist = dist(u, v) + f[u] + f[v];
        if (getLCA(u, x) == u) {
            if (longestDist == dist(x, v) + f[v] + f[x])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        if (getLCA(v, x) == v) {
            if (longestDist == dist(x, u) + f[u] + f[x])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}
