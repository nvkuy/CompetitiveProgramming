#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("moocast.in", "r"))
        return;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
}

struct edge {
    long long w;
    int u, v;

    edge(long long weight, int from, int to) {
        w = weight;
        u = from;
        v = to;
    }

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

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<pair<long long, long long>> cow(n);
    for (int i = 0; i < n; i++) cin >> cow[i].first >> cow[i].second;

    vector<edge> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edges.push_back(edge(
                (cow[i].first - cow[j].first) * (cow[i].first - cow[j].first) + 
                (cow[i].second - cow[j].second) * (cow[i].second - cow[j].second),
                i, j
            ));
    sort(edges.begin(), edges.end());
    par.assign(n, -1);
    for (auto e : edges) {
        mergeNode(e.u, e.v);
        if (abs(par[findRoot(e.u)]) == n) {
            cout << e.w << endl;
            return 0;
        }
    }
    
    return 0;
}
