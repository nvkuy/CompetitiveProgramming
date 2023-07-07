#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> dd;
int money;

void dfs(int u, int root) {
    dd[u] = 1;
    for (int v : c[u]) {
        if (!dd[v]) {
            if (u == root) money++;
            dfs(v, root);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    c.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        c[i].push_back(u);
        c[i].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        dd.assign(n + 1, 0);
        money = -1;
        dfs(i, i);
        cout << (money < 0 ? "Y" : "N");
        // cout << money << endl;
    }
    cout << endl;

    return 0;
}
