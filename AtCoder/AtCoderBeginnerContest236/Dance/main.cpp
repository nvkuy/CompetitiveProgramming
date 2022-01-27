#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
int ans = 0, n;

void dfs(int u, vector<int> b) {
    if (u == 2 * n) {
        int tans = 0;
        for (int i = 1; i <= 2 * n; i++)
            tans ^= a[i][b[i]];
        ans = max(ans, tans);
        return;
    }
    if (b[u] >= 0) {
        dfs(u + 1, b);
        return;
    }
    for (int i = u + 1; i <= 2 * n; i++) {
        if (b[i] == -1) {
            b[u] = i;
            b[i] = u;
            dfs(u + 1, b);
            b[u] = -1;
            b[i] = -1;
        }
    }
}

int main() {

    int ai;
    cin >> n;
    a.assign(2 * n + 1, vector<int>(2 * n + 1, 0));
    vector<int> b(2 * n + 1, -1);
    for (int i = 1; i < 2 * n; i++) {
        for (int j = i + 1; j <= 2 * n; j++) {
            cin >> ai;
            a[i][j] = ai;
            //a[j][i] = ai;
        }
    }
    dfs(1, b);
    cout << ans;

    return 0;
}
