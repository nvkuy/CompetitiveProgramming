#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long INF = 1e18;
int n;
vector<vector<long long>> c;
vector<vector<int>> trace;

void floyd() {
    for (int i = 1; i <= n; i++)
        c[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i][j] > c[i][k] + c[k][j]) {
                    c[i][j] = max(c[i][k] + c[k][j], -INF);
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

    int m, u, v, q;
    long long cost;
    cin >> n >> m >> q;
    c.assign(n + 1, vector<long long>(n + 1, INF));
    trace.assign(n + 1, vector<int>(n + 1, -1));
    while (m--) {
        cin >> u >> v >> cost;
        if (c[u][v] > cost) {
            c[u][v] = cost;
            trace[u][v] = v;
        }
        if (c[v][u] > cost) {
            c[v][u] = cost;
            trace[v][u] = u;
        }
    }
    floyd();
    while (q--) {
        cin >> u >> v;
        cout << (c[u][v] < 1e17 ? c[u][v] : -1LL) << endl;
        vector<int> path = getPath(u, v);
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << ' ';
        cout << endl;
    }

    return 0;
}
