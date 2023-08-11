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
const int MAXN = 2e5;
long long per[MAXN + 1];

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

long long ckn(long long n, long long k) {
    if (k > n) return 0;
    return (per[n] * power((per[n - k] * per[k]) % mod, mod - 2)) % mod;
}

vector<int> node_cnt;
vector<vector<int>> c;
long long n, k, good_edge = 0;

void dfs1(int u, int par) {
    node_cnt[u]++;
    for (int v : c[u]) {
        if (v != par) {
            dfs1(v, u);
            node_cnt[u] += node_cnt[v];
        }
    }
}

void dfs2(int u, int par) {
    good_edge = (good_edge + ckn(node_cnt[u], k / 2) * ckn(n - node_cnt[u], k / 2)) % mod;
    for (int v : c[u]) 
        if (v != par) dfs2(v, u);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    per[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        per[i] = (per[i - 1] * i) % mod;

    cin >> n >> k;
    c.resize(n + 1);
    node_cnt.assign(n + 1, 0);
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
    dfs2(1, 0);

    cout << (good_edge * power(ckn(n, k), mod - 2) + 1) % mod << endl;

    return 0;
}
