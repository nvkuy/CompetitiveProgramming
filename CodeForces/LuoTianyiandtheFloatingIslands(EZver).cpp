#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long mod = 1e9 + 7;

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

vector<long long> node_cnt, sum_dist;
long long sum_all = 0, n, k;
vector<vector<int>> c;

void dfs1(int u, int par) {
    node_cnt[u]++;
    for (int v : c[u]) {
        if (v != par) {
            dfs1(v, u);
            node_cnt[u] += node_cnt[v];
            sum_dist[u] += (sum_dist[v] + node_cnt[v]);
        }
    }
}

void dfs2(int u, int par, long long par_sum) {
    long long cur_sum = par_sum + n - node_cnt[u];
    for (int v : c[u])
        if (v != par)
            cur_sum += sum_dist[v] + node_cnt[v];
    sum_all = (sum_all + cur_sum + n - 1) % mod;
    for (int v : c[u])
        if (v != par)
            dfs2(v, u, cur_sum - sum_dist[v] - node_cnt[v]);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    c.resize(n + 1);
    node_cnt.assign(n + 1, 0);
    sum_dist.assign(n + 1, 0);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    if (k % 2) {
        // imbalance => only way
        cout << 1 << endl;
        return 0;
    }

    dfs1(1, 0);
    dfs2(1, 0, 0);
    // cout << "@sum_all: " << sum_all << endl;
    // cout << "@all_way: " << n * (n - 1) / 2 << endl; 
    cout << (((sum_all * power(2, mod - 2)) % mod) * power((n * (n - 1) / 2) % mod, mod - 2)) % mod << endl;

    return 0;
}
