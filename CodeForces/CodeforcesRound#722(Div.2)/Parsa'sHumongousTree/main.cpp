#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<pair<int, int>> ranges;
vector<vector<int>> c;
vector<pair<long long, long long>> f;

void dfs(int u, int par) {
    for (int i = 0; i < c[u].size(); i++) {
        if (c[u][i] == par)
            continue;
        int v = c[u][i];
        dfs(v, u);
        f[u].first += max(f[v].first + llabs(ranges[v].first - ranges[u].first), f[v].second + llabs(ranges[v].second - ranges[u].first));
        f[u].second += max(f[v].first + llabs(ranges[v].first - ranges[u].second), f[v].second + llabs(ranges[v].second - ranges[u].second));
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, u, v, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ranges.resize(n + 1);
        c.clear();
        c.resize(n + 1);
        f.clear();
        f.assign(n + 1, make_pair(0, 0));
        for (int i = 1; i <= n; i++)
            cin >> ranges[i].first >> ranges[i].second;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        dfs(1, -1);
        /*
        for (int i = 1; i <= n; i++)
            cout << f[i].first << '|' << f[i].second << ' ';
        cout << endl;
        */
        cout << max(f[1].first, f[1].second) << endl;
    }

    return 0;
}
