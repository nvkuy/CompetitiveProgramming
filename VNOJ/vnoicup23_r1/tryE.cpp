#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> dd, com;
bool reachTop, reachBot, reachLeft, reachRight;
int n, m, l;
vector<pair<int, int>> point;

bool in_range(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first - l <= p2.first && p1.first + l >= p2.first && p1.second - l <= p2.second && p1.second + l >= p2.second)
        return true;
    return false;
}

void dfs(int u) {

    dd[u] = true;
    com.push_back(u);
    
    if (in_range(point[u], {point[u].first, 0}))
        reachBot = true;
    if (in_range(point[u], {point[u].first, n}))
        reachTop = true;
    if (in_range(point[u], {0, point[u].second}))
        reachLeft = true;
    if (in_range(point[u], {n, point[u].second}))
        reachRight = true;

    for (int v : c[u])
        if (!dd[v]) dfs(v);

}

int main() {

    cin >> n >> m >> l;
    assert(m <= 2000);
    point.resize(m);
    for (int i = 0; i < m; i++)
        cin >> point[i].first >> point[i].second;
    dd.assign(m, 0);
    c.resize(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (in_range(point[i], point[j]))
                c[i].push_back(j);
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++) {
        if (dd[i]) continue;
        com.clear();
        reachBot = reachTop = reachLeft = reachRight = false;
        dfs(i);
        if ((reachBot || reachRight) && (reachLeft || reachTop))
            for (auto u : com) ans.push_back(point[u]);
    }

    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << ' ' << p.second << endl;

    return 0;
}