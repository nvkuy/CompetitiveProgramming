#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, m;
vector<vector<int>> dd, c;
vector<pair<int, pair<int, int>>> sh;

bool canGo(int x, int y, int h) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (dd[x][y] == 1 || c[x][y] > h)
        return false;
    return true;
}

void dfs(int x, int y) {
    dd[x][y] = 1;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (canGo(x + i, y + j, c[x][y]))
                dfs(x + i, y + j);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int hij, ans = 0;
    cin >> n >> m;
    dd.assign(n, vector<int>(m, 0));
    c.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> hij;
            c[i][j] = hij;
            sh.push_back({hij, {i, j}});
        }
    }
    sort(sh.begin(), sh.end(), greater<pair<int, pair<int, int>>>());
    for (int i = 0; i < sh.size(); i++) {
        pair<int, int> cor = sh[i].second;
        if (canGo(cor.first, cor.second, 1e9)) {
            dfs(cor.first, cor.second);
            ans++;
        }
    }
    cout << ans;

    return 0;
}
