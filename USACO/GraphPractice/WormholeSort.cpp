#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("wormsort.in", "r"))
        return;
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
}

struct edge {
    int w, u, v;

    bool operator < (const edge &e) const {
        return w < e.w;
    }

};

vector<vector<int>> c;
vector<int> cc;

void dfs(int u, int cc_num) {
    cc[u] = cc_num;
    for (int v : c[u])
        if (cc[v] == 0)
            dfs(v, cc_num);
}

int main()
{

    debugLocal();

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--, edges[i].v--;
    }

    bool needSort = false;
    for (int i = 0; i < n; i++)
        if (a[i] != i) needSort = true;
    if (!needSort) {
        cout << -1 << endl;
        return 0;
    }

    sort(edges.begin(), edges.end());
    int l = 1, r = 1e9;
    while (l < r) {
        m = (l + r + 1) / 2;

        c.clear();
        c.resize(n);
        cc.assign(n, 0);
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (edges[i].w < m)
                break;
            c[edges[i].u].push_back(edges[i].v);
            c[edges[i].v].push_back(edges[i].u);
        }

        for (int i = 0; i < n; i++) {
            if (cc[i] == 0)
                dfs(i, i + 1);
        }

        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (cc[i] != cc[a[i]]) {
                iok = false;
                break;
            }
        }
        if (iok)
            l = m;
        else
            r = m - 1;
    }

    cout << l << endl;
    
    return 0;
}
