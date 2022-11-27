#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
vector<vector<pair<int, long long>>> c;
vector<vector<long long>> dis;
vector<int> shop_mask;

void dijkstra(int st, int k, int n) {
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
    dis.assign(n + 1, vector<long long>(1 << k, INF));
    dis[st][shop_mask[st]] = 0;
    pq.push({0LL, {st, shop_mask[st]}});

    while (pq.size()) {
        auto state = pq.top();
        pq.pop();
        int u = state.second.first;
        int mask = state.second.second;
        long long du = state.first;
        if (du != dis[u][mask])
            continue;

        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i].first, next_mask = (mask | shop_mask[v]);
            long long uv = c[u][i].second;
            if (dis[v][next_mask] > du + uv) {
                dis[v][next_mask] = du + uv;
                pq.push({dis[v][next_mask], {v, next_mask}});
            }
        }
    }
}

long long shop(int n, int k, vector<vector<int>> centers, vector<vector<int>> roads) {
    c.clear();
    c.resize(n + 1);
    for (auto p : roads) {
        c[p[0]].push_back({p[1], p[2]});
        c[p[1]].push_back({p[0], p[2]});
    }
    shop_mask.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int b : centers[i])
            shop_mask[i] |= (1 << (b - 1));
    }
    dijkstra(1, k, n);
    long long ans = INF;
    for (int mask1 = 0; mask1 < (1 << k); mask1++) {
        for (int mask2 = 0; mask2 < (1 << k); mask2++) {
            if ((mask1 | mask2) == (1 << k) - 1) {
                ans = min(ans, max(dis[n][mask1], dis[n][mask2]));
                // cout << dis[n][mask1] << '|' << dis[n][mask2] << endl;
            }
        }
    }
    // cout << dis[n][(1 << k) - 1 - (1 << 2)] << endl;
    // cout << dis[n][(1 << k) - 1 - (1 << 1) - (1 << 3)] << endl;
    return ans;
}

int main()
{

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> centers(n + 1);

    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        centers[i].resize(sz);
        for (int j = 0; j < sz; j++)
            cin >> centers[i][j];
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);
        for (int j = 0; j < 3; j++)
            cin >> roads[i][j];
    }

    cout << shop(n, k, centers, roads) << endl;

    return 0;
}
