#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> dd, readTurn;
int ans, n;

void dfs(int u) {
    if (ans > n)
        return;
    dd[u] = 1;
    int maxTime = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (dd[v] == 1) {
            //cout << "FAIL AT: " << u << ' ' << v << endl;
            ans = n + 1;
            return;
        }
        if (readTurn[v] > n)
            dfs(v);
        maxTime = max(maxTime, readTurn[v] + (v > u));
    }
    readTurn[u] = maxTime;
    dd[u] = 2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, k, u;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        dd.assign(n + 1, 0);
        readTurn.assign(n + 1, n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> k;
            while (k--) {
                cin >> u;
                c[i].push_back(u);
            }
        }
        ans = 1;
        for (int i = 1; i <= n; i++) {
            if (dd[i] != 0)
                continue;
            dfs(i);
            ans = max(ans, readTurn[i]);
        }
        /*
        cout << "TEST: " << endl;
        for (int i = 1; i <= n; i++)
            cout << readTurn[i] << ' ';
        cout << endl;
        */
        cout << (ans <= n ? ans : -1) << endl;
    }

    return 0;
}
