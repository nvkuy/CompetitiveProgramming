#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long INF = 1e16;
int n;
vector<vector<pair<int, long long>>> c;
vector<vector<int>> trace;
vector<vector<long long>> picked;

void floyd() {
    for (int i = 1; i <= n; i++)
        c[i][i] = {0, 0};
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((c[i][j].second > c[i][k].second + c[k][j].second) || (c[i][j].second == c[i][k].second + c[k][j].second && c[i][j].first < c[i][k].first + c[k][j].first)) {
                    c[i][j] = {c[i][k].first + c[k][j].first, c[i][k].second + c[k][j].second};
                    trace[i][j] = trace[i][k];
                }
            }
        }
    }
}

vector<int> getPath(int u, int v) {
    vector<int> path;
    do {
        path.push_back(u);
        u = trace[u][v];
    } while (u > 0);
    return path;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, u, v;
    long long cost;
    cin >> n >> m;
    c.assign(n + 1, vector<pair<int, long long>>(n + 1, {0, INF}));
    picked.assign(n + 1, vector<long long>(n + 1, INF));
    trace.assign(n + 1, vector<int>(n + 1, -1));
    while (m--) {
        cin >> u >> v >> cost;
        if (c[u][v].second > cost) {
            c[u][v] = {1, cost};
            picked[u][v] = cost;
            trace[u][v] = v;
        }
        if (c[v][u].second > cost) {
            c[v][u] = {1, cost};
            picked[v][u] = cost;
            trace[v][u] = u;
        }
    }
    floyd();
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> path = getPath(i, j);
            for (int k = 1; k < path.size(); k++) {
                u = path[k - 1], v = path[k];
                if (picked[u][v] < INF) {
                    ans += picked[u][v];
                    picked[u][v] = picked[v][u] = INF;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
