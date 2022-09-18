#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<pair<int, int>> t1, t2;
vector<int> dd;

void dfs(int u) {
    dd[u] = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (dd[v] == 0) {
            t1.push_back({u, v});
            dfs(v);
        }
    }
}

void bfs(int s) {

    queue<int> q;
    q.push(s);
    dd[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i];
            if (dd[v] == 0) {
                t2.push_back({u, v});
                dd[v] = 1;
                q.push(v);
            }
        }
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;
    c.resize(n + 1);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dd.assign(n + 1, 0);
    dfs(1);
    dd.assign(n + 1, 0);
    bfs(1);
    for (int i = 0; i < t1.size(); i++)
        cout << t1[i].first << ' ' << t1[i].second << endl;
    for (int i = 0; i < t2.size(); i++)
        cout << t2[i].first << ' ' << t2[i].second << endl;

    return 0;
}
