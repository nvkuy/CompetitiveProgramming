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
vector<long long> s, best_remain;
long long ans;

void dfs(int u, int path, long long val_path = 0) {
    val_path += s[u];
    if (c[u].size() == 0) {
        ans += path * val_path;
        best_remain[u] = val_path;
        return;
    }
    int child_path = path / c[u].size(), rm = path % c[u].size();
    vector<long long> val_child;
    for (int v : c[u]) {
        dfs(v, child_path, val_path);
        val_child.push_back(best_remain[v]);
    }
    sort(val_child.begin(), val_child.end(), greater<long long>());
    best_remain[u] = val_child[rm];
    for (int i = 0; i < rm; i++)
        ans += val_child[i];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        c.clear();
        c.resize(n + 1);
        s.resize(n + 1);
        best_remain.resize(n + 1);
        ans = 0;
        for (int i = 2; i <= n; i++) {
            int par;
            cin >> par;
            c[par].push_back(i);
        }
        for (int i = 1; i <= n; i++) cin >> s[i];
        dfs(1, k);
        cout << ans << endl;
    }

    return 0;
}
