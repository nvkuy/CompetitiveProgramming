#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth;
int root;

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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, a, b;
    char t;
    cin >> n;
    while (n != 0) {
        root = 1;
        c.clear();
        c.resize(n + 1);
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(max_h));
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            c[b].push_back(a);
            c[a].push_back(b);
        }
        buildBL(root, root);
        cin >> q;
        while (q--) {
            cin >> t;
            if (t == '!')
                cin >> root;
            else {
                cin >> a >> b;
                vector<int> tmp;
                tmp.push_back(getLCA(a, b));
                tmp.push_back(getLCA(a, root));
                tmp.push_back(getLCA(b, root));
                sort(tmp.begin(), tmp.end());
                cout << (tmp[0] != tmp[1] ? tmp[0] : tmp[2]) << endl;
            }
        }
        cin >> n;
    }

    return 0;
}
