#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long INF = 1e18;
int n, m;
vector<vector<pair<int, long long>>> c;
vector<long long> dis, trace;

void dijkstra(int st) {
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
    trace.assign(n + 1, -1);
    dis.assign(n + 1, INF);
    dis[st] = 0, trace[st] = st;
    pq.push(make_pair(st, 0));

    while (pq.size()) {
        int u = pq.top().first;
        long long du = pq.top().second;
        pq.pop();
        if (du != dis[u])
            continue;

        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i].first;
            long long uv = c[u][i].second;
            if (dis[v] > du + uv) {
                dis[v] = du + uv, trace[v] = u;
                pq.push(make_pair(v, dis[v]));
            }
        }
    }
}

vector<int> getPath(int fi) {
    int u = fi;
    vector<int> path;
    path.push_back(u);
    while (u != trace[u] && trace[u] != -1) {
        u = trace[u];
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int u, v, w;
    cin >> n >> m;
    c.resize(n + 1);
    while (m--) {
        cin >> u >> v >> w;
        c[u].push_back({v, w});
        c[v].push_back({u, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ": ";
        vector<int> path = getPath(i);
        for (int j = 0; j < path.size(); j++)
            cout << path[j] << ' ';
        cout << endl;
    }

    return 0;
}
