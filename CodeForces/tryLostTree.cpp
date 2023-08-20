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

vector<vector<int>> dist;
int n;

void query(int r) {
    cout << "? " << r << endl;
    cout.flush();
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        dist[r][i] = dist[i][r] = d;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dist.assign(n + 1, vector<int>(n + 1, 1e9));

    query(1);
    vector<int> c1, c2;
    for (int i = 1; i <= n; i++) {
        if (dist[i][1] % 2 == 0) c1.push_back(i);
        else c2.push_back(i);
    }
    if (c1.size() > c2.size()) swap(c1, c2);
    for (int u : c1) {
        if (u == 1) continue;
        query(u);
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dist[i][j] == 1) edges.push_back({i, j});
        }
    }

    cout << "! " << endl;
    for (auto e : edges) cout << e.first << ' ' << e.second << endl;
    cout.flush();

    return 0;
}
