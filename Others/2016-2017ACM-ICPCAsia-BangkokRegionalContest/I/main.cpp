#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth, numNodeSubTree;

void build(int u, int par) {
    numNodeSubTree[u]++;
    up[u][0] = par;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        depth[v] = depth[u] + 1;
        build(v, u);
        numNodeSubTree[u] += numNodeSubTree[v];
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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, q, root, a, b;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cin >> n >> q >> root;
        c.clear();
        c.resize(n + 1);
        up.assign(n + 1, vector<int>(max_h));
        depth.assign(n + 1, 0);
        numNodeSubTree.assign(n + 1, 0);
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            c[a].push_back(b);
            c[b].push_back(a);
        }
        build(root, root);
        vector<int> ans;
        while (q--) {
            cin >> a >> b;
            if (a == 0)
                root = b;
            else {
                if (b == root) {
                    ans.push_back(n);
                    continue;
                }
                int tmp = getLCA(root, b);
                if (tmp != b) {
                    ans.push_back(numNodeSubTree[b]);
                    continue;
                }
                tmp = upByK(root, depth[root] - depth[b] - 1);
                ans.push_back(n - numNodeSubTree[tmp]);
            }
        }
        cout << "Case #" << tt << ':' << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;
    }

    return 0;
}
