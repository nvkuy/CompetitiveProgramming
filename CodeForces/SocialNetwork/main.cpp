#include <bits/stdc++.h>

using namespace std;

int n, d, co;
int dd[1001];
vector<vector<int>> c(1001);

void dfs(int u, int cco) {
    dd[u] = cco;
    co++;
    for (int i = 0; i < c[u].size(); i++)
        if (dd[c[u][i]] == 0)
            dfs(c[u][i], cco);
}

int main()
{

    int u, v, mc, cco, exd = 0;
    cin >> n >> d;
    while (d--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
        if ((dd[u] != 0) && (dd[u] == dd[v]))
            exd++;
        mc = 0;
        cco = 0;
        vector<int> mcs;
        memset(dd, 0, (n + 1) * sizeof *dd);
        for (int i = 1; i <= n; i++) {
            if (dd[i] != 0)
                continue;
            co = 0;
            cco++;
            dfs(i, cco);
            mcs.push_back(co);
        }
        sort(mcs.begin(), mcs.end(), greater<int>());
        mc = mcs[0];
        for (int i = 1; i <= min(exd, n - 1); i++)
            mc += mcs[i];
        cout << (mc - 1) << endl;
    }

    return 0;
}
