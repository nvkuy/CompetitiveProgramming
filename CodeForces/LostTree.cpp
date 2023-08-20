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

vector<vector<int>> dist, c;
vector<int> vis;
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

void dfs(int u, int par) {

    query(u);

    vis[u] = 1;
    int mid = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[u][i] == 1) {
            c[u][i] = c[i][u] = 1;
            if (dist[par][i] == 1) mid = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[u][i] == dist[par][i]) {
            if (dist[u][i] == 2) c[mid][i] = c[i][mid] = vis[i] = 1;
            dist[mid][i] = dist[i][mid] = dist[u][i] - 1;
        } else dist[mid][i] = dist[i][mid] = min(dist[u][i], dist[par][i]) + 1;
    }
    vis[mid] = 1;

    for (int v = 1; v <= n; v++) {
        if (dist[u][v] == 2 && dist[par][v] == 4 && !vis[v]) dfs(v, u);
        if (dist[u][v] == 3 && dist[par][v] == 3 && !vis[v]) dfs(v, mid);
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dist.assign(n + 1, vector<int>(n + 1, 1e9));
    c.assign(n + 1, vector<int>(n + 1));
    vis.assign(n + 1, 0);

    query(1);
    vis[1] = 1;
    for (int u = 1; u <= n; u++) {
        if (dist[u][1] == 1) c[u][1] = c[1][u] = 1;
        if (dist[u][1] == 2 && !vis[u]) dfs(u, 1);
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (c[i][j]) edges.push_back({i, j});
        }
    }

    cout << "! " << endl;
    for (auto e : edges) cout << e.first << ' ' << e.second << endl;
    cout.flush();

    return 0;
}
