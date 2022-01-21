#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, ans = 0;
    int mx[4] = {-1, 0, 0, 1};
    int my[4] = {0, 1, -1, 0};
    vector<string> a;
    string s;
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        a.push_back(s);
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#')
                continue;
            q.push(make_pair(i, j));
            a[i][j] = '#';
            ans++;
            //cout << i << ' ' << j << ' ' << ans << endl;
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                //cout << "vis: " << x << ' ' << y << endl;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    if (x + mx[k] >= n || x + mx[k] < 0 || y + my[k] >= m || y + my[k] < 0)
                        continue;
                    if (a[x + mx[k]][y + my[k]] != '#')
                        q.push(make_pair(x + mx[k], y + my[k]));
                    a[x + mx[k]][y + my[k]] = '#';
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
