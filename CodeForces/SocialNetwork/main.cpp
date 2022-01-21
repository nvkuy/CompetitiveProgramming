#include <bits/stdc++.h>

using namespace std;

int n, d, co;
bool dd[1001];
vector<vector<int>> c(1001);

void dfs(int u) {
    dd[u] = true;
    co++;
    for (int i = 0; i < c[u].size(); i++)
        if (!dd[c[u][i]])
            dfs(c[u][i]);
}

int main()
{

    int u, v, mc = 1;
    cin >> n >> d;
    while (d--) {
        memset(dd, false, sizeof(dd));
        cin >> u >> v;
        co = 0;
        c[u].push_back(v);
        c[v].push_back(u);
        dfs(u);
        mc = max(mc, co);
        cout << (mc - 1) << endl;
    }

    return 0;
}
