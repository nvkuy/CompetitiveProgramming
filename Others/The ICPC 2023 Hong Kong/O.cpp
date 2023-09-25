#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> c(10);
    for (int i = 0; i < 10; i++) cin >> c[i];

    vector<vector<int>> a(10, vector<int> (10));
    vector<int> F(1000), G(1000);

    int id = 0;
    function<void(int, int)> dfs = [&] (int x, int y) {
        if (x < 0 || y < 0) return;
        if (x > 9 || y > 9) return;
        if (c[x][y] == '*') return;
        c[x][y] = '*';
        a[x][y] = id;
        F[id] += 1;
        dfs(x - 1, y); dfs(x + 1, y); dfs(x, y - 1); dfs(x, y + 1);
    };

    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (c[i][j] == '#') {
                ++id;
                dfs(i, j);
                cnt += 1;
            }
        }
    }

    G = F;

    int q;
    cin >> q;
    while (q--) {
        string mess;
        cin >> mess;
        if (mess == "SHOW") {
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for (int i = 1; i <= 100; i++) {
                if (F[i] == G[i] && F[i] > 0) {
                    cnt1 += 1;
                }
                if (F[i] > G[i] && F[i] > 0 && G[i] > 0) {
                    cnt2 += 1;
                }
                if (G[i] == 0 && F[i] > 0) {
                    cnt3 += 1;
                }
            }
            cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';
        }
        else {
            int x, y;
            cin >> x >> y; --x, --y;
            G[a[x][y]] -= 1;
            a[x][y] = 0;
        }
    }

    return 0;
}