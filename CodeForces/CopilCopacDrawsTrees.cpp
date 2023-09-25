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

vector<vector<pair<int, int>>> c;
int ans;

void dfs(int u, int par = 0, int cur = 0, int val = 1e9) {
    ans = max(ans, cur);
    for (auto p : c[u]) {
        if (p.first == par) continue;
        int next = cur + (val > p.second);
        dfs(p.first, u, next, p.second);
    }
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
        c.clear();
        c.resize(n + 1);
        ans = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            c[u].push_back({v, i});
            c[v].push_back({u, i});
        }
        dfs(1);
        cout << ans << endl;
    }

    return 0;
}
