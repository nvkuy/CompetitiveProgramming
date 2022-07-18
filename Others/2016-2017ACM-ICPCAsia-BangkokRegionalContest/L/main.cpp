#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Edge {
    int to;
    int dx, dy;
    Edge(int u, int x, int y) {
        to = u;
        dx = x, dy = y;
    }
};

vector<pair<int, int>> base_cor;
vector<int> dd;
vector<vector<Edge>> c;

void dfs(int u) {
    dd[u] = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i].to;
        if (dd[v] == 0) {
            int x = base_cor[u].first + c[u][i].dx;
            int y = base_cor[u].second + c[u][i].dy;
            base_cor[v] = {x, y};
            dfs(v);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, dx, dy;
    cin >> n >> m;
    dd.assign(n + 1, 0);
    base_cor.resize(n + 1);
    c.resize(n + 1);
    while (m--) {
        cin >> a >> b >> dx >> dy;
        c[a].push_back(Edge(b, dx, dy));
        c[b].push_back(Edge(a, -dx, -dy));
    }
    base_cor[1] = {0, 0};
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << base_cor[i].first << ' ' << base_cor[i].second << endl;

    return 0;
}
