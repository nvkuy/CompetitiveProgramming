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
vector<int> distToF;
int white_cell = 1;

void dfsF(int u, int par = 0) {
    for (int v : c[u]) {
        if (v == par) continue;
        distToF[v] = distToF[u] + 1;
        dfsF(v, u);
    }
}

void dfsS(int u, int dist = 0, int par = 0) {
    dist++;
    for (int v : c[u]) {
        if (v == par) continue;
        if (dist < distToF[v]) {
            white_cell++;
            dfsS(v, dist, u);
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
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    distToF.assign(n + 1, 0);
    dfsF(1);
    dfsS(n);
    cout << (2 * white_cell >= n ? "Snuke" : "Fennec") << endl;

    return 0;
}
