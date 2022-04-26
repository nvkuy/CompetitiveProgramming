#include "bits/stdc++.h"

using namespace std;

const int INF = 1e18;

int n, m;
vector<vector<pair<int, long long>>> c;
vector<long long> dis;

long long prim(int s) {
    long long ret = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    fill(dis.begin(), dis.end(), INF);

    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        long long curDis = top.first; int u = top.second;

        if (curDis != dis[u]) continue;

        ret += dis[u]; dis[u] = -INF;

        for (auto &e : c[u]) {
            int v = e.first; long long cc = e.second;
            if (dis[v] > cc) {
                dis[v] = cc;
                q.push({dis[v], v});
            }
        }
    }
    return ret;
}
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    c.clear();
    c.resize(n + 1);
    dis.assign(n + 1, INF);
    for (int i = 1; i <= m; i++) {
        int u, v, cc;
        cin >> u >> v >> cc;
        c[u].push_back({v, cc});
        c[v].push_back({u, cc});
    }

    cout << prim(1) << '\n';
}
