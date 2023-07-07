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

vector<int> par;

int findRoot(int u) {
    if (par[u] < 0) return u;
    par[u] = findRoot(par[u]);
    return par[u];
}

void mergeNode(int n1, int n2) {
    int u = findRoot(n1), v = findRoot(n2);
    if (u == v) return;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
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
    par.assign(n, -1);
    int j = edges.size();
    for (int i = 0; i < n; i++) {
        while (findRoot(i) != findRoot(a[i])) {
            j--;
            mergeNode(edges[j].u, edges[j].v);
        }
        if (i + 1 == n)
            cout << edges[j].w << endl;
    }
    
    return 0;
}
