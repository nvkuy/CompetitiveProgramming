#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int max_h = 20;
int n;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth, numNodeSubTree;

void buildBL(int u, int par) {
    up[u][0] = par;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        numNodeSubTree[u]++;
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

int nodeByMid(int mid_node, int node) {
    if (depth[node] > depth[mid_node])
        return numNodeSubTree[node];
    return n - numNodeSubTree[mid_node];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, a, b;
    cin >> n;
    c.resize(n + 1);
    depth.assign(n + 1, 0);
    numNodeSubTree.assign(n + 1, 1);
    up.assign(n + 1, vector<int>(max_h));
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        c[b].push_back(a);
        c[a].push_back(b);
    }
    buildBL(1, 1);
    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a == b) {
            cout << n << endl;
            continue;
        }
        int len = dist(a, b);
        if (len % 2 == 1) {
            cout << "0" << endl;
            continue;
        }
        int child1, child2, mid_node;
        if (depth[a] < depth[b])
            swap(a, b);
        child1 = upByK(a, (len / 2) - 1);
        mid_node = upByK(child1, 1);
        int lca = getLCA(a, b);
        if (mid_node == lca)
            child2 = upByK(b, (len / 2) - 1);
        else
            child2 = upByK(mid_node, 1);
        cout << n - nodeByMid(mid_node, child1) - nodeByMid(mid_node, child2) << endl;

    }

    return 0;
}
