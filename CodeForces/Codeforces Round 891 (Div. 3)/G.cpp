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
vector<int> par;

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (num >= mod) return power(num % mod, pow);
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power(num * num, pow / 2);
}

int getRoot(int u) {
    if (par[u] < 0) return u;
    return (par[u] = getRoot(par[u]));
}

int getSize(int u) {
    int r = getRoot(u);
    return -par[r];
}

void merge(int u, int v) {
    int p1 = getRoot(u), p2 = getRoot(v);
    if (getSize(p1) < getSize(p2)) swap(p1, p2);
    par[p1] += par[p2];
    par[p2] = p1;
}

struct Edge {
    int u, v, w;
    bool operator < (const Edge &e) const {
        return w < e.w;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;
        par.assign(n + 1, -1);
        vector<Edge> edges;
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        sort(edges.begin(), edges.end());
        long long ans = 1;
        for (auto &e : edges) {
            long long c1 = getSize(e.u), c2 = getSize(e.v), ew = s - e.w + 1;
            long long canAdd = c1 * c2 - 1;
            ans = (ans * power(ew, canAdd)) % mod;
            merge(e.u, e.v);
        }
        cout << ans << endl;
    }

    return 0;
}
