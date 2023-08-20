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
    int preMax, sufMax, preMin, sufMin, maxAns, minAns, sum;
    Node() {
        preMax = sufMax = maxAns = -1e9;
        preMin = sufMin = minAns = 1e9;
        sum = 0;
    }
    Node(int w) {
        preMax = sufMax = preMin = sufMin = maxAns = minAns = sum = w;
    }
};

Node merge(const Node &n1, const Node &n2) {
    Node res;
    res.sum = n1.sum + n2.sum;
    res.preMax = max(n1.preMax, n2.preMax + n1.sum);
    res.preMin = min(n1.preMin, n2.preMin + n1.sum);
    res.sufMax = max(n2.sufMax, n1.sufMax + n2.sum);
    res.sufMin = min(n2.sufMin, n1.sufMin + n2.sum);
    res.maxAns = max(max(max(res.preMax, res.sufMax), max(n1.maxAns, n2.maxAns)), n1.sufMax + n2.preMax);
    res.minAns = min(min(min(res.preMin, res.sufMin), min(n1.minAns, n2.minAns)), n1.sufMin + n2.preMin);
    return res;
}

const int max_h = 20, MAXN = 2e5;
vector<int> c[MAXN + 1];
vector<vector<int>> up(MAXN + 1, vector<int>(max_h));
int depth[MAXN + 1], w[MAXN + 1];
vector<vector<Node>> f(MAXN + 1, vector<Node>(max_h));

void buildBL(int u, int par) {
    up[u][0] = par;
    f[u][0] = Node(w[u]);
    for (int i = 1; i < max_h; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        f[u][i] = merge(f[u][i - 1], f[up[u][i - 1]][i - 1]);
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

Node getValPath(int u, int k) {
    Node res = Node(0);
    bitset<max_h> bs(k);
    for (int i = 0; i < max_h; i++) {
        if (bs[i]) {
            res = merge(res, f[u][i]);
            u = up[u][i];
        }
    }
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

struct query {
    int u, v, k;
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int e, n = 1;
        cin >> e;
        c[1].clear();
        vector<query> qr;
        while (e--) {
            char type;
            cin >> type;
            if (type == '+') {
                n++;
                c[n].clear();
                int par, weight;
                cin >> par >> weight;
                c[par].push_back(n);
                c[n].push_back(par);
                w[n] = weight;
            } else {
                int u, v, k;
                cin >> u >> v >> k;
                qr.push_back({u, v, k});
            }
        }

        w[1] = 1;
        depth[1] = 0;
        buildBL(1, 1);
        for (auto q : qr) {
            int lca = getLCA(q.u, q.v);
            Node c1 = getValPath(q.u, depth[q.u] - depth[lca] + 1), c2 = getValPath(q.v, depth[q.v] - depth[lca]);
            swap(c2.preMax, c2.sufMax); 
            swap(c2.preMin, c2.sufMin);
            Node res = merge(c1, c2);
            cout << (q.k >= res.minAns && q.k <= res.maxAns ? "YES" : "NO") << endl;
        }

    }

    return 0;
}
