#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

vector<vector<int>> c;
vector<int> dd;

void dfs(int u) {
    dd[u] = 1;
    for (int v : c[u]) {
        if (!dd[v])
            dfs(v);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edge;
    while (m--) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a - 1, b - 1});
    }
    dd.assign(n, 0);
    c.resize(n);
    for (auto e : edge)
        c[e.first].push_back(e.second);
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (dd[i] == 0) {
            cout << "NO" << endl;
            cout << "1 " << i + 1 << endl;
            return 0;
        }
    }
    c.clear();
    dd.assign(n, 0);
    c.resize(n);
    for (auto e : edge)
        c[e.second].push_back(e.first);
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (dd[i] == 0) {
            cout << "NO" << endl;
            cout << i + 1 << " 1" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    
    return 0;
}
