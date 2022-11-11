#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<vector<int>> c;
vector<int> cc, a, dd;

void dfs(int u) {
    dd[u] = 1;
    cc.push_back(u);
    for (int v : c[u]) {
        if (dd[v] == 0)
            dfs(v);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // debugLocal();

    int n, m, u, v;
    cin >> n >> m;
    a.resize(n);
    dd.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    c.resize(n);
    while (m--) {
        cin >> u >> v;
        u--, v--;
        if (u == v)
            continue;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (dd[i] != 0)
            continue;
        dfs(i);
        vector<int> b;
        for (int j : cc)
            b.push_back(a[j]);
        sort(b.begin(), b.end());
        sort(cc.begin(), cc.end());
        for (int j = 0; j < b.size(); j++)
            a[cc[j]] = b[j];
        cc.clear();
    }
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    vector<int> f(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

    return 0;
}
