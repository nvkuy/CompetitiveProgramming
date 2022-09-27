#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugMode() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

struct edge {
    int to, ai, bi;
};

vector<vector<edge>> c;
vector<long long> pf;
vector<int> r;

void dfs(int u, int par, long long sumA, long long sumB) {
    pf.push_back(sumB);
    int p = upper_bound(pf.begin(), pf.end(), sumA) - pf.begin();
    p--;
    r[u] = p;
    for (edge e : c[u]) {
        if (e.to == par)
            continue;
        dfs(e.to, u, sumA + e.ai, sumB + e.bi);
    }
    pf.pop_back();
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugMode();

    int t, p, a, b, n;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        r.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            cin >> p >> a >> b;
            c[p].push_back({i, a, b});
            c[i].push_back({p, a, b});
        }
        dfs(1, 0, 0, 0);
        for (int i = 2; i <= n; i++)
            cout << r[i] << ' ';
        cout << endl;
    }

    return 0;
}
