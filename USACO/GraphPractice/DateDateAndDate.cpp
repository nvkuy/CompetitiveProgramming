#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dd;
vector<vector<vector<pair<int, int>>>> c;
vector<int> com;
set<int> real_node;

void dfs(const pair<int, int> &u) {
    real_node.insert(u.first);
    com.push_back(u.second);
    dd[u.first][u.second] = 1;
    for (auto &v : c[u.first][u.second]) {
        if (!dd[v.first][v.second])
            dfs(v);
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    dd.assign(n + 1, vector<int>(2, 0));
    c.assign(n + 1, vector<vector<pair<int, int>>>(2));
    while (m--) {
        int u, v;
        cin >> u >> v;
        c[u][0].push_back({v, 1});
        c[u][1].push_back({v, 0});
        c[v][0].push_back({u, 1});
        c[v][1].push_back({u, 0});
    }
    long long ans = n;
    for (int i = 1; i <= n; i++) {
        if (dd[i][0] || dd[i][1]) continue;
        com.clear();
        real_node.clear();
        long long odd = 0, even = 0;
        dfs({i, 0});
        for (int p : com) {
            if (p % 2) odd++;
            else even++;
        }
        ans += (odd * (odd - 1LL));
        ans += (even * (even - 1LL));
        long long intersect = odd + even - real_node.size();
        ans -= (intersect * (intersect - 1LL));
    }
    cout << ans << endl;

    return 0;
}