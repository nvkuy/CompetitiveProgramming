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
int ans = 0;

void dfs(int u, int par) {
    for (int v : c[u]) {
        if (v == par)
            continue;
        dfs(v, u);
        if (dd[v] == 0 && dd[u] == 0) {
            dd[v] = 1, dd[u] = 1;
            ans++;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, u, v;
    cin >> n;
    c.resize(n);
    dd.assign(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans << endl;

    return 0;
}