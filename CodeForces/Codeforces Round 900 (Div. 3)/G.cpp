#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up, f;
vector<int> depth, a;

void buildBL(int u, int par) {
    up[u][0] = par;
    f[u][0] = a[u];
    for (int i = 1; i < max_h; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        f[u][i] = f[u][i - 1] | f[up[u][i - 1]][i - 1];
    }
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

int getOrUpByK(int u, int k) {
    bitset<max_h> bs(k);
    int res = 0;
    for (int i = 0; i < max_h; i++) {
        if (bs[i]) {
            res |= f[u][i];
            u = up[u][i];
        }
    }
    res |= a[u];
    return res;
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

int getDist(int x, int y) {
    int lca = getLCA(x, y);
    return depth[x] + depth[y] - 2 * depth[lca];
}

int getOR(int x, int y) {
    int lca = getLCA(x, y);
    int d1 = depth[x] - depth[lca], d2 = depth[y] - depth[lca];
    return getOrUpByK(x, d1) | getOrUpByK(y, d2);
}

int getZ(int x, int y, int m) {
    int lca = getLCA(x, y);
    int d1 = depth[x] - depth[lca], d2 = depth[y] - depth[lca];
    int z;
    if (m <= d1)
        z = upByK(x, m);
    else {
        int tmp = d2 - (m - d1);
        z = upByK(y, tmp);
    }
    return z;
}

int tryXZ(int x, int y, int bitXZ) {

    if (bit_cnt(getOR(x, y)) < bitXZ) return 0;
    int d = getDist(x, y);

    int l = 0, r = d;
    while (l < r) {

        int m = (l + r) / 2;
        int z = getZ(x, y, m);

        if (bit_cnt(getOR(x, z)) < bitXZ)
            l = m + 1;
        else
            r = m;

    }

    int z = getZ(x, y, r);
    return bit_cnt(getOR(x, z)) + bit_cnt(getOR(z, y));

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

        a.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(max_h));
        f.assign(n, vector<int>(max_h));
        c.assign(n, vector<int>());

        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            c[u].push_back(v);
            c[v].push_back(u);
        }

        buildBL(0, 0);

        int q;
        cin >> q;

        while (q--) {

            int x, y;
            cin >> x >> y;
            x--, y--;

            int res = 0;
            for (int i = 0; i < 40; i++)
                res = max(res, tryXZ(x, y, i));

            cout << res << ' ';

        }

        cout << endl;

    }

    return 0;
}