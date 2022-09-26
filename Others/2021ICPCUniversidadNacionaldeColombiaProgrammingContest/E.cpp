#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<long long> dd;

void dfs(int u, int val_par, int par) {
    int num = c[u].size() / 2;
    int numLessThan = num;
    if (val_par < dd[u])
        numLessThan--;
    for (int v : c[u]) {
        if (v == par)
            continue;
        if (numLessThan > 0) {
            numLessThan--;
            dd[v] = dd[u] - 1;
        } else
            dd[v] = dd[u] + 1;
        if (c[v].size() % 2 == 0)
            dfs(v, dd[u], u);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, u, v;
    cin >> n;
    c.resize(n);
    dd.assign(n, 1e9);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (dd[i] < 1e9 || c[i].size() % 2 == 1)
            continue;
        dd[i] = 0;
        dfs(i, 0, -1);
    }
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i++)
        tmp.push_back({dd[i], i});
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++)
        cout << tmp[i].second << ' ';

    return 0;
}