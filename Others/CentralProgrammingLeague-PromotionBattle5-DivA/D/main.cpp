#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long INF = 1e18;
int n, m;
vector<vector<long long>> c;
vector<vector<long long>> dis;
int mx[4] = {-1, 0, 0, 1}, my[4] = {0, -1, 1, 0};

long long dijkstra(int xs, int ys) {
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
    dis.assign(n, vector<long long>(m, INF));
    dis[xs][ys] = c[xs][ys];
    pq.push({dis[xs][ys], {xs, ys}});

    while (pq.size()) {
        pair<int, int> cor = pq.top().second;
        int ux = cor.first, uy = cor.second;
        //cout << "vis: " << ux << ' ' << uy << endl;
        long long du = pq.top().first;
        pq.pop();
        if (du != dis[ux][uy])
            continue;
        for (int i = 0; i < 4; i++) {
            int vx = ux + mx[i], vy = uy + my[i];
            if (vx < 0 || vx >= n)
                continue;
            if (vy < 0 || vy >= m)
                continue;
            long long uv = c[vx][vy];
            if (dis[vx][vy] > du + uv) {
                dis[vx][vy] = du + uv;
                pq.push({dis[vx][vy], {vx, vy}});
            }
        }
    }

    long long ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dis[i][m - 1]);
        //cout << xs << '|' << ys << "->" << i << '|' << m - 1 << ':' << dis[i][m - 1] << endl;
    }
    return ans;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    c.assign(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    long long ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, dijkstra(i, 0));
    cout << ans;

    return 0;
}
