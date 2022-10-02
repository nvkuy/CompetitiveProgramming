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

int n;
vector<vector<int>> c;
vector<int> dis;

void dfs(int u, int par) {
    for (int v : c[u]) {
        if (v == par)
            continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}

int farestFromU(int u) {
    dis.assign(n, 0);
    dfs(u, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (dis[ans] < dis[i])
            ans = i;
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int u, v;
    cin >> n;
    c.resize(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    cout << dis[farestFromU(farestFromU(0))] << endl;

    return 0;
}
