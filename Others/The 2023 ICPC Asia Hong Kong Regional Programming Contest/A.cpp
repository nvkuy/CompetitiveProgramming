#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> f;

void dfs(int u, int par = 0) {

    vector<int> cf;
    for (int v : c[u]) {
        if (v == par) continue;
        dfs(v, u);
        cf.push_back(f[v]);
    }
    sort(cf.begin(), cf.end());
    if (cf.size() > 0)
        f[u] = cf.back();
    if (cf.size() > 1 && cf[cf.size() - 1] == cf[cf.size() - 2])
        f[u]++;

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
        f.assign(n + 1, 1);
        c.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            c[i].push_back(u);
            c[u].push_back(i);
        }
        dfs(1);
        cout << f[1] << endl;
    }

    return 0;
}
