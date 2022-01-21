#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test_input.txt", "r", stdin);
    int n, m;
    pair<int, int> sta = make_pair(0, 0), fin = make_pair(0, 0);
    int mx[4] = {-1, 0, 0, 1};
    int my[4] = {0, 1, -1, 0};
    char mo[4] = {'D', 'L', 'R', 'U'};
    string s;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'A')
                sta = make_pair(i, j);
            if (s[j] == 'B')
                fin = make_pair(i, j);
            if (s[j] == '#')
                a[i][j] = -3;
            else
                a[i][j] = -4;
        }
    }
    queue<pair<int, int>> q;
    string trace;
    int ans = -1, x, y;
    q.push(sta);
    a[sta.first][sta.second] = 0;
    while (!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            if (x + mx[k] >= n || x + mx[k] < 0 || y + my[k] >= m || y + my[k] < 0)
                continue;
            if ((x + mx[k] == fin.first) && (y + my[k] == fin.second)) {
                ans = a[x][y] + 1;
                x += mx[k]; y += my[k];
                break;
            }
            if (a[x + mx[k]][y + my[k]] == -4) {
                q.push(make_pair(x + mx[k], y + my[k]));
                a[x + mx[k]][y + my[k]] = a[x][y] + 1;
            }
        }
        if (ans >= 0)
            break;
    }
    if (ans < 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl << ans << endl;
    while (x != sta.first || y != sta.second) {
        for (int k = 0; k < 4; k++) {
            if (x + mx[k] >= n || x + mx[k] < 0 || y + my[k] >= m || y + my[k] < 0)
                continue;
            if (a[x + mx[k]][y + my[k]] == (ans - 1)) {
                trace.push_back(mo[k]);
                x += mx[k]; y += my[k];
                ans--;
                break;
            }
        }
    }
    reverse(trace.begin(), trace.end());
    cout << trace;

    return 0;
}
