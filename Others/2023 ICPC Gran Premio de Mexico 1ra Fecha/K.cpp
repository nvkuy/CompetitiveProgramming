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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ns, ne;
    cin >> n >> ns >> ne;
    vector<int> s(ns), e(ne);
    vector<vector<int>> c(n + 1);
    for (int i = 0; i < ns; i++) cin >> s[i];
    for (int i = 0; i < ne; i++) cin >> e[i];

    int m;
    cin >> m;
    vector<int> vis(n + 1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    int ans = 0;
    while (true) {
        vector<int> pre(n + 1, -1), dist(n + 1, 1e9);
        vector<int> dd(n + 1, 0);
        queue<int> q;
        for (int u : s) {
            if (!vis[u]) {
                q.push(u);
                dist[u] = 0;
                dd[u] = 1;
            }
        }
        while (q.size() > 0) {
            int u  = q.front(); q.pop();
            for (int v : c[u]) {
                if (!vis[v] && !dd[v]) {
                    dd[v] = 1;
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    pre[v] = u;
                }
            }
        }
        int min_node = -1;
        for (int u : e) {
            if (!vis[u] && dd[u] && (min_node == -1 || dist[min_node] > dist[u])) min_node = u;
        }
        if (min_node == -1) break;
        ans++;
        while (min_node != -1) {
            vis[min_node] = 1;
            min_node = pre[min_node];
        }
    }

    cout << ans << endl;

    return 0;
}
