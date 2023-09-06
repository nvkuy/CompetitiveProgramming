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

vector<long long> c, good, vis, good_but_depend;
long long ans, n, good_cnt, com1;
vector<vector<int>> depend;

void dfs1(int u) {

    vis[u] = 1;
    int v = c[u] + u;
    if (v < 1 || v > n) 
        good[u] = 1;
    else {
        if (!vis[v])
            dfs1(v);
        if (good[v]) {
            good[u] = 1;
            depend[v].push_back(u);
        }
    }
    good_cnt += good[u];

}

void dfs2(int u) {

    vis[u] = 1;
    good_but_depend[u] = good[u];
    for (int v : depend[u]) {
        if (!vis[v])
            dfs2(v);
        good_but_depend[u] += good_but_depend[v];
    }

}

void dfs3(int u) {

    com1++;
    vis[u] = 1;
    ans += (n + 1);
    ans += (good_cnt - good_but_depend[u]);
    int v = u + c[u];
    if (v >= 1 && v <= n && !vis[v])
        dfs3(v);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        c.resize(n + 1);
        depend.clear();
        depend.resize(n + 1);
        good.assign(n + 1, 0);
        good_but_depend.assign(n + 1, 0);
        ans = good_cnt = com1 = 0;
        for (int i = 1; i <= n; i++) cin >> c[i];
        vis.assign(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            if (!vis[u]) 
                dfs1(u);
        }
        vis.assign(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            if (!vis[u]) 
                dfs2(u);
        }
        vis.assign(n + 1, 0);
        dfs3(1);
        if (good[1]) ans += (n - com1) * (2 * n + 1);
        cout << ans << endl;
    }

    return 0;
}
