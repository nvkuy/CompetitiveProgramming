#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<pair<int, int>>> c;
vector<long long> cor;
bool iok = true;

void dfs(int u, long long pos = 0) {
    cor[u] = pos;
    for (auto p : c[u]) {
        if (cor[p.first] == 1e18)
            dfs(p.first, pos + p.second);
        else {
            if (cor[u] + p.second != cor[p.first]) {
                iok = false;
                return;
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        c.clear();
        c.resize(n + 1);
        cor.assign(n + 1, 1e18);
        while (m--) {
            int u, v, d;
            cin >> u >> v >> d;
            c[u].push_back({v, d});
            c[v].push_back({u, -d});
        }

        iok = true;
        for (int i = 1; i <= n; i++) {
            if (!iok) break;
            if (cor[i] == 1e18)
                dfs(i);
        }

        cout << (iok ? "YES" : "NO") << endl;

    }

    return 0;
}
