#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, inf = 1e9;
    int mx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, my[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    cin >> n >> m;
    vector<vector<int>> dd(n, vector<int>(m, 0)), dist(n, vector<int>(m, inf));
    for (int i = 2; i + 2 < n; i++)
        for (int j = 2; j + 2 < m; j++)
            dd[i][j] = 1;

    queue<pair<int, int>> q;
    dist[0][0] = 0;
    dd[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        // cout << "@q: " << q.size() << endl;
        pair<int, int> u = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            pair<int, int> v = {u.first + mx[i], u.second + my[i]};
            if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m || dd[v.first][v.second]) continue;
            dist[v.first][v.second] = dist[u.first][u.second] + 1;
            dd[v.first][v.second] = 1;
            q.push(v);
        }
    }

    int ans = 2 * dist[n - 1][m - 1];
    for (int i = 2; i < n; i++) {
        for (int j = m - 2; j < m; j++) {
            if (!dd[i][j]) continue;
            for (int k = 0; k < 8; k++) {
                int nx = i + mx[k], ny = j + my[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || abs(nx - n - 1) + abs(ny) > abs(nx) + abs(m - ny - 1) || !dd[nx][ny]) continue;
                ans = min(ans, dist[i][j] + dist[nx][ny] + 1);
            }
        }
    }

    if (ans >= inf) ans = 0;
    cout << ans << endl;

    return 0;
}
