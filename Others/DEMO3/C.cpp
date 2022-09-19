#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, m;
vector<vector<int>> c;

bool canGo(int x, int y) {
    if (x < 0 || x == n)
        return false;
    if (y < 0 || y == m)
        return false;
    if (c[x][y] == 0)
        return false;
    return true;
}

void dfs(int x, int y) {
    c[x][y] = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (canGo(x + i, y + j))
                dfs(x + i, y + j);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> n >> m;
    c = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            c[i][j] = (s[j] == 'W' ? 1 : 0);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 1) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;

    return 0;
}