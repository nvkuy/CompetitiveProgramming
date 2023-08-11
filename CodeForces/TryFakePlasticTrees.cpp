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
    int res = 0;
    long long sum = 0;
    for (int v : c[u]) {
        dfs(v);
        sum += f[v].second;
        res += f[v].first;
    }
    if (sum < range[u].first) {
        f[u] = {res + 1, range[u].second};
        return;
    }
    f[u] = {res, min(sum, range[u].second * 1LL)};
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
