#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
int buds, leaves, lr;
vector<int> type; //0 - not vis, 1 - visited, 2 - bud, 3 - leaf

void dfs(int u) {
    type[u] = 1;
    int ln = 0;
    for (int i = 0; i < c[u].size(); i++) {
        if (type[c[u][i]] == 0)
            dfs(c[u][i]);
        if (type[c[u][i]] == 3)
            ln++;
    }
    if (u == 1) {
        lr += ln;
        return;
    }
    if (ln > 0) {
        type[u] = 2;
        buds++;
    } else {
        type[u] = 3;
        leaves++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        type.assign(n + 1, 0);
        buds = leaves = lr = 0;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(1);
        /*
        for (int i = 1; i <= n; i++)
            cout << type[i] << ' ';
        cout << endl;
        cout << lr << '|' << leaves << '|' << buds << endl;
        */
        cout << leaves - (buds - (lr <= 0)) << endl;
    }

    return 0;
}
