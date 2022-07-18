#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool iok;
vector<vector<int>> c;
vector<int> dd;

void dfs(int u, int color) {
    dd[u] = color;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (dd[v] < 0) {
            dfs(v, 1 - color);
            continue;
        }
        if (dd[u] == dd[v])
            iok = false;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        dd.assign(n + 1, 0);
        iok = true;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            c[a].push_back(b);
            c[b].push_back(a);
            dd[a]++, dd[b]++;
            if (dd[a] > 2 || dd[b] > 2)
                iok = false;
        }
        dd.assign(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (dd[i] < 0)
                dfs(i, 0);
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
