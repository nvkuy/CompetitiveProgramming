#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, rm;
vector<int> a;
vector<vector<int>> ans;

void dfs(int x, int y, int val) {
    ans[x][y] = val;
    rm--;
    if (rm > 0 && y > 0 && ans[x][y - 1] == 0)
        dfs(x, y - 1, val);
    if (rm > 0 && x + 1 < n && ans[x + 1][y] == 0)
        dfs(x + 1, y, val);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n), ans.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        rm = a[i];
        dfs(i, i, a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
