#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long INF = 1e18;
int n, m;
vector<vector<pair<int, long long>>> c;
vector<map<int, int>> edges;
vector<long long> dis, trace;
vector<int> pickedEdge, vis;

void dijkstra(int st) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    trace.assign(n + 1, -1);
    dis.assign(n + 1, INF);
    dis[st] = 0, trace[st] = st;
    pq.push(make_pair(0, st));

    while (pq.size()) {
        int u = pq.top().second;
        long long du = pq.top().first;
        pq.pop();
        if (du != dis[u])
            continue;

        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i].first;
            long long uv = c[u][i].second;
            if (dis[v] > du + uv) {
                dis[v] = du + uv, trace[v] = u;
                pq.push(make_pair(dis[v], v));
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
    return path;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int u, v, w;
    cin >> n >> m;
    c.resize(n + 1);
    edges.resize(n + 1);
    pickedEdge.assign(m + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        c[u].push_back({v, w});
        c[v].push_back({u, w});
        edges[u].insert({v, i});
        edges[v].insert({u, i});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        vector<int> path = getPath(i);
        for (int j = 1; j < path.size(); j++) {
            u = path[j - 1], v = path[j];
            int edge = edges[u][v];
            if (pickedEdge[edge] != 0)
                break;
            pickedEdge[edge] = 1;
            vis[u] = vis[v] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (pickedEdge[i] != 0)
            cout << i << ' ';
    }

    return 0;
}
