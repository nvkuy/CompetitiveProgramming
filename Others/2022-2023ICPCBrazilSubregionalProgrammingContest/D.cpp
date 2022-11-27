#include <bits/stdc++.h>
using namespace std;

int bfs(int s, int t, int n) {
    int nn = (1 << n);
    vector<int> dd(nn + 1, 1e9);
    dd[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return dd[t];
        int v1 = (u + nn) / 2, v2 = u / 2;
        if (dd[v1] == 1e9) {
            dd[v1] = dd[u] + 1;
            q.push(v1);
        }
        if (dd[v2] == 1e9) {
            dd[v2] = dd[u] + 1;
            q.push(v2);
        }
    }
    return 1e9;
}

int main() {

    int n, x, y, ans = 0;
    cin >> n >> x >> y;
    ans = max(ans, bfs(1 << (n - 1), x, n));
    ans = max(ans, bfs(1 << (n - 1), y, n));
    cout << ans << endl;

    return 0;
}