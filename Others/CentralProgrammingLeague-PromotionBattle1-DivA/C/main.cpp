#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


const int INF = 1e18;

int n, m;
vector<vector<pair<int, long long>>> c;
vector<long long> dis;
bitset<33> bf;

vector<bool> dd;
void dfs(int u) {
    dd[u] = true;
    for (int i = 0; i < c[u].size(); i++) {
        if (!dd[c[u][i].first] && bf[c[u][i].first])
            dfs(c[u][i].first);
    }
}

bool isConnect(int s) {
    dd.assign(n + 1, false);
    dfs(s);
    for (int i = 1; i <= n; i++) {
        if (bf[i] && !dd[i])
            return false;
    }
    return true;
}

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
            if (!bf[v])
                continue;
            if (dis[v] > cc) {
                dis[v] = cc;
                q.push({dis[v], v});
            }
        }
    }
    return ret;
}

void dijkstra(int st) {
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[st] = 0;
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
                dis[v] = du + uv;
                pq.push(make_pair(v, dis[v]));
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, u, v, w;
    cin >> n >> k >> m;
    vector<int> in(k);
    c.resize(n + 1), dis.resize(n + 1);
    for (int i = 0; i < k; i++)
        cin >> in[i];
    while (m--) {
        cin >> u >> v >> w;
        c[u].push_back({v, w});
        c[v].push_back({u, w});
    }
    if (k <= 1) {
        cout << "0";
        return 0;
    }
    if (k == 2) {
        dijkstra(in[0]);
        cout << dis[in[1]];
        return 0;
    }
    if (n <= 30) {
        long long ans = INF;
        for (int i = 0; i < (1 << n); i++) {
            bf = bitset<33>(i);
            for (int j = 30; j >= 1; j--)
                bf[j] = bf[j - 1];
            for (int j = 0; j < k; j++)
                bf[in[j]] = true;
            if (!isConnect(in[0]))
                continue;
            ans = min(ans, prim(in[0]));
        }
        cout << ans;
        return 0;
    }

    return 0;
}
