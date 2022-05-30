#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, m;
vector<vector<int>> c;
vector<vector<int>> trace;
//L D R U
//vector<int> mx = {0, 1, 0, -1}, my = {-1, 0, 1, 0};
//vector<char> mm = {'R', 'U', 'L', 'D'};
vector<int> mx = {1, 0, -1, 0}, my = {0, -1, 0, 1};
vector<char> mm = {'U', 'R', 'D', 'L'};
vector<char> mm2 = {'D', 'L', 'U', 'R'};

int prio(char cc) {
    if (cc == '?')
        return 1e9;
    if (cc == 'U')
        return 3;
    if (cc == 'R')
        return 2;
    if (cc == 'D')
        return 1;
    return 0;
}

int charToInt(char mc) {
    if (mc == '.')
        return 0;
    if (mc == 'E')
        return 1;
    if (mc == 'X')
        return 2;
    return 3;
}

bool canGo(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return c[x][y] < 2;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    trace[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> v = u;
            v.first += mx[i], v.second += my[i];
            if (!canGo(v.first, v.second) || trace[v.first][v.second] != 1e9)
                continue;
            q.push(v);
            trace[v.first][v.second] = trace[u.first][u.second] + 1;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("output.out", "w", stdout);

    int x, y, q;
    string s;
    cin >> n >> m;
    cin.ignore();
    c.assign(n, vector<int>(m));
    trace.assign(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < m; j++) {
            c[i][j] = charToInt(s[j]);
            if (s[j] == 'E')
                x = i, y = j;
        }
    }
    //cout << x << ' ' << y << endl;
    bfs(x, y);

    cin >> q;
    while (q--) {
        cin >> x >> y;
        x--, y--;
        if (!canGo(x, y)) {
            if (x < 0 || x >= n || y < 0 || y >= m) {
                cout << "?" << endl;
                continue;
            }
            if (c[x][y] == 2)
                cout << "X" << endl;
            else
                cout << "W" << endl;
        } else {
            if (trace[x][y] == 1e9) {
                cout << "?" << endl;
                continue;
            }
            if (trace[x][y] == 0) {
                cout << "E" << endl;
                continue;
            }
            char ans = '?';
            for (int i = 0; i < 4; i++) {
                int xt = x + mx[i], yt = y + my[i];
                if (canGo(xt, yt) && trace[x][y] == trace[xt][yt] + 1 && prio(ans) > prio(mm2[i])) {
                    ans = mm2[i];
                    //cout << trace[xt][yt] << '|' << mm2[i] << endl;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
