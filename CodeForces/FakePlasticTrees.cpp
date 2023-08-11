#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<pair<int, int>> range, f;
vector<vector<int>> c;

bool iok(int u, long long x, long long sum_val) {
    for (int v : c[u]) {
        long long rm = x - sum_val + f[v].second;
        if (rm <= f[v].second) return true;
    }
    return false;
}

void dfs(int u) {
    if (c[u].size() == 0) {
        f[u] = {1, range[u].second};
        return;
    }
    int res = 0;
    long long sum_val = 0;
    for (int v : c[u]) {
        dfs(v);
        res += f[v].first;
        sum_val += f[v].second;
    }
    int l = range[u].first, r = range[u].second, m;
    if (!iok(u, l, sum_val)) {
        f[u] = {res + 1, r};
        return;
    }
    while (l < r) {
        m = (l + r + 1) / 2;
        if (iok(u, m, sum_val))
            l = m;
        else
            r = m - 1;
    }
    f[u] = {res, l};
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
        range.clear();
        f.clear();
        c.clear();
        range.resize(n + 1);
        f.resize(n + 1);
        c.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            int u;
            cin >> u;
            c[u].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            cin >> range[i].first >> range[i].second;
        dfs(1);
        cout << f[1].first << endl;
    }

    return 0;
}
