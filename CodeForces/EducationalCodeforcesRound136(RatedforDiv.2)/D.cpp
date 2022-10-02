#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<vector<int>> c;
vector<pair<int, int>> f;

void dfs(int u, int par, int maxH) {
    int t1 = 0, t2 = 0;
    for (int v : c[u]) {
        if (v == par)
            continue;
        dfs(v, u, maxH);
        t1 = max(f[v].first, t1);
        t2 += f[v].second;
    }
    f[u] = {t1 + 1, t2};
    if (f[u].first == maxH && u != 0 && par != 0) {
        // cout << "try " << maxH << " cut at " << u << ' ' << f[u].first << endl;
        f[u].first = 0, f[u].second++;
    }
}

bool check(int maxH, int k) {
    f.assign(c.size(), {0, 0});
    dfs(0, -1, maxH);
    return (f[0].second <= k);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n, k, pi;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        c.clear();
        c.resize(n);
        int nzc = 0;
        for (int i = 1; i < n; i++) {
            cin >> pi;
            pi--;
            if (pi != 0)
                nzc++;
            c[pi].push_back(i);
            c[i].push_back(pi);
        }
        if (k >= nzc) {
            cout << 1 << endl;
            continue;
        }
        int l = 2, r = n, m;
        while (l < r) {
            m = (l + r) / 2;
            if (check(m, k))
                r = m;
            else
                l = m + 1;
        }
        cout << r << endl;
    }

    return 0;
}
