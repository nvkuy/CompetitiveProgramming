#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
long long ans;
vector<long long> h, dd;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    dd[st] = 0LL;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < c[u].size(); i++) {
            long long tmp = h[u] - h[c[u][i]];
            if (h[u] <= h[c[u][i]])
                tmp *= 2LL;
            tmp += dd[u];
            if (dd[c[u][i]] < tmp) {
                dd[c[u][i]] = tmp;
                ans = max(ans, tmp);
                q.push(c[u][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    c.resize(n + 1);
    h.resize(n + 1);
    ans = -1e18 - 12;
    dd.assign(n + 1, ans);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    ans = 0LL;
    bfs(1);
    cout << ans;

    return 0;
}
