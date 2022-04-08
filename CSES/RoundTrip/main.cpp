#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<vector<int>> c;
vector<int> ans;
vector<int> par;

void dfs(int u) {
    for (int i = 0; i < c[u].size(); i++) {
        if (!ans.empty())
            return;
        if (par[c[u][i]] == -1) {
            par[c[u][i]] = u;
            dfs(c[u][i]);
        } else {
            if (c[u][i] == par[u])
                continue;
            else {
                int v = u;
                ans.push_back(c[u][i]);
                //cout << u << ':' << par[c[u][i]] << endl;
                while (v != par[c[u][i]]) {
                    //cout << v << '|' << par[v] << endl;
                    ans.push_back(v);
                    v = par[v];
                }
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, u, v;
    cin >> n >> m;
    par.assign(n + 1, -1);
    c.resize(n + 1);

    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (par[i] == -1) {
            par[i] = 0;
            dfs(i);
        }
        if (!ans.empty())
            break;
    }

    if (ans.empty()) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
