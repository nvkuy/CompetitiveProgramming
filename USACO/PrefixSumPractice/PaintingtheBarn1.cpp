#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("paintbarn.in", "r")) {
        freopen("paintbarn.in", "r", stdin);
        freopen("paintbarn.out", "w", stdout);
    }

    int n, k;
    cin >> n >> k;
    vector<vector<int>> ps(1e3 + 5, vector<int>(1e3 + 5, 0));
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ps[x1][y1]++;
        ps[x2][y2]++;
        ps[x1][y2]--;
        ps[x2][y1]--;
    }
    int ans = 0;
    for (int i = 0; i <= 1e3; i++) {
        for (int j = 0; j <= 1e3; j++) {
            int t1 = 0, t2 = 0, t3 = 0;
            if (i > 0 && j > 0)
                t3 = ps[i - 1][j - 1];
            if (i > 0)
                t1 = ps[i - 1][j];
            if (j > 0)
                t2 = ps[i][j - 1];
            ps[i][j] += (t1 + t2 - t3);
            if (ps[i][j] == k) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}