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

int h, need;
vector<vector<int>> c;
vector<int> rm;

void dfs(int u, int par = 0) {
    for (int v : c[u]) {
        dfs(v, u);
        rm[u] = max(rm[u], rm[v]);
    }
    rm[u]++;
    if (rm[u] == h && par > 1) {
        need++;
        rm[u] = 0;
    }
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
        c.assign(n + 1, vector<int>());
        rm.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            int par;
            cin >> par;
            c[par].push_back(i);
        }
        int l = 1, r = n, m;
        while (l < r) {
            m = (l + r) / 2;
            h = m, need = 0;
            fill(rm.begin(), rm.end(), 0);
            dfs(1);
            if (need > k) l = m + 1;
            else r = m;
        }
        cout << r << endl;
    }

    return 0;
}
