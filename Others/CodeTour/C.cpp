#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int dd[202][202], dist[202][202];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> block(n);
    int max_cor = 0;
    for (int i = 0; i < n; i++) {
        cin >> block[i].first >> block[i].second;
        max_cor = max(max_cor, block[i].first);
        max_cor = max(max_cor, block[i].second);
    }

    int m;
    cin >> m;
    vector<pair<int, int>> point(m);
    for (int i = 0; i < m; i++) {
        cin >> point[i].first >> point[i].second;
        max_cor = max(max_cor, point[i].first);
        max_cor = max(max_cor, point[i].second);
    }

    if (max_cor <= 100 && n != 0) {
        //bfs
        for (int i = 0; i < n; i++)
            block[i] = {block[i].first + 100, block[i].second + 100};
        for (int i = 0; i < m; i++)
            point[i] = {point[i].first + 100, point[i].second + 100};

        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        long long ans = 1e18;
        for (int tx = 0; tx <= max_cor; tx++) {
        for (int ty = 0; ty <= max_cor; ty++) {
            pair<int, int> st = {tx, ty};
            queue<pair<int, int>> q;
            for (int i = 0; i <= max_cor; i++) {
                for (int j = 0; j <= max_cor; j++) {
                    dd[i][j] = 0;
                    dist[i][j] = 1e9;
                }
            }
            for (auto p : block)
                dd[p.first][p.second] = 1;
            if (dd[st.first][st.second] == 1) continue;
            q.push(st);
            dd[st.first][st.second] = 1;
            dist[st.first][st.second] = 0;

            while (!q.empty()) {
                pair<int, int> u = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = u.first + dx[i], ny = u.second + dy[i];
                    if (nx >= 0 && nx <= max_cor + 100 && ny >= 0 && ny <= max_cor + 100 && !dd[nx][ny]) {
                        q.push({nx, ny});
                        dd[nx][ny] = 1;
                        dist[nx][ny] = dist[u.first][u.second] + 1;
                    }
                }
            }

            bool hasAns = true;
            for (auto p : point)
                if (!dd[p.first][p.second]) hasAns = false;
            if (!hasAns) {
                cout << -1 << endl;
                return 0;
            }
            long long dis = 0;
            for (auto p: point)
                dis += dist[p.first][p.second];
            ans = min(ans, dis);
            // cout << tx << ' ' << ty << ' ' << dis << endl;
        }
        }

        cout << ans << endl;

        return 0;
    }
    // n = 0;
    long long sum_x = 0, sum_y = 0;
    long long ans1 = 0;
    for (auto p : point) {
        sum_x += p.first;
        sum_y += p.second;
    }
    long long x = sum_x / m, y = sum_y / m;
    for (auto p : point) ans1 += (abs(p.first - x) + abs(p.second - y));

    long long ans = 1e18;
    for (auto p : point) {
        long long tans = 0;
        for (auto np : point)
            tans += (abs(p.first - np.first) + abs(p.second - np.second));
        ans = min(ans, tans);
    }
    cout << min(ans, ans1) << endl;

    return 0;
}
