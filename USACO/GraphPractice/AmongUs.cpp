#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> c;
vector<int> dd, com;

bool two_color(int u, int color) {
    dd[u] = color;
    com.push_back(u);
    bool iok = true;
    for (auto v : c[u]) {
        int next_color = color;
        if (v.second == 1) next_color = 3 - next_color;
        if (dd[v.first] == 0)
            iok &= two_color(v.first, next_color);
        else {
            if (next_color != dd[v.first]) {
                iok = false;
                break;
            }
        }
    }
    return iok;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        c.clear();
        c.resize(n + 1);
        dd.assign(n + 1, 0);
        while (m--) {
            int type, u, v;
            cin >> type >> u >> v;
            c[u].push_back({v, type});
            c[v].push_back({u, type});
        }

        bool iok = true;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!iok) break;
            if (dd[i] == 0) {
                com.clear();
                iok &= two_color(i, 1);
                int oneCnt = 0;
                for (int u : com) oneCnt += (dd[u] == 1);
                ans += max(oneCnt, (int)com.size() - oneCnt);
            }
        }

        if (!iok) ans = -1;
        cout << ans << endl;
    }

    return 0;
}