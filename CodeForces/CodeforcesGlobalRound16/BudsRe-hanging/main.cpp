#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
int buds, leafs;
vector<bool> dd, ddb;
vector<int> leaves;

void dfs(int u) {
    dd[u] = true;
    bool ib = true;
    for (int i = 0; i < c[u].size(); i++) {
        if (dd[c[u][i]])
            continue;
        if (c[c[u][i]].size() == 1) {
            leaves.push_back(c[u][i]);
            leafs++;
        }
        if ((c[c[u][i]].size() > 1) || (c[u][i] == 1) || (u == 1))
            ib = false;
        if (c[c[u][i]].size() > 1)
            dfs(c[u][i]);
        else
            dd[c[u][i]] = true;
    }
    if (ib) {
        buds++;
        ddb[u] = true;
    }
    //cout << u << '|' << buds << '|' << leafs << endl;
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
        dd.assign(n + 1, false);
        ddb.assign(n + 1, false);
        leaves.clear();
        buds = leafs = 0;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(1);
        //cout << leafs << '|' << buds << endl;
        for (int i = 0; i < leaves.size(); i++) {
            if (!ddb[c[leaves[i]][0]]) {
                buds++;
                break;
            }
        }
        cout << leafs - buds + 1 << endl;
    }

    return 0;
}
