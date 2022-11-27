#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> dd;
int n, m;

int bfs(int st) {
    queue<int> q;
    dd.assign(n + 1, 0);
    q.push(st);
    dd[st] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : c[u]) {
            if (dd[v] == 0) {
                q.push(v);
                dd[v] = dd[u] + 1;
            }
        }
    }
    int max_val = *max_element(dd.begin(), dd.end());
    for (int i = 1; i <= n; i++)
        if (dd[i] == max_val)
            return i;
    return 0;
}

int main() {

    int u, v;
    cin >> n >> m;
    c.resize(n + 1);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    int tmp = bfs(1);
    bool cn = true;
    for (int i = 1; i <= n; i++) {
        if (dd[i] == 0)
            cn = false;
    }
    if (!cn) {
        cout << -1 << endl;
        return 0;
    }
    tmp = bfs(tmp);
    int max_len = dd[tmp] - 1;
    int ans = 0;
    while ((1 << ans) < max_len)
        ans++;
    cout << ans << endl;

    return 0;
}