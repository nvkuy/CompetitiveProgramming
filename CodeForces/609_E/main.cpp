#include "bits/stdc++.h"

using namespace std;

const int INF = 1e18;

int n, m;
vector<vector<pair<int, long long>>> c;
vector<long long> dis;
long long BiggestEdge = 0;
vector<int> parent;

long long prim(int s) {
    long long ret = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    fill(dis.begin(), dis.end(), INF);
    int turn = 1;
    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        long long curDis = top.first; int u = top.second;

        if (curDis != dis[u]) continue;

        BiggestEdge = max(BiggestEdge, dis[u]);
        ret += dis[u]; dis[u] = -INF;

        for (auto &e : c[u]) {
            int v = e.first; long long cc = e.second;
            if (dis[v] > cc) {
                dis[v] = cc;
                q.push({dis[v], v});
                parent[v] = u;
            }
        }
    }
    return ret;
}
int main() {

    vector<pair<int, pair<int, int>>> query;
    cin >> n >> m;
    c.clear();
    c.resize(n + 1);
    parent.assign(n + 1, 0);
    dis.assign(n + 1, INF);
    for (int i = 0; i < m; i++) {
        int u, v, cc;
        cin >> u >> v >> cc;
        c[u].push_back({v, cc});
        c[v].push_back({u, cc});
        query.push_back({cc, {u, v}});
    }
    long long mst = prim(1);
    //cout << mst << '|' << BiggestEdge << endl;
    for (int i = 0; i < m; i++) {
        int cc = query[i].first, u = query[i].second.first, v = query[i].second.second;
        if (parent[v] == u || parent[u] == v)
            cout << mst << endl;
        else
            cout << (mst + cc - BiggestEdge) << endl;
    }

    return 0;
}
