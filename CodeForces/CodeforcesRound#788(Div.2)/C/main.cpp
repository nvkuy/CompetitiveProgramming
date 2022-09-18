#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> dd;

void dfs(int u) {
    dd[u] = 1;
    for (int i = 0; i < c[u].size(); i++)
        if (dd[c[u][i]] == 0)
            dfs(c[u][i]);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n), d(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        c.clear();
        c.resize(n + 1);
        dd.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            c[a[i]].push_back(b[i]);
            c[b[i]].push_back(a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (d[i] == 0)
                continue;
            dd[d[i]] = 1;
            if (a[i] == d[i])
                dfs(b[i]);
            else
                dfs(a[i]);
        }
        long long ans = 1, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (dd[a[i]] == 1 || a[i] == b[i])
                continue;
            ans = (ans * 2) % mod;
            dd[a[i]] = 1;
            dfs(b[i]);
        }
        //cout << "ANS: ";
        cout << ans << endl;
    }

    return 0;
}
