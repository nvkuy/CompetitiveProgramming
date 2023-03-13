#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> dd;

struct edge {
    int f, t, w;
};

void dfs(int u) {
    dd[u] = 1;
    for (int v : c[u]) {
        if (!dd[v])
            dfs(v);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<edge> edges(m);
        for (int i = 0; i < m; i++)
            cin >> edges[i].f >> edges[i].t >> edges[i].w;
        int ll = 0, rr = 1e9 + 7, mm;
        while (ll < rr) {
            mm = (ll + rr) / 2;
            c.clear();
            c.resize(n + 1);
            dd.assign(n + 1, 0);
            vector<int> in_cnt(n + 1, 0);
            for (auto e : edges) {
                c[e.f].push_back(e.t);
                in_cnt[e.t]++;
                if (e.w <= mm) {
                    c[e.t].push_back(e.f);
                    in_cnt[e.f]++;
                }
            }
            int root = 1;
            for (int i = 1; i <= n; i++) {
                if (in_cnt[i] < in_cnt[root])
                    root = i;
            }
            dfs(root);
            bool iok = true;
            for (int i = 1; i <= n; i++)
                iok &= dd[i];
            if (iok)
                rr = mm;
            else
                ll = mm + 1;
        }
        if (rr > 1e9) rr = -1;
        cout << rr << endl;
    }

    return 0;
}
