#include <bits/stdc++.h>
using namespace std;

struct color {
    int l, r, u, d;
    color() {
        l = r = u = d = -1;
    }
    void setCor(int x, int y) {
        if (l == -1 || l > x) l = x;
        if (r == -1 || r < x) r = x;
        if (u == -1 || u < y) u = y;
        if (d == -1 || d > y) d = y;
    }
};

int main() {

    if (fopen("art.in", "r")) {
        freopen("art.in", "r", stdin);
        freopen("art.out", "w", stdout);
    }

    int n, zr_cnt = 0;
    cin >> n;
    vector<color> cor(n * n + 1);
    vector<vector<int>> c(n, vector<int>(n, 0));
    vector<vector<int>> ps(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            cor[c[i][j]].setCor(i, j);
            zr_cnt += (c[i][j] == 0);
        }
    }
    if (zr_cnt == n * n) {
        cout << 0 << endl;
        return 0;
    }
    int color_cnt = 0;
    for (int i = 1; i <= n * n; i++) {
        if (cor[i].l < 0) continue;
        color_cnt++;
        ps[cor[i].l][cor[i].d]++;
        ps[cor[i].r + 1][cor[i].u + 1]++;
        ps[cor[i].r + 1][cor[i].d]--;
        ps[cor[i].l][cor[i].u + 1]--;
    }
    if (color_cnt == 1) {
        cout << n * n - 1 << endl;
        return 0;
    }
    vector<int> first(n * n + 1, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0)
                ps[i][j] += ps[i - 1][j];
            if (j > 0)
                ps[i][j] += ps[i][j - 1];
            if (i > 0 && j > 0)
                ps[i][j] -= ps[i - 1][j - 1];
            if (ps[i][j] > 1)
                first[c[i][j]] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n * n; i++)
        ans += first[i];
    cout << ans << endl;

    return 0;
}
