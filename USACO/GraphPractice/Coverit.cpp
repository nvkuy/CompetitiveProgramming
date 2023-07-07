#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int color, vector<vector<int>> &c, vector<int> &dd) {
    dd[u] = color;
    for (int v : c[u]) {
        if (dd[v] == 0)
            dfs(v, 3 - color, c, dd);
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n + 1);
        vector<int> dd(n + 1, 0);
        while (m--) {
            int u, v;
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        
        dfs(1, 1, c, dd);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += (dd[i] == 1);
        vector<int> ans;
        if (cnt <= (n / 2)) {
            for (int i = 1; i <= n; i++)
                if (dd[i] == 1) ans.push_back(i);
        } else {
            for (int i = 1; i <= n; i++)
                if (dd[i] != 1) ans.push_back(i);
        }

        cout << ans.size() << endl;
        for (int u : ans) cout << u << ' ';
        cout << endl;
    }

    return 0;
}