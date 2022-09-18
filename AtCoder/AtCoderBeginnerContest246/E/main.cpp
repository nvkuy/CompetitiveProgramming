#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<vector<bool>> c;
vector<vector<int>> dd;

bool canGo(int x, int y, int d) {
    if (x < 1 || y < 1 || x > n || y > n || dd[x][y] < d + 1 || c[x][y] == false)
        return false;
    return true;
}

void bfs(int xs, int ys, int xf, int yf) {
    dd.assign(n + 1, vector<int>(n + 1, 1e9));
    if (!c[xs][ys])
        return;
    dd[xs][ys] = 0;
    queue<pair<int, int>> q;
    q.push({xs, ys});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int d = 1; d <= n; d++) {
            if (canGo(x + d, y + d, dd[x][y])) {
                dd[x + d][y + d] = dd[x][y] + 1;
                q.push({x + d, y + d});
            } else
                break;
        }
        for (int d = 1; d <= n; d++) {
            if (canGo(x - d, y + d, dd[x][y])) {
                dd[x - d][y + d] = dd[x][y] + 1;
                q.push({x - d, y + d});
            } else
                break;
        }
        for (int d = 1; d <= n; d++) {
            if (canGo(x + d, y - d, dd[x][y])) {
                dd[x + d][y - d] = dd[x][y] + 1;
                q.push({x + d, y - d});
            } else
                break;
        }
        for (int d = 1; d <= n; d++) {
            if (canGo(x - d, y - d, dd[x][y])) {
                dd[x - d][y - d] = dd[x][y] + 1;
                q.push({x - d, y - d});
            } else
                break;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int xs, ys, xf, yf;
    string s;
    cin >> n;
    c.assign(n + 1, vector<bool>(n + 1, false));
    cin >> xs >> ys >> xf >> yf;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        for (int j = 1; j <= n; j++)
            c[i][j] = (s[j - 1] == '.');
    }
    bfs(xs, ys, xf, yf);
    if (dd[xf][yf] >= 1e9)
        dd[xf][yf] = -1;
    cout << dd[xf][yf];

    return 0;
}
