#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> dd;

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

    int n, ans;
    cin >> n;
    c.resize(n + 1);
    vector<vector<int>> wl(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        bool id = false;
        for (int j = 1; j <= n; j++) {
            cin >> wl[i][j];
            if (wl[i][j] == i)
                id = true;
            if (!id)
                c[wl[i][j]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = i;
        dd.assign(n + 1, false);
        dfs(i);
        for (int j = 1; wl[i][j] != i; j++) {
            if (dd[wl[i][j]]) {
                ans = wl[i][j];
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
