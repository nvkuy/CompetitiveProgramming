#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> cnt;

void dfs(int u, int par) {
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        cnt[u] += (cnt[v] + 1);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n;
    c.resize(n);
    cnt.assign(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> t;
        c[t - 1].push_back(i);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++)
        cout << cnt[i] << ' ';

    return 0;
}