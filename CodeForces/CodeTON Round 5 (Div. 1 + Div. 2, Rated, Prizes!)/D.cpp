#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c, w;
vector<int> vis, done;
vector<pair<string, int>> ans;

void dfs(int u) {

    vis[u] = 1;
    for (int v : c[u]) {
        if (!vis[v])
            dfs(v);
    }

}

void findDoneNode(int u) {

    vis[u] = 1;
    for (int v : c[u]) {
        if (!vis[v] && w[u][v] == 0) {
            done.push_back(v);
            findDoneNode(v);
        }
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    w.assign(n + 1, vector<int>(n + 1, 0));
    while (m--) {
        int u, v, y;
        cin >> u >> v >> y;
        c[u].push_back(v);
        c[v].push_back(u);
        w[u][v] = w[v][u] = y;
    }

    vis.assign(n + 1, 0);
    dfs(1);
    if (!vis[n]) {
        cout << "inf" << endl;
        return 0;
    }

    vis.assign(n + 1, 0);
    done.push_back(n);
    long long play_time = 0;
    while (true) {

        for (int i = 0; i < done.size(); i++)
            findDoneNode(done[i]);

        if (vis[1]) 
            break;

        string play_round(n, '1');
        int min_time = 2e9;
        for (int u : done) {
            play_round[u - 1] = '0';
            for (int v : c[u])
                if (!vis[v])
                    min_time = min(min_time, w[u][v]);
        }
        for (int u : done) {
            for (int v : c[u]) {
                if (!vis[v]) {
                    w[u][v] -= min_time;
                    w[v][u] -= min_time;
                }
            }
        }

        ans.push_back({play_round, min_time});
        play_time += min_time;

    }

    cout << play_time << ' ' << ans.size() << endl;
    for (auto p : ans)
        cout << p.first << ' ' << p.second << endl;

    return 0;
}
