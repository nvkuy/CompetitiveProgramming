#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;

void place(int u, int par, int dr) {
    if (c[u].size() % 2) {
        cout << u << ' ';
        for (int v : c[u]) {
            if (v != par)
                place(v, u, 1);
        }
        return;
    }
    int pl = (c[u].size() / 2) - (dr == 1);
    if (pl == 0)
        cout << u << ' ';
    for (int v : c[u]) {
        if (v == par)
            continue;
        if (pl > 0) {
            place(v, u, -1);
            pl--;
            if (pl == 0)
                cout << u << ' ';
        } else
            place(v, u, 1);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, u, v;
    cin >> n;
    c.resize(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    place(0, -1, 0);

    return 0;
}