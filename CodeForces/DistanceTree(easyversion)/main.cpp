#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
vector<pair<int, int>> vd;

void dfs(int u, int r, int pa) {
    vd[u].first = r;
    for (int i = 0; i < c[u].size(); i++) {
        if (vd[c[u][i]].first == 0)
            dfs(c[u][i], r + 1, u);
    }
    vd[pa].second += vd[u].second;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        c.resize(n + 1);
        vd.assign(n + 1, make_pair(0, 1));
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(1, 1, 0);
        for (int x = 1; x <= n; x++) {
            int u = -1, md = 0;
            for (int j = 1; j <= n; j++) {
                if (vd[j].first == x + 1) {
                    if (u == -1) {
                        u = j;
                        md = vd[j].second;
                    } else {
                        if (vd[j].second > md) {
                            u = j;
                            md = vd[j].second;
                        }
                    }
                }
            }
            if (u == -1) {
                cout << x << ' ';
                continue;
            }
            int ans = vd[u].first + vd[u].second - 2;
            for (int j = 1; j <= n; j++) {
                if (vd[j].first == x + 1 && j != u)
                    ans = max(ans, vd[j].first + vd[j].second - 1);
            }
            cout << ans << ' ';
        }
        cout << endl;
    }

    return 0;
}
