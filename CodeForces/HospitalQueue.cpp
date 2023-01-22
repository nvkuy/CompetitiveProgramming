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
int cnt;

void dfs(int u) {
    dd[u] = 1;
    cnt++;
    for (int v : c[u])
        if (!dd[v]) dfs(v);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    vector<pair<int, int>> p(n), sp;
    for (int i = 0; i < n; i++) {
        cin >> u;
        p[i] = {u, i};
    }
    sp = p;
    sort(sp.begin(), sp.end());
    c.resize(n);
    while (m--) {
        cin >> u >> v;
        u--, v--;
        c[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        int ll = 1, rr = p[i].first, mm;
        while (ll < rr) {
            mm = (ll + rr) / 2;
            dd.assign(n, 0);
            cnt = 0;
            bool iok = true;
            dfs(i);
            for (int j = 0; j < n; j++) {
                if (!dd[j] && p[j].first <= mm)
                    dfs(j);
            }
            if (cnt > mm)
                iok = false;
            for (int j = 0; j < n; j++) {
                auto t = sp[j];
                if (!dd[t.second]) {
                    dfs(t.second);
                    if (cnt > t.first)
                        iok = false;
                }
            }
            if (iok)
                rr = mm;
            else
                ll = mm + 1;
        }
        cout << rr << ' ';
    }
    cout << endl;

    return 0;
}
