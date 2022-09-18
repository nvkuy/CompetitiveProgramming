#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
vector<bool> dd;

void dfs(int u) {
    dd[u] = true;
    for (int i = 0; i < c[u].size(); i++)
        if (!dd[c[u][i]])
            dfs(c[u][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, l, r;
    cin >> n >> q;
    c.resize(n + 1);
    dd.assign(n + 1, false);
    while (q--) {
        cin >> l >> r;
        c[l - 1].push_back(r);
        c[r].push_back(l - 1);
    }
    dfs(0);
    cout << (dd[n] ? "Yes" : "No");

    return 0;
}
