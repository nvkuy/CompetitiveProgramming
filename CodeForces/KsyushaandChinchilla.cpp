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

vector<vector<int>> c;
set<pair<int, int>> keep;
vector<int> used;
bool iok;

void dfs(int u, int par) {
    if (!iok) return;
    vector<int> free;
    for (int v : c[u]) {
        if (v == par) continue;
        dfs(v, u);
        if (!iok) return;
        if (!used[v]) free.push_back(v);
    }
    if (free.size() > 2) {
        iok = false;
        return;
    }
    if (free.size() == 1) {
        if (used[par] || used[u]) {
            iok = false;
            return;
        }
        int t1 = par, t2 = u;
        if (t1 > t2) swap(t1, t2);
        keep.insert({t1, t2});
        t1 = u, t2 = free[0];
        if (t1 > t2) swap(t1, t2);
        keep.insert({t1, t2});
        used[free[0]] = used[par] = used[u] = 1;
    }
    if (free.size() == 2) {
        if (used[u]) {
            iok = false;
            return;
        }
        int t1 = free[0], t2 = u;
        if (t1 > t2) swap(t1, t2);
        keep.insert({t1, t2});
        t1 = u, t2 = free[1];
        if (t1 > t2) swap(t1, t2);
        keep.insert({t1, t2});
        used[free[0]] = used[free[1]] = used[u] = 1;
    }
    if (free.size() == 0 && used[par] && !used[u]) iok = false;
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
        iok = (n % 3 == 0);
        c.clear();
        c.resize(n + 1);
        keep.clear();
        used.assign(n + 1, 0);
        vector<pair<int, int>> edge(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            edge[i] = {u, v};
            c[u].push_back(v);
            c[v].push_back(u);
        }
        used[0] = 1;
        dfs(1, 0);
        if (!iok) {
            cout << -1 << endl;
            continue;
        }
        cout << n - 1 - keep.size() << endl;
        for (int i = 1; i < n; i++) {
            if (keep.find(edge[i]) == keep.end())
                cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
