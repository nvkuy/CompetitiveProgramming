#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("multimoo.in", "r"))
        return;
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
}

int n, cc_size;
vector<vector<int>> c, dd;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool canGo(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= n) return false;
    return true;
}

void dfs(int x, int y, const pair<int, int> &color) {
    dd[x][y] = 1;
    cc_size++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!canGo(nx, ny)) continue;
        if (!dd[nx][ny] && (c[nx][ny] == color.first || c[nx][ny] == color.second))
            dfs(nx, ny, color);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    cin >> n;
    c.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    set<pair<int, int>> canGroup;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!canGo(x, y)) continue;
                if (c[i][j] != c[x][y])
                    canGroup.insert({min(c[i][j], c[x][y]), max(c[i][j], c[x][y])});
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    dd.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!dd[i][j]) {
                cc_size = 0;
                dfs(i, j, {c[i][j], c[i][j]});
                ans1 = max(ans1, cc_size);
            }
        }
    }
    vector<pair<int, int>> group;
    for (auto p : canGroup) group.push_back(p);
    for (auto p : group) {
        dd.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!dd[i][j] && (c[i][j] == p.first || c[i][j] == p.second)) {
                    cc_size = 0;
                    dfs(i, j, {p.first, p.second});
                    ans2 = max(ans2, cc_size);
                }
            }
        }
    }
    cout << ans1 << endl << ans2 << endl;

    return 0;
}
