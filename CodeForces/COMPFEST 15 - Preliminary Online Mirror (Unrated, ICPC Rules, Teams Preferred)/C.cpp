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

const long long mod = 998244353;
vector<vector<pair<int, int>>> c;
vector<long long> one_cnt, zero_cnt, inv_cnt;
vector<int> vis;

void dfs(int u) {
    
    vis[u] = 1;
    for (auto p : c[u]) {
        if (p.second == 0) {
            inv_cnt[u] += one_cnt[u];
            zero_cnt[u]++;
        } else
            one_cnt[u]++;
        if (!vis[p.first]) dfs(p.first);
        inv_cnt[u] += inv_cnt[p.first];
        inv_cnt[u] += (one_cnt[u] * zero_cnt[p.first]) % mod;
        one_cnt[u] += one_cnt[p.first];
        zero_cnt[u] += zero_cnt[p.first];
        inv_cnt[u] %= mod;
        one_cnt[u] %= mod;
        zero_cnt[u] %= mod;
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    c.clear();
    c.resize(n + 1);
    one_cnt.assign(n + 1, 0);
    zero_cnt.assign(n + 1, 0);
    inv_cnt.assign(n + 1, 0);
    vis.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int si;
        cin >> si;
        for (int j = 0; j < si; j++) {
            int l, w;
            cin >> l >> w;
            c[i].push_back({l, w});
        }
    }

    dfs(1);

    cout << inv_cnt[1] << endl;

    return 0;
}
